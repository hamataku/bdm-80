/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : STM32TouchController.cpp
 ******************************************************************************
 * This file is generated by TouchGFX Generator 4.20.0.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include "ili9341.h"
#include "xpt2046.h"
#include <stdio.h>
#include <cmath>

extern "C" {
static void ConvXPTtoILI(uint16_t* x, uint16_t* y)
{
    int16_t tx, ty;
    tx = (int16_t)(((int32_t)*x - XPT_XMIN) * GUI_WIDTH / XPT_WIDTH);
    tx = (tx < 0) ? 0 : tx;
    tx = (tx >= GUI_WIDTH) ? GUI_WIDTH - 1 : tx;
    ty = (int16_t)(((int32_t)*y - XPT_YMIN) * GUI_HEIGHT / XPT_HEIGHT);
    ty = (ty < 0) ? 0 : ty;
    ty = (ty >= GUI_HEIGHT) ? GUI_HEIGHT - 1 : ty;
    *x = tx;
    *y = ty;
}
}

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */
    static uint16_t prevx = GUI_WIDTH;
    static uint16_t prevy = GUI_HEIGHT;

    static int32_t x_prev = 0;
    static int32_t y_prev = 0;
    static int count = 0;
    static bool touch_flag = false;
    uint16_t intx = 0, inty = 0;

    if (count > 6) {
        XPT2046_Update(&intx, &inty);
        count = 0;
    } else {
        count++;
    }

    if (XPT2046_IsReasonable(intx, inty)) {
        ConvXPTtoILI(&intx, &inty);
        if (intx != prevx || inty != prevy) {
            x = GUI_WIDTH - (int32_t)intx;
            y = GUI_HEIGHT - (int32_t)inty;

            if (touch_flag) {
                touch_flag = false;
                if (std::abs(x - x_prev) > 10 || std::abs(y - y_prev) > 10) {
                    return false;
                }
            } else {
                touch_flag = true;
                x_prev = x;
                y_prev = y;
                return false;
            }
            prevx = intx;
            prevy = inty;
            return true;
        }
    }
    return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
