#ifndef SETTINGVIEW_HPP
#define SETTINGVIEW_HPP

#include <gui_generated/setting_screen/SettingViewBase.hpp>
#include <gui/setting_screen/SettingPresenter.hpp>

class SettingView : public SettingViewBase
{
public:
    SettingView();
    virtual ~SettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

protected:
    void slider_callback(int value) override;
    void slider_release_callback(int value) override;
    void demo_callback() override;
    int freq = 1;
};

#endif  // SETTINGVIEW_HPP
