#include "main_cycle.h"

#include <stdio.h>
#include <string.h>

#include "rom.h"
#include "com.h"
#include "gpio.h"
#include "tim.h"
#include "clock.h"

// #define DEBUG

uint32_t moder_output = 0;
uint32_t moder_input = 0;

uint16_t address = 0;
uint16_t address_prev = 0;

__attribute__((section(".ccmram"))) uint8_t data[65536];

#define WAIT()           \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop"); \
    asm volatile("nop");

void main_init(void)
{
    clock_init();
    // https://rappy.hatenablog.com/entry/2019/11/17/221651
    // https://controllerstech.com/stm32-gpio-input-configuration/
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = D0_Pin | D1_Pin | D2_Pin | D3_Pin | D4_Pin | D5_Pin | D6_Pin | D7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
    moder_output = DATA_PORT->MODER;

    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(DATA_PORT, &GPIO_InitStruct);
    moder_input = DATA_PORT->MODER;

    // memデータをccmramにコピー
    memcpy(data, mem_data, sizeof(mem_data));

    com_init();

    // CPU RESET
    main_reset();

    HAL_TIM_Base_Start_IT(&htim2);
    main_setFrequency(10);
}

void main_reset()
{
    printf("reset\n");
    HAL_TIM_Base_Stop_IT(&htim2);
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
    for (int i = 0; i < 10; i++) {
        // clock信号を3回以上入れる
        main_callback();
    }
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
    HAL_TIM_Base_Start_IT(&htim2);
}

void main_cycle(void)
{
    while (1) {
        com_update();
    }
}

void main_callback(void)
{
    CLK_GPIO_Port->ODR ^= CLK_Pin;
    WAIT();

    if ((GPIOA->IDR & (MREQ_Pin | WR_Pin)) == 0x00) {
        // write
        DATA_PORT->MODER = moder_input;
        address = ADDR_PORT->IDR;
        data[address] = (uint8_t)(DATA_PORT->IDR);

        if (address >= 0xfffc) {
            // LCD表示
            printf("%d%x\n", address - 0xfffc, data[address]);
        }

#ifdef DEBUG
        if (address != address_prev) {
            address_prev = address;
            printf("w: %x %x\n", address, (uint8_t)(DATA_PORT->IDR));
        }
#endif
    } else if ((GPIOA->IDR & (MREQ_Pin | RD_Pin | WR_Pin)) == WR_Pin) {
        // read
        DATA_PORT->MODER = moder_output;
        address = ADDR_PORT->IDR;
        DATA_PORT->ODR = data[address];

#ifdef DEBUG
        if (address != address_prev) {
            address_prev = address;
            printf("r: %x %x\n", address, data[address]);
        }
#endif
    } else {
        // disable
        DATA_PORT->MODER = moder_input;
    }
}

void main_setFrequency(uint32_t freq)
{
    freq = freq > 2000000 ? 2000000 : freq;
    freq = freq < 1 ? 1 : freq;
    uint32_t period = (uint32_t)(1000000 / freq);
    __HAL_TIM_SetAutoreload(&htim2, period);
    printf("freq %lu\n", freq);
}