#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <stdio.h>

#ifndef SIMULATOR
#include "tm1630.h"
#endif

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    static uint16_t data;
    static uint16_t data_current;
    static uint16_t address;
    static uint16_t address_current;
    static uint8_t dma_rx_buffer[64];
#ifndef SIMULATOR
    void dma_exec();
    void update() override;

    void b0_callback() override
    {
        data = data << 4;
    }
    void b1_callback() override
    {
        data = (data << 4) + 1;
    }
    void b2_callback() override
    {
        data = (data << 4) + 2;
    }
    void b3_callback() override
    {
        data = (data << 4) + 3;
    }
    void b4_callback() override
    {
        data = (data << 4) + 4;
    }
    void b5_callback() override
    {
        data = (data << 4) + 5;
    }
    void b6_callback() override
    {
        data = (data << 4) + 6;
    }
    void b7_callback() override
    {
        data = (data << 4) + 7;
    }
    void b8_callback() override
    {
        data = (data << 4) + 8;
    }
    void b9_callback() override
    {
        data = (data << 4) + 9;
    }
    void ba_callback() override
    {
        data = (data << 4) + 10;
    }
    void bb_callback() override
    {
        data = (data << 4) + 11;
    }
    void bc_callback() override
    {
        data = (data << 4) + 12;
    }
    void bd_callback() override
    {
        data = (data << 4) + 13;
    }
    void be_callback() override
    {
        data = (data << 4) + 14;
    }
    void bf_callback() override
    {
        data = (data << 4) + 15;
    }
    void adrs_callback() override
    {
        address = data;
        printf("v%x\n", address);
    }
    void read_incr_callback() override
    {
        address++;
        printf("v%x\n", address);
    }
    void read_decr_callback() override
    {
        address--;
        printf("v%x\n", address);
    }
    void write_incr_callback() override
    {
        printf("w%04x%x\n", address, data & 0xff);
        address++;
        printf("v%x\n", address);
    }
    void run_callback() override
    {
        printf("s%x\n", address);
    }
    void reset_callback() override
    {
        printf("r\n");
        address = 0;
        for (int i = 0; i < 6; i++) {
            dma_exec();
            printf("v0\n");
            HAL_Delay(100);
        }
    }
#endif
};

inline uint16_t MainView::data = 0;
inline uint16_t MainView::data_current = 0;
inline uint16_t MainView::address = 0;
inline uint16_t MainView::address_current = 0;
inline uint8_t MainView::dma_rx_buffer[64];
#endif  // MAINVIEW_HPP
