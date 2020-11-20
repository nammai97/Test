#pragma once
#include "Temp.h"
#include "Warning.h"
#include <kanzi/kanzi.hpp>

using namespace kanzi;
class SendDataMonitor
{
private:
    Temp* pTemp;
    Warning* pWarning;
public:
    SendDataMonitor(void);
    ~SendDataMonitor(void);
    void sendKeyInput(KzsInputKey mbutton);
    void initCluster();
    void sendDataValue(int dataType, float valueInput);
};

