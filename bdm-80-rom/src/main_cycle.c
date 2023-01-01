#include "main_cycle.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "rom.h"
#include "gpio.h"
#include "stm32f4xx_it.h"
#include "usart.h"

#define PERIOD 5
#define PRINT

uint32_t moder_output = 0;
uint32_t moder_analog = 0;

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
    // https://rappy.hatenablog.com/entry/2019/11/17/221651
    // https://controllerstech.com/stm32-gpio-input-configuration/
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = D0_Pin | D1_Pin | D2_Pin | D3_Pin | D4_Pin | D5_Pin | D6_Pin | D7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    moder_output = GPIOC->MODER;

    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    moder_analog = GPIOC->MODER;

    // CPU RESET
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
}

void main_cycle(void)
{
    uint16_t address = 0;
    while (1) {
        CLK_GPIO_Port->ODR ^= CLK_Pin;

        GPIOC->MODER = moder_analog;

        address = GPIOB->IDR;
        GPIO_PinState rd = HAL_GPIO_ReadPin(RD_GPIO_Port, RD_Pin);
        GPIO_PinState wr = HAL_GPIO_ReadPin(WR_GPIO_Port, WR_Pin);
        GPIO_PinState mreq = HAL_GPIO_ReadPin(MREQ_GPIO_Port, MREQ_Pin);
        printf("address=%x, rd=%d, wr=%d, mreq=%d\n", address, rd, wr, mreq);

        HAL_Delay(PERIOD);
    }
}