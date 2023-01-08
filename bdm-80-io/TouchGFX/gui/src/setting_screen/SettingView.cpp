#include <gui/setting_screen/SettingView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <cmath>
#include <stdio.h>

int freq_list[10] = {1, 10, 20, 30, 60, 100, 1000, 10000, 100000, 1000000};

SettingView::SettingView()
{
}

void SettingView::setupScreen()
{
    SettingViewBase::setupScreen();
}

void SettingView::tearDownScreen()
{
    SettingViewBase::tearDownScreen();
}

void SettingView::slider_callback(int value)
{
    freq = freq_list[value / 10];
    Unicode::snprintf(hzBuffer, HZ_SIZE, "%d", freq);
    hz.invalidate();
}

void SettingView::slider_release_callback(int value)
{
    printf("f%d\n", freq);
}

void SettingView::demo_callback()
{
}