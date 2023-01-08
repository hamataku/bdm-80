#include "com.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "usart.h"
#include "stm32f4xx_it.h"
#include "main_cycle.h"
#include "tim.h"

#define MAX_SIZE 256

uint8_t receive[128];
volatile uint16_t place = 0;
uint8_t buf;
volatile bool received = false;

void com_init()
{
    memset(receive, 0, sizeof(receive));
    HAL_UART_Receive_IT(&huart2, &buf, 1);
}

void com_update()
{
    if (received) {
        __set_BASEPRI(3 << 4);
        switch (receive[0]) {
        case 'r':
            data[0x100] = 0x00;
            data[0x101] = 0x00;
            main_reset();
            break;
        case 'R':
            HAL_NVIC_SystemReset();
            break;
        case 'h':
            printf("halt\n");
            HAL_TIM_Base_Stop_IT(&htim2);
            HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET);
            break;
        case 's': {
            uint16_t p = (uint16_t)strtol((char*)&receive[1], NULL, 16);
            data[0x100] = (uint8_t)(p >> 8);
            data[0x101] = (uint8_t)(p & 0xff);

            printf("k%x\n", (uint16_t)(data[0xfffc]) << 8 | data[0xfffd]);
            HAL_Delay(10);
            printf("l%x\n", (uint16_t)(data[0xfffe]) << 8 | data[0xffff]);
            main_reset();
            HAL_TIM_Base_Start_IT(&htim2);
            break;
        }
        case 'w': {
            char buf[5] = {0, 0, 0, 0, 0};
            memcpy(buf, &receive[1], 4);
            uint16_t p = (uint16_t)strtol(buf, NULL, 16);
            memset(buf, 0, sizeof(buf));
            memcpy(buf, &receive[5], 2);
            uint8_t d = (uint8_t)strtol(buf, NULL, 16);
            data[p] = d;
            //printf("write %x %x\n", p, d);
            break;
        }
        case 'v': {
            uint16_t p = (uint16_t)strtol((char*)&receive[1], NULL, 16);
            if (p == 0) {
                printf("l00%02x\n", data[0x00]);
            } else {
                printf("l%02x%02x\n", data[p - 1], data[p]);
            }
            break;
        }
        case 'f': {
            uint32_t freq = (uint32_t)strtol((char*)&receive[1], NULL, 10);
            main_setFrequency(freq);
            break;
        }
        default:
            break;
        }
        received = false;
        memset(receive, 0, sizeof(receive));
        __set_BASEPRI(0);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart == &huart2 && READ_BIT(huart->Instance->CR1, USART_CR1_RXNEIE) != (USART_CR1_RXNEIE)) {
        HAL_UART_Receive_IT(&huart2, &buf, 1);
        if (buf == '\n' || buf == '\r') {
            received = true;
            place = 0;
        } else {
            receive[place] = buf;
            place++;
            received = false;
        }
    }
}