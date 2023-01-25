#include <gui/setting_screen/SettingView.hpp>
#include <gui/main_screen/MainView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <cmath>
#include <stdio.h>

int freq_list[10] = {1, 10, 20, 30, 60, 100, 1000, 10000, 100000, 1000000};
extern uint32_t _reboot_cookie;

SettingView::SettingView()
{
}

void SettingView::setupScreen()
{
    slider1.setValue(slider_value);
    slider_callback(slider_value);
    SettingViewBase::setupScreen();
}

void SettingView::tearDownScreen()
{
    SettingViewBase::tearDownScreen();
}

void SettingView::slider_callback(int value)
{
    slider_value = value;
    int freq = freq_list[value / 10];
    Unicode::snprintf(hzBuffer, HZ_SIZE, "%d", freq);
    hz.invalidate();
}

void SettingView::slider_release_callback(int value)
{
    int freq = freq_list[value / 10];
    printf("f%d\n", freq);
}

void SettingView::demo_callback()
{
    __disable_irq();
    _reboot_cookie = 0xDEADBEEF;
    HAL_NVIC_SystemReset();
}