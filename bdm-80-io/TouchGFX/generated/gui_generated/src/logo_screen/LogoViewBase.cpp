/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/logo_screen/LogoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LogoViewBase::LogoViewBase() :
    waitCounter(0)
{

    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(247, 247, 247));

    textureMapper1.setXY(160, 30);
    textureMapper1.setWidth(80);
    textureMapper1.setHeight(80);
    textureMapper1.setBitmapPosition(0.0f, 0.0f);
    textureMapper1.setScale(1.0f);
    textureMapper1.setCameraDistance(1000.0f);
    textureMapper1.setOrigo(0.0f, 0.0f, 1000.0f);
    textureMapper1.setCamera(40.0f, 40.0f);
    textureMapper1.setAngles(0.0f, 0.0f, 0.0f);
    textureMapper1.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    textArea1.setXY(78, 79);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(122, 122, 122));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4SKY));

    textArea2.setXY(105, 162);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(122, 122, 122));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZM3U));

    add(__background);
    add(box1);
    add(textureMapper1);
    add(textArea1);
    add(textArea2);
}

void LogoViewBase::setupScreen()
{

}

//Handles tick based events
void LogoViewBase::handleTickEvent()
{
    if(waitCounter > 0)
    {
        waitCounter--;
        if(waitCounter == 0)
        {
            //Interaction1
            //When wait completed change screen to Main
            //Go to Main with screen transition towards West
            application().gotoMainScreenWipeTransitionWest();
        }
    }

}

//Called when the screen transition ends
void LogoViewBase::afterTransition()
{
    //wait
    //When screen transition ends delay
    //Delay for 2000 ms (120 Ticks)
    waitCounter = WAIT_DURATION;
}
