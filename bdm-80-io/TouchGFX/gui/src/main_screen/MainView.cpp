#include <gui/main_screen/MainView.hpp>
#include <cstring>
#include <stdlib.h>

#ifndef SIMULATOR
#include "usart.h"
#endif

char receive[64];

MainView::MainView()
{
    memset(receive, 0, sizeof(receive));
}

void MainView::setupScreen()
{
    HAL_UART_Receive_DMA(&huart2, dma_rx_buffer, sizeof(dma_rx_buffer));
    for (int i = 0; i < 6; i++) {
        dma_exec();
        printf("v%x\n", address);
        HAL_Delay(100);
    }
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

#ifndef SIMULATOR
void MainView::update()
{
    dma_exec();

    if (data != data_current) {
        data_current = data;
        printf("D%x\n", data);
    }
    if (address != address_current) {
        address_current = address;
        printf("P%x\n", address);
    }
}

void MainView::dma_exec()
{
    int16_t uart_buffer_end_index = sizeof(dma_rx_buffer) - 1 - huart2.hdmarx->Instance->NDTR;
    if (uart_buffer_end_index < 0) {
        return;
    }

    int16_t end_index = uart_buffer_end_index;
    static int16_t last_end_index = 0;
    while (end_index >= 0) {
        if (dma_rx_buffer[end_index] == '\n') {
            break;
        }
        end_index--;
    }
    if (end_index == -1) {
        return;
    }
    if (end_index == last_end_index) {  // UARTを受信してなかったら抜ける
        return;
    }

    if (end_index > last_end_index) {
        memcpy(receive, dma_rx_buffer + last_end_index, end_index - last_end_index);
    } else {
        memcpy(receive, dma_rx_buffer + last_end_index, sizeof(dma_rx_buffer) - last_end_index);
        memcpy(receive + sizeof(dma_rx_buffer) - last_end_index, dma_rx_buffer, end_index);
    }

    switch (receive[1]) {
    case 'k': {
        address = (uint16_t)strtol((char*)&receive[2], NULL, 16);
    } break;
    case 'l': {
        data = (uint16_t)strtol((char*)&receive[2], NULL, 16);
    } break;
    default:
        break;
    }

    last_end_index = end_index;

    memset(receive, 0, sizeof(receive));
}
#endif