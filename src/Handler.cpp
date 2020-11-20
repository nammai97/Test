#include "Handler.h"

ScreenSharedPtr Handler::mScreenNode;
Domain* Handler::mDomain;

Handler::Handler()
{
    appendMessageEvent();
}

void Handler::appendMessageEvent()
{
    if(mScreenNode != nullptr)mToggle = mScreenNode->lookupNode<ToggleButton2D>("RootPage/Viewport 2D/CheckBox/Toggle Button 2D");
	if(mToggle != nullptr)mToggle->addMessageHandler(ButtonConcept::ToggleStateChangedMessage, bind(&Handler::autoTest, this));
}

void Handler::autoTest()
{
    int sliderValue = mToggle->getToggleState();
}

Handler::~Handler(void)
{
}

void Handler::setScreenNode(ScreenSharedPtr ScreenNode)
{
    mScreenNode = ScreenNode;
}

ScreenSharedPtr Handler::getScreenNode()
{
    return mScreenNode;
}

void Handler::setDomain(Domain* Domain)
{
    mDomain = Domain;
}

Domain* Handler::getDomain()
{
    return mDomain;
}