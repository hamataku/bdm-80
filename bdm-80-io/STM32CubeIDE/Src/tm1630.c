#include "tm1630.h"
#include "gpio.h"

static uint8_t number[16] = {
    0b00011110, 0b00101000, 0b10110110, 0b10111100,
    0b01111000, 0b11011100, 0b11011110, 0b11101000,
    0b11111110, 0b11111100, 0b11111010, 0b01011110,
    0b11000110, 0b00111110, 0b11010110, 0b11010010};

static void TM1630_SetBrightness(uint8_t brightness);
static void TM1630_WriteByte(uint8_t data);
static void TM1630_SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4);

void TM1630_Init(void)
{
    TM1630_SetBrightness(0x3);
    TM1630_SetNumber(0);
}

void TM1630_SetBrightness(uint8_t brightness)
{
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0x88 | brightness);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);
}

void TM1630_SetNumber(uint16_t num)
{
    uint8_t digit1, digit2, digit3, digit4;
    digit1 = number[num & 0x0f];
    digit2 = number[(num >> 4) & 0x0f];
    digit3 = number[(num >> 8) & 0x0f];
    digit4 = number[(num >> 12) & 0x0f];
    TM1630_SetDisplay(digit1, digit2, digit3, digit4);
}

void TM1630_SetDisplay(uint8_t digit1, uint8_t digit2, uint8_t digit3, uint8_t digit4)
{
    __disable_irq();
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0x44);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0xc0);
    TM1630_WriteByte(digit1);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0xc2);
    TM1630_WriteByte(digit2);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0xc4);
    TM1630_WriteByte(digit3);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0xc6);
    TM1630_WriteByte(digit4);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);
    __enable_irq();
}

void TM1630_WriteByte(uint8_t data)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        SEG1_CLK_GPIO_Port->BSRR = (uint32_t)SEG1_CLK_Pin << 16;
        if (data & 0x01) {
            HAL_GPIO_WritePin(SEG1_DIO_GPIO_Port, SEG1_DIO_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(SEG1_DIO_GPIO_Port, SEG1_DIO_Pin, GPIO_PIN_RESET);
        }
        SEG1_CLK_GPIO_Port->BSRR = SEG1_CLK_Pin;
        data >>= 1;
    }
    SEG1_CLK_GPIO_Port->BSRR = SEG1_CLK_Pin;
}