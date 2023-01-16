#include "tm1630.h"
#include "gpio.h"
#include "main_cycle.h"

static uint8_t number[16] = {
    0b00011110, 0b00101000, 0b10110110, 0b10111100,
    0b01111000, 0b11011100, 0b11011110, 0b11101000,
    0b11111110, 0b11111100, 0b11111010, 0b01011110,
    0b11000110, 0b00111110, 0b11010110, 0b11010010};

static void TM1630_SetBrightness(uint8_t brightness);
static void TM1630_WriteByte(uint8_t data1, uint8_t data2);

uint16_t seg1_prev, seg2_prev;

void TM1630_Init(void)
{
    TM1630_SetBrightness(0x3);

    HAL_GPIO_WritePin(SEG_STB_GPIO_Port, SEG_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0x40, 0x40);
    HAL_GPIO_WritePin(SEG_STB_GPIO_Port, SEG_STB_Pin, GPIO_PIN_SET);

    seg1_prev = 0xffff;
    seg2_prev = 0xffff;
}

void TM1630_Update(void)
{
    uint16_t seg1_data = data[0xfffd] << 8 | data[0xfffc];
    uint16_t seg2_data = data[0xffff] << 8 | data[0xfffe];
    if (seg1_data == seg1_prev && seg2_data == seg2_prev) {
        return;
    }
    seg1_prev = seg1_data;
    seg2_prev = seg2_data;

    SEG_STB_GPIO_Port->BSRR = SEG_STB_Pin << 16;
    TM1630_WriteByte(0xc0, 0xc0);
    TM1630_WriteByte(number[seg1_data & 0x0f], number[seg2_data & 0x0f]);
    TM1630_WriteByte(0x00, 0x00);
    TM1630_WriteByte(number[(seg1_data >> 4) & 0x0f], number[(seg2_data >> 4) & 0x0f]);
    TM1630_WriteByte(0x00, 0x00);
    TM1630_WriteByte(number[(seg1_data >> 8) & 0x0f], number[(seg2_data >> 8) & 0x0f]);
    TM1630_WriteByte(0x00, 0x00);
    TM1630_WriteByte(number[(seg1_data >> 12) & 0x0f], number[(seg2_data >> 12) & 0x0f]);
    SEG_STB_GPIO_Port->BSRR = SEG_STB_Pin;
}

void TM1630_SetBrightness(uint8_t brightness)
{
    HAL_GPIO_WritePin(SEG_STB_GPIO_Port, SEG_STB_Pin, GPIO_PIN_RESET);
    TM1630_WriteByte(0x88 | brightness, 0x88 | brightness);
    HAL_GPIO_WritePin(SEG_STB_GPIO_Port, SEG_STB_Pin, GPIO_PIN_SET);
}

void TM1630_WriteByte(uint8_t data1, uint8_t data2)
{
    uint8_t i;
    for (i = 0; i < 8; i++) {
        SEG_CLK_GPIO_Port->BSRR = (uint32_t)SEG_CLK_Pin << 16;
        if (data1 & 0x01) {
            SEG_DIO1_GPIO_Port->BSRR = SEG_DIO1_Pin;
        } else {
            SEG_DIO1_GPIO_Port->BSRR = (uint32_t)SEG_DIO1_Pin << 16;
        }
        if (data2 & 0x01) {
            SEG_DIO2_GPIO_Port->BSRR = SEG_DIO2_Pin;
        } else {
            SEG_DIO2_GPIO_Port->BSRR = (uint32_t)SEG_DIO2_Pin << 16;
        }
        SEG_CLK_GPIO_Port->BSRR = SEG_CLK_Pin;
        data1 >>= 1;
        data2 >>= 1;
    }
    SEG_CLK_GPIO_Port->BSRR = SEG_CLK_Pin;
}