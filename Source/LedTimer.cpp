#include "LedTimer.h"

LedTimer::LedTimer(PlayPositionLeds& playPositionLeds) : playPositionLeds(playPositionLeds)
{
	this->startTimerHz(60);
}

LedTimer::~LedTimer()
{
}

void LedTimer::timerCallback()
{
	playPositionLeds.SetFlashingLedVisibility();
}