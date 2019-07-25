#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayPositionLeds.h"

class LedTimer : public Timer
{
public:

	LedTimer(PlayPositionLeds& playPositionLeds);
	~LedTimer();

	void timerCallback() override;

	PlayPositionLeds& playPositionLeds;


private:

};