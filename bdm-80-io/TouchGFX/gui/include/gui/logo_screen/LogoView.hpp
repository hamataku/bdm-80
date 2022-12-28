#ifndef LOGOVIEW_HPP
#define LOGOVIEW_HPP

#include <gui_generated/logo_screen/LogoViewBase.hpp>
#include <gui/logo_screen/LogoPresenter.hpp>

class LogoView : public LogoViewBase
{
public:
    LogoView();
    virtual ~LogoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOGOVIEW_HPP
