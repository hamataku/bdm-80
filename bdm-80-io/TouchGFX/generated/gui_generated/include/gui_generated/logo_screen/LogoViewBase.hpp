/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOGOVIEWBASE_HPP
#define LOGOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/logo_screen/LogoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class LogoViewBase : public touchgfx::View<LogoPresenter>
{
public:
    LogoViewBase();
    virtual ~LogoViewBase() {}
    virtual void setupScreen();
    virtual void handleTickEvent();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::TextureMapper textureMapper1;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea2;

private:

    /*
     * Delay Variable Declarations
     */
    static const uint16_t WAIT_DURATION = 120;
    uint16_t waitCounter;

};

#endif // LOGOVIEWBASE_HPP
