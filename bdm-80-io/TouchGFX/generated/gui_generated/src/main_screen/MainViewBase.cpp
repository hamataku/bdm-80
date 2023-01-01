/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MainViewBase::MainViewBase() :
    buttonCallback(this, &MainViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(227, 227, 227));

    bf.setXY(224, 48);
    bf.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bf.setLabelText(touchgfx::TypedText(T___SINGLEUSE_J1C9));
    bf.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bf.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bf.setAction(buttonCallback);

    be.setXY(176, 48);
    be.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    be.setLabelText(touchgfx::TypedText(T___SINGLEUSE_IJGT));
    be.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    be.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    be.setAction(buttonCallback);

    bd.setXY(128, 48);
    bd.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bd.setLabelText(touchgfx::TypedText(T___SINGLEUSE_MEPQ));
    bd.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bd.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bd.setAction(buttonCallback);

    bc.setXY(80, 48);
    bc.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bc.setLabelText(touchgfx::TypedText(T___SINGLEUSE_9ZC7));
    bc.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bc.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bc.setAction(buttonCallback);

    bb.setXY(224, 96);
    bb.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    bb.setLabelText(touchgfx::TypedText(T___SINGLEUSE_Z4C9));
    bb.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bb.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bb.setAction(buttonCallback);

    ba.setXY(176, 96);
    ba.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    ba.setLabelText(touchgfx::TypedText(T___SINGLEUSE_VDEA));
    ba.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ba.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ba.setAction(buttonCallback);

    b9.setXY(128, 96);
    b9.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b9.setLabelText(touchgfx::TypedText(T___SINGLEUSE_C9AB));
    b9.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b9.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b9.setAction(buttonCallback);

    b8.setXY(80, 96);
    b8.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b8.setLabelText(touchgfx::TypedText(T___SINGLEUSE_0F7E));
    b8.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b8.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b8.setAction(buttonCallback);

    b7.setXY(224, 144);
    b7.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b7.setLabelText(touchgfx::TypedText(T___SINGLEUSE_HUC5));
    b7.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b7.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b7.setAction(buttonCallback);

    b6.setXY(176, 144);
    b6.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b6.setLabelText(touchgfx::TypedText(T___SINGLEUSE_WE88));
    b6.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b6.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b6.setAction(buttonCallback);

    b5.setXY(128, 144);
    b5.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b5.setLabelText(touchgfx::TypedText(T___SINGLEUSE_D5SU));
    b5.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b5.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b5.setAction(buttonCallback);

    b4.setXY(80, 144);
    b4.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b4.setLabelText(touchgfx::TypedText(T___SINGLEUSE_94BI));
    b4.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b4.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b4.setAction(buttonCallback);

    b3.setXY(224, 192);
    b3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b3.setLabelText(touchgfx::TypedText(T___SINGLEUSE_YG6E));
    b3.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b3.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b3.setAction(buttonCallback);

    b2.setXY(176, 192);
    b2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_PRESSED_ID));
    b2.setLabelText(touchgfx::TypedText(T___SINGLEUSE_BLF7));
    b2.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b2.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b2.setAction(buttonCallback);

    b1.setXY(128, 192);
    b1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_BLDW));
    b1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b1.setAction(buttonCallback);

    b0.setXY(80, 192);
    b0.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ID), touchgfx::Bitmap(BITMAP_BLUE_ID));
    b0.setLabelText(touchgfx::TypedText(T___SINGLEUSE_26U0));
    b0.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b0.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    b0.setAction(buttonCallback);

    buttonWithLabel1.setXY(80, 0);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_4AKZ));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1.setXY(128, 0);
    buttonWithLabel1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_F7SQ));
    buttonWithLabel1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1.setXY(176, 0);
    buttonWithLabel1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_8CQT));
    buttonWithLabel1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1.setXY(224, 0);
    buttonWithLabel1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_61B9));
    buttonWithLabel1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1.setXY(272, 0);
    buttonWithLabel1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_80VW));
    buttonWithLabel1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1.setXY(272, 48);
    buttonWithLabel1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_UD6S));
    buttonWithLabel1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1.setXY(272, 96);
    buttonWithLabel1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_TT4Y));
    buttonWithLabel1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1_1.setXY(272, 144);
    buttonWithLabel1_1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_FCNM));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    buttonWithLabel1_1_1_1_1_1_1_1_1.setXY(272, 192);
    buttonWithLabel1_1_1_1_1_1_1_1_1.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE_ID), touchgfx::Bitmap(BITMAP_ORANGE_PRESSED_ID));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_AMXG));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1_1_1_1_1_1_1_1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));

    button1.setXY(13, 201);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_ICONS_SETTINGS_32_ID), touchgfx::Bitmap(BITMAP_BLUE_ICONS_SETTINGS_32_ID));

    toggleButton1_1.setXY(14, 152);
    toggleButton1_1.setBitmaps(touchgfx::Bitmap(BITMAP_TOGGLE_ON_ID), touchgfx::Bitmap(BITMAP_TOGGLE_OFF_ID));

    textArea1.setXY(30, 122);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4LNC));

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
}

void MainViewBase::setupScreen()
{

}

void MainViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &bf)
    {
        //bf
        //When bf clicked call virtual function
        //Call bf_callback
        bf_callback();
    }
    else if (&src == &be)
    {
        //be
        //When be clicked call virtual function
        //Call be_callback
        be_callback();
    }
    else if (&src == &bd)
    {
        //bd
        //When bd clicked call virtual function
        //Call bd_callback
        bd_callback();
    }
    else if (&src == &bc)
    {
        //bc
        //When bc clicked call virtual function
        //Call bc_callback
        bc_callback();
    }
    else if (&src == &bb)
    {
        //bb
        //When bb clicked call virtual function
        //Call bb_callback
        bb_callback();
    }
    else if (&src == &ba)
    {
        //ba
        //When ba clicked call virtual function
        //Call ba_callback
        ba_callback();
    }
    else if (&src == &b9)
    {
        //b9
        //When b9 clicked call virtual function
        //Call b9_callback
        b9_callback();
    }
    else if (&src == &b8)
    {
        //b8
        //When b8 clicked call virtual function
        //Call b8_callback
        b8_callback();
    }
    else if (&src == &b7)
    {
        //b7
        //When b7 clicked call virtual function
        //Call b7_callback
        b7_callback();
    }
    else if (&src == &b6)
    {
        //b6
        //When b6 clicked call virtual function
        //Call b6_callback
        b6_callback();
    }
    else if (&src == &b5)
    {
        //b5
        //When b5 clicked call virtual function
        //Call b5_callback
        b5_callback();
    }
    else if (&src == &b4)
    {
        //b4
        //When b4 clicked call virtual function
        //Call b4_callback
        b4_callback();
    }
    else if (&src == &b3)
    {
        //b3
        //When b3 clicked call virtual function
        //Call b3_callback
        b3_callback();
    }
    else if (&src == &b2)
    {
        //b2
        //When b2 clicked call virtual function
        //Call b2_callback
        b2_callback();
    }
    else if (&src == &b1)
    {
        //b1
        //When b1 clicked call virtual function
        //Call b1_callback
        b1_callback();
    }
    else if (&src == &b0)
    {
        //b0
        //When b0 clicked call virtual function
        //Call b0_callback
        b0_callback();
    }
}