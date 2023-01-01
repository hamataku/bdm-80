#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void TM1630_Init(void);
void TM1630_SetSeg1(uint16_t num);
void TM1630_SetSeg2(uint16_t num);


#ifdef __cplusplus
}
#endif