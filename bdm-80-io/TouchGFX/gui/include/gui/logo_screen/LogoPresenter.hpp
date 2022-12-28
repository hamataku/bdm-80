#ifndef LOGOPRESENTER_HPP
#define LOGOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LogoView;

class LogoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LogoPresenter(LogoView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~LogoPresenter() {};

private:
    LogoPresenter();

    LogoView& view;
};

#endif // LOGOPRESENTER_HPP
