#include "LedTimer.h"
#include "Parameters.h"

LedTimer::LedTimer(TransportLEDs& leds) : leds(leds)
{
	this->startTimerHz(30);
}

LedTimer::~LedTimer()
{
}

void LedTimer::timerCallback()
{
	leds.UpdateFlashingLED();
}