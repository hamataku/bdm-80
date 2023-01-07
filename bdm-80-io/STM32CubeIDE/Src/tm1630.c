#include "tm1630.h"
#include "gpio.h"

static uint8_t number[16] = {
    0b00011110, 0b00101000, 0b10110110, 0b10111100,
    0b01111000, 0b11011100, 0b11011110, 0b11101000,
    0b11111110, 0b11111100, 0b11111010, 0b01011110,
    0b11000110, 0b00111110, 0b11010110, 0b11010010};

static void TM1630_SetBrightness(uint8_t brightness);
static void TM1630_WriteByteSeg1(uint8_t data);
static void TM1630_WriteByteSeg2(uint8_t data);

void TM1630_Init(void)
{
    TM1630_SetBrightness(0x3);

    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg1(0x40);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg2(0x40);
    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_SET);

    TM1630_SetSeg1(0);
    TM1630_SetSeg2(0);
}

void TM1630_SetBrightness(uint8_t brightness)
{
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg1(0x88 | brightness);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg2(0x88 | brightness);
    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_SET);
}

void TM1630_SetSeg1(uint16_t num)
{
    __disable_irq();
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg1(0xc0);
    TM1630_WriteByteSeg1(number[num & 0x0f]);
    TM1630_WriteByteSeg1(0x00);
    TM1630_WriteByteSeg1(number[(num >> 4) & 0x0f]);
    TM1630_WriteByteSeg1(0x00);
    TM1630_WriteByteSeg1(number[(num >> 8) & 0x0f]);
    TM1630_WriteByteSeg1(0x00);
    TM1630_WriteByteSeg1(number[(num >> 12) & 0x0f]);
    HAL_GPIO_WritePin(SEG1_STB_GPIO_Port, SEG1_STB_Pin, GPIO_PIN_SET);
    __enable_irq();
}

void TM1630_SetSeg2(uint16_t num)
{
    __disable_irq();
    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByteSeg2(0xc0);
    TM1630_WriteByteSeg2(number[num & 0x0f]);
    TM1630_WriteByteSeg2(0x00);
    TM1630_WriteByteSeg2(number[(num >> 4) & 0x0f]);
    TM1630_WriteByteSeg2(0x00);
    TM1630_WriteByteSeg2(number[(num >> 8) & 0x0f]);
    TM1630_WriteByteSeg2(0x00);
    TM1630_WriteByteSeg2(number[(num >> 12) & 0x0f]);
    HAL_GPIO_WritePin(SEG2_STB_GPIO_Port, SEG2_STB_Pin, GPIO_PIN_SET);
    __enable_irq();
}

void TM1630_WriteByteSeg1(uint8_t data)
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

void TM1630_WriteByteSeg2(uint8_t data)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        SEG2_CLK_GPIO_Port->BSRR = (uint32_t)SEG2_CLK_Pin << 16;
        if (data & 0x01) {
            HAL_GPIO_WritePin(SEG2_DIO_GPIO_Port, SEG2_DIO_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(SEG2_DIO_GPIO_Port, SEG2_DIO_Pin, GPIO_PIN_RESET);
        }
        SEG2_CLK_GPIO_Port->BSRR = SEG2_CLK_Pin;
        data >>= 1;
    }
    SEG2_CLK_GPIO_Port->BSRR = SEG2_CLK_Pin;
}