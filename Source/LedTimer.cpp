#include "LedTimer.h"
#include "Parameters.h"

LedTimer::LedTimer(TransportLEDs& leds) : leds(leds)
{
	this->startTimerHz(60);
}

LedTimer::~LedTimer()
{
}

void LedTimer::timerCallback()
{
	leds.UpdateFlashingLED();
}