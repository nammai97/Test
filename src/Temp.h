#pragma once
#include "Handler.h"
#include <string>

class Temp : public Handler
{
private:
    int mTemp;
    TextBlock2DSharedPtr mTextBlock; 
    //kb tro vao nhiet do
public:
    Temp(void);
    ~Temp(void);
    void onKeyInput(KzsInputKey Key);
    int getTempValue();
    void setTempValue(int tempValue);
    void setDefautValue();
    void increaseTempValue();
    void decreaseTempValue();
};

