#include <kanzi/kanzi.hpp>
#include "SendDataMonitor.h"
#include "Handler.h"
#include "Entry.h"

using namespace kanzi;

class PracticeVer2 : public ExampleApplication
{
private: 
    SendDataMonitor* pSendDataMonitor;
    Slider2DSharedPtr rangeSlide;

public:
    void sendDataInput(int typeData, float value)
    {
        if(pSendDataMonitor != nullptr)pSendDataMonitor->sendDataValue(typeData, value);
    }
    void onCallbackValueChanged(Slider2DConceptImplType::ValueChangedMessageArguments&)
    {
        float sliderValue = rangeSlide->getValue();
        sendDataInput(RANGE_VALUE, sliderValue);
    }

    void initScreen()
    {
        pSendDataMonitor = new SendDataMonitor();
        rangeSlide = getScreen()->lookupNode<Slider2D>("RootPage/Viewport 2D/Range");
        rangeSlide->addMessageHandler(Slider2D::ValueChangedMessage, bind(&PracticeVer2::onCallbackValueChanged, this, placeholders::_1));
    }

    virtual void onConfigure(ApplicationProperties& configuration) KZ_OVERRIDE
    {
        configuration.binaryName = "Practice_ver2.kzb.cfg";
    }
    virtual void onKeyInputEvent(const KzsInputEventKey* inputData) KZ_OVERRIDE
    {
        KzsInputKey button = kzsInputEventKeyGetButton(inputData);
        if (button != KZS_KEY_ESC){
            pSendDataMonitor->sendKeyInput(button);
        }else
        {
            quit();
        }
    }

    virtual void onProjectLoaded() KZ_OVERRIDE
    {
       Handler::setScreenNode(getScreen());
       Handler::setDomain(getDomain());
       initScreen();
    }
};

Application* createApplication()
{
    return new PracticeVer2;
}
