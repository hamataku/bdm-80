/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/setting_screen/SettingViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SettingViewBase::SettingViewBase() :
    waitCounter(0),
    buttonCallback(this, &SettingViewBase::buttonCallbackHandler),
    sliderValueChangedCallback(this, &SettingViewBase::sliderValueChangedCallbackHandler),
    sliderValueConfirmedCallback(this, &SettingViewBase::sliderValueConfirmedCallbackHandler)
{

    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(247, 247, 247));

    bf.setXY(224, 48);
    bf.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bf.setLabelText(touchgfx::TypedText(T___SINGLEUSE_VAYO));
    bf.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bf.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    be.setXY(176, 48);
    be.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    be.setLabelText(touchgfx::TypedText(T___SINGLEUSE_M3XV));
    be.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    be.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    bd.setXY(128, 48);
    bd.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bd.setLabelText(touchgfx::TypedText(T___SINGLEUSE_NNNQ));
    bd.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bd.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    bc.setXY(80, 48);
    bc.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bc.setLabelText(touchgfx::TypedText(T___SINGLEUSE_3ZAR));
    bc.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bc.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    bb.setXY(224, 96);
    bb.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bb.setLabelText(touchgfx::TypedText(T___SINGLEUSE_WDDI));
    bb.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bb.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    ba.setXY(176, 96);
    ba.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    ba.setLabelText(touchgfx::TypedText(T___SINGLEUSE_Z6M2));
    ba.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ba.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b9.setXY(128, 96);
    b9.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b9.setLabelText(touchgfx::TypedText(T___SINGLEUSE_7EEN));
    b9.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b9.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b8.setXY(80, 96);
    b8.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b8.setLabelText(touchgfx::TypedText(T___SINGLEUSE_T7YJ));
    b8.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b8.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b7.setXY(224, 144);
    b7.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b7.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9ZH9));
    b7.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b7.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b6.setXY(176, 144);
    b6.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b6.setLabelText(touchgfx::TypedText(T___SINGLEUSE_GDIY));
    b6.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b6.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b5.setXY(128, 144);
    b5.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b5.setLabelText(touchgfx::TypedText(T___SINGLEUSE_HAF5));
    b5.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b5.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b4.setXY(80, 144);
    b4.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b4.setLabelText(touchgfx::TypedText(T___SINGLEUSE_B5HO));
    b4.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b4.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b3.setXY(224, 192);
    b3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b3.setLabelText(touchgfx::TypedText(T___SINGLEUSE_3LFJ));
    b3.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b3.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b2.setXY(176, 192);
    b2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b2.setLabelText(touchgfx::TypedText(T___SINGLEUSE_M2GY));
    b2.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b2.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b1.setXY(128, 192);
    b1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_Y6RH));
    b1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    b0.setXY(80, 192);
    b0.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b0.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YKCP));
    b0.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b0.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1.setXY(80, 0);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YEQD));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1.setXY(128, 0);
    buttonWithLabel1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_SBLS));
    buttonWithLabel1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1.setXY(176, 0);
    buttonWithLabel1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_5OAY));
    buttonWithLabel1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1.setXY(224, 0);
    buttonWithLabel1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_0Q0B));
    buttonWithLabel1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1.setXY(272, 0);
    buttonWithLabel1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_60TH));
    buttonWithLabel1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1.setXY(272, 48);
    buttonWithLabel1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_1P6H));
    buttonWithLabel1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1.setXY(272, 96);
    buttonWithLabel1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_SSKK));
    buttonWithLabel1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1_1.setXY(272, 144);
    buttonWithLabel1_1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_WA97));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1_1_1.setXY(272, 192);
    buttonWithLabel1_1_1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_8ZG6));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    button1.setXY(13, 201);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ICONS_SETTINGS_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_SETTINGS_32_ID));

    toggleButton1_1.setXY(14, 152);
    toggleButton1_1.setBitmaps(touchgfx::Bitmap(BITMAP_TOGGLE_ON_ID), touchgfx::Bitmap(BITMAP_TOGGLE_OFF_ID));

    textArea1.setXY(30, 122);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OD52));

    box2.setPosition(0, 0, 320, 240);
    box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    box2.setAlpha(110);

    textureMapper1.setXY(0, 0);
    textureMapper1.setBitmap(touchgfx::Bitmap(BITMAP_POPUP_ID));
    textureMapper1.setWidth(320);
    textureMapper1.setHeight(240);
    textureMapper1.setBitmapPosition(36.0f, 36.0f);
    textureMapper1.setScale(0.0f);
    textureMapper1.setCameraDistance(1000.0f);
    textureMapper1.setOrigo(160.0f, 120.0f, 1000.0f);
    textureMapper1.setCamera(160.0f, 120.0f);
    textureMapper1.setAngles(0.0f, 0.0f, 0.0f);
    textureMapper1.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    container1.setPosition(0, 0, 320, 240);
    container1.setVisible(false);

    back.setXY(29, 34);
    back.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_REMOVE_32_ID));
    back.setAction(buttonCallback);
    container1.add(back);

    freq.setXY(121, 122);
    freq.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    freq.setLinespacing(0);
    freq.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AWO7));
    container1.add(freq);

    slider1.setXY(36, 144);
    slider1.setBitmaps(touchgfx::Bitmap(BITMAP_VOLUME_BAR_ID), touchgfx::Bitmap(BITMAP_VOLUME_BAR_ID), touchgfx::Bitmap(BITMAP_BLUE_RADIO_BUTTONS_RADIO_ROUND_BUTTON_NORMAL_ID));
    slider1.setupHorizontalSlider(24, 19, 0, 0, 205);
    slider1.setValueRange(0, 99);
    slider1.setValue(0);
    slider1.setNewValueCallback(sliderValueChangedCallback);
    slider1.setStopValueCallback(sliderValueConfirmedCallback);
    container1.add(slider1);

    demo.setXY(137, 52);
    demo.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    demo.setLinespacing(0);
    demo.setTypedText(touchgfx::TypedText(T___SINGLEUSE_14YJ));
    container1.add(demo);

    hz.setPosition(80, 177, 160, 31);
    hz.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    hz.setLinespacing(0);
    Unicode::snprintf(hzBuffer, HZ_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_GC5Q).getText());
    hz.setWildcard(hzBuffer);
    hz.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1S7H));
    container1.add(hz);

    button_demo.setXY(137, 83);
    button_demo.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ICONS_FOLDER_48_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_FOLDER_48_ID));
    button_demo.setAction(buttonCallback);
    container1.add(button_demo);

    add(__background);
    add(box1);
    add(bf);
    add(be);
    add(bd);
    add(bc);
    add(bb);
    add(ba);
    add(b9);
    add(b8);
    add(b7);
    add(b6);
    add(b5);
    add(b4);
    add(b3);
    add(b2);
    add(b1);
    add(b0);
    add(buttonWithLabel1);
    add(buttonWithLabel1_1);
    add(buttonWithLabel1_1_1);
    add(buttonWithLabel1_1_1_1);
    add(buttonWithLabel1_1_1_1_1);
    add(buttonWithLabel1_1_1_1_1_1);
    add(buttonWithLabel1_1_1_1_1_1_1);
    add(buttonWithLabel1_1_1_1_1_1_1_1);
    add(buttonWithLabel1_1_1_1_1_1_1_1_1);
    add(button1);
    add(toggleButton1_1);
    add(textArea1);
    add(box2);
    add(textureMapper1);
    add(container1);
}

void SettingViewBase::setupScreen()
{

    //resize
    //When screen transition begins scale textureMapper1
    //Scale textureMapper1
    textureMapper1.setupAnimation(touchgfx::AnimationTextureMapper::SCALE, 1.100f, 9, 0, touchgfx::EasingEquations::linearEaseIn);
    textureMapper1.startAnimation();

    //wait
    //When screen transition begins delay
    //Delay for 150 ms (9 Ticks)
    waitCounter = WAIT_DURATION;

}

//Handles tick based events
void SettingViewBase::handleTickEvent()
{
    if(waitCounter > 0)
    {
        waitCounter--;
        if(waitCounter == 0)
        {
            //container
            //When wait completed show container1
            //Show container1
            container1.setVisible(true);
            container1.invalidate();
        }
    }

}

void SettingViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &back)
    {
        //back
        //When back clicked change screen to Main
        //Go to Main with no screen transition
        application().gotoMainScreenNoTransition();
    }
    else if (&src == &button_demo)
    {
        //demo
        //When button_demo clicked call virtual function
        //Call demo_callback
        demo_callback();
    }
}

void SettingViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider1)
    {
        //slider
        //When slider1 value changed call virtual function
        //Call slider_callback
        slider_callback(value);
    }
}

void SettingViewBase::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider1)
    {
        //slider_release
        //When slider1 value confirmed call virtual function
        //Call slider_release_callback
        slider_release_callback(value);
    }
}
