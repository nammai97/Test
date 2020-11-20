#include "Speed.h"


Speed::Speed(void)
{
	mSpeed = 0;
}
void Speed::setValue( int speed)
{
	mSpeed = speed;
}
int Speed::getValue()
{
	return mSpeed;
}

void Speed::autoTest(bool enabled)
{
}

Speed::~Speed(void)
{
	mSpeed = 0;
}
