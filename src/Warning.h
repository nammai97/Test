#pragma once
#include "Handler.h"
class Warning :
    public Handler
{
private:
    bool mCurrentPopupStatus;
    Image2DSharedPtr mImage;
    float mRangeValue;
    TimerSubscriptionToken mTimerPopupCountdown;
public:
    Warning(void);
    ~Warning(void);
	void onKeyInput(KzsInputKey key);
    void createTimer();
	void removeTimer();
	bool getCurrentPopupStatus();
    void displayRangePopup();
    void closeRangePopup();
	void setDefautState();
    void setPropertyForNode(bool isShow);
    void onDataReceived(float valueInput);
    bool checkRangeValue();
};

