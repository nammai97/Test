#pragma once
#include "Handler.h"
class Speed : public Handler
{
private:
    int mSpeed;
public:
    Speed(void);
    void setValue(int speed);
    int getValue();
    void autoTest(bool enabled);
    ~Speed(void);
};

