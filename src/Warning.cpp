#include "Warning.h"
#include <boost/chrono.hpp>

Warning::Warning(void)
{
    setDefautState();
}

void Warning::onKeyInput(KzsInputKey key){
    switch(key){
    case KZS_KEY_C:
        closeRangePopup();
    break;
    //case KZS_KEY_D:
    //    if(getCurrentPopupStatus() == false)
    //    {
    //        displayRangePopup();
    //    }
    //    break;
    }
}

void Warning::onDataReceived(float valueInput)
{
    mRangeValue = valueInput * 500;
    if(checkRangeValue())displayRangePopup();
}

bool Warning::checkRangeValue()
{
    return (mRangeValue < 20);
}

void Warning::setDefautState()
{
    mCurrentPopupStatus = false;
    mRangeValue = 0;
    if(getScreenNode() != nullptr) mImage = getScreenNode()->lookupNode<Image2D>("RootPage/Viewport 2D/2+4_gauge_1x");
    
}

void Warning::createTimer()
{
    removeTimer();
    mTimerPopupCountdown = addTimerHandler(getDomain()->getMessageDispatcher(), boost::chrono::milliseconds(3000), KZU_TIMER_MESSAGE_MODE_ONCE, bind(&Warning::closeRangePopup, this));
}

void Warning::removeTimer()
{
    if (mTimerPopupCountdown != nullptr)
    {
        removeTimerHandler(getDomain()->getMessageDispatcher(), mTimerPopupCountdown);
    }
}

bool Warning::getCurrentPopupStatus()
{
    return mCurrentPopupStatus;
}

void Warning::displayRangePopup()
{
    if(getCurrentPopupStatus() == false)
    {
        mCurrentPopupStatus = true;
        setPropertyForNode(mCurrentPopupStatus);
        createTimer();
    }
}

void Warning::closeRangePopup()
{
    if(getCurrentPopupStatus() == true)
    {
        mCurrentPopupStatus = false;
        setPropertyForNode(mCurrentPopupStatus);
        removeTimer();
    }
}

void Warning::setPropertyForNode(bool isShow)
{
    DynamicPropertyType<bool> isShowProperty("isShow");
    if(mImage != nullptr)mImage->setProperty(isShowProperty, isShow);
}

Warning::~Warning(void)
{
    removeTimer();
}


