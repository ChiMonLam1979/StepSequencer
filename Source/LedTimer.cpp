#include "LedTimer.h"

LedTimer::LedTimer(TransportLEDs& transportLEDs) : transportLEDs(transportLEDs)
{
	this->startTimerHz(60);
}

LedTimer::~LedTimer()
{
}

void LedTimer::timerCallback()
{
	transportLEDs.UpdateFlashingLED();
}