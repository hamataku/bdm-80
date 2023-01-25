/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file   fatfs.c
 * @brief  Code for fatfs applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
#include "fatfs.h"

uint8_t retUSER;  /* Return value for USER */
char USERPath[4]; /* USER logical drive path */
FATFS USERFatFS;  /* File system object for USER logical drive */
FIL USERFile;     /* File object for USER */

/* USER CODE BEGIN Variables */
#include <stdio.h>
/* USER CODE END Variables */

void MX_FATFS_Init(void)
{
    /*## FatFS: Link the USER driver ###########################*/
    retUSER = FATFS_LinkDriver(&USER_Driver, USERPath);

    /* USER CODE BEGIN Init */
    uint8_t buffer[_MAX_SS]; /* a work buffer for the f_mkfs() */
    FRESULT fr;
    fr = f_mount(&USERFatFS, (TCHAR const*)USERPath, 0);
    if (fr != FR_OK)
        return;

    fr = f_mkfs((TCHAR const*)USERPath, FM_FAT, 0, buffer, sizeof(buffer));
    if (fr != FR_OK)
        return;

    fr = f_open(&USERFile, "README.TXT", FA_CREATE_ALWAYS | FA_WRITE);
    if (fr != FR_OK)
        return;

    // Write text
    f_puts("main.romファイルをペーストすることでBDM-80のROMに書き込みます。", &USERFile);
    fr = f_close(&USERFile);
    if (fr != FR_OK)
        return;

    /* additional user code for init */
    /* USER CODE END Init */
}

/**
 * @brief  Gets Time from RTC
 * @param  None
 * @retval Time in DWORD
 */
DWORD get_fattime(void)
{
    /* USER CODE BEGIN get_fattime */
    return 0;
    /* USER CODE END get_fattime */
}

/* USER CODE BEGIN Application */

/* USER CODE END Application */
