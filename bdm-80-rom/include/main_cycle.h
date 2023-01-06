#pragma once

#include <stdint.h>

#define ADDR_PORT GPIOB
#define DATA_PORT GPIOC

extern uint8_t data[65536];

void main_reset(void);
void main_init(void);
void main_cycle(void);
void main_callback(void);
void main_setFrequency(uint32_t freq);