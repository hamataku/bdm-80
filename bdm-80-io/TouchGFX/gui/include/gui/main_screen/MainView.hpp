#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include "tm1630.h"

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    uint16_t counter = 0;
    void b0_callback() override
    {
        counter = counter << 4;
        TM1630_SetSeg1(counter);
    }
    void b1_callback() override
    {
        counter = (counter << 4) + 1;
        TM1630_SetSeg1(counter);
        TM1630_SetSeg2(counter);
    }
    void b2_callback() override
    {
        counter = (counter << 4) + 2;
        TM1630_SetSeg1(counter);
    }
    void b3_callback() override
    {
        counter = (counter << 4) + 3;
        TM1630_SetSeg1(counter);
    }
    void b4_callback() override
    {
        counter = (counter << 4) + 4;
        TM1630_SetSeg1(counter);
    }
    void b5_callback() override
    {
        counter = (counter << 4) + 5;
        TM1630_SetSeg1(counter);
    }
    void b6_callback() override
    {
        counter = (counter << 4) + 6;
        TM1630_SetSeg1(counter);
    }
    void b7_callback() override
    {
        counter = (counter << 4) + 7;
        TM1630_SetSeg1(counter);
    }
    void b8_callback() override
    {
        counter = (counter << 4) + 8;
        TM1630_SetSeg1(counter);
    }
    void b9_callback() override
    {
        counter = (counter << 4) + 9;
        TM1630_SetSeg1(counter);
    }
    void ba_callback() override
    {
        counter = (counter << 4) + 10;
        TM1630_SetSeg1(counter);
    }
    void bb_callback() override
    {
        counter = (counter << 4) + 11;
        TM1630_SetSeg1(counter);
    }
    void bc_callback() override
    {
        counter = (counter << 4) + 12;
        TM1630_SetSeg1(counter);
    }
    void bd_callback() override
    {
        counter = (counter << 4) + 13;
        TM1630_SetSeg1(counter);
    }
    void be_callback() override
    {
        counter = (counter << 4) + 14;
        TM1630_SetSeg1(counter);
    }
    void bf_callback() override
    {
        counter = (counter << 4) + 15;
        TM1630_SetSeg1(counter);
    }
};

#endif  // MAINVIEW_HPP
