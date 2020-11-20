#pragma once
#include <kanzi/kanzi.hpp>
#include <iostream>

using namespace kanzi;

class Handler
{
private:
    static ScreenSharedPtr mScreenNode;
    static Domain *mDomain;
    Button2DSharedPtr mAutoTestButton;
    ToggleButton2DSharedPtr mToggle;
public:
    Handler(void);
    virtual ~Handler(void);
    void autoTest();
    void appendMessageEvent();
    static void setScreenNode(ScreenSharedPtr ScreenNode);
    static ScreenSharedPtr getScreenNode();
    static void setDomain(Domain* mDomain);
    static Domain* getDomain();
};

