#ifndef TRANSFERVIEW_HPP
#define TRANSFERVIEW_HPP

#include <gui_generated/transfer_screen/TransferViewBase.hpp>
#include <gui/transfer_screen/TransferPresenter.hpp>

class TransferView : public TransferViewBase
{
public:
    TransferView();
    virtual ~TransferView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TRANSFERVIEW_HPP
