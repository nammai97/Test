#include "Temp.h"

using namespace std; 

Temp::Temp()
{
    setDefautValue();
}

void Temp::setDefautValue()
{
    mTemp = 20;
    if(getScreenNode() != nullptr) mTextBlock = getScreenNode()->lookupNode<TextBlock2D>("RootPage/Viewport 2D/Temperature/Value");
    setTempValue(mTemp);
}

void Temp::onKeyInput(KzsInputKey Key){
    switch(Key){
    case KZS_KEY_A: 
    case KZS_KEY_PLUS:
        increaseTempValue();
        break;
    case KZS_KEY_S:
    case KZS_KEY_MINUS:
        decreaseTempValue();
    }
    setTempValue(mTemp);
}

void Temp::increaseTempValue() {
    mTemp++;
}

void Temp::decreaseTempValue() {
    mTemp--;
}

int Temp::getTempValue(){
    return mTemp;
}

void Temp::setTempValue(int tempValue){
    mTextBlock->setText(to_string(tempValue));
}

Temp::~Temp(void)
{
}
