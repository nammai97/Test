#include "SendDataMonitor.h"
#include "Entry.h"

SendDataMonitor::SendDataMonitor(void)
{
    //create Temp obj
    initCluster();
}

void SendDataMonitor::initCluster()
{
    //create Temp obj
    pTemp = new Temp();

    //create Warning obj
    pWarning = new Warning();
}

void SendDataMonitor::sendKeyInput(KzsInputKey mbutton){
    switch(mbutton){
    case KZS_KEY_A: 
    case KZS_KEY_MINUS:
        pTemp->onKeyInput(mbutton);
        break;
    case KZS_KEY_C:
    case KZS_KEY_D:
        pWarning->onKeyInput(mbutton);
        break;
    }
}

void SendDataMonitor::sendDataValue(int dataType, float valueInput){
    switch(dataType){
    case RANGE_VALUE:
        pWarning->onDataReceived(valueInput);
        break;
    }
    
}

SendDataMonitor::~SendDataMonitor(void)
{
    delete pTemp;
    delete pWarning;
}
