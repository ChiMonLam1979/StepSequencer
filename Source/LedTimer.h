#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "TransportLEDs.h"

class LedTimer : public Timer
{
public:

	LedTimer(TransportLEDs& leds);
	~LedTimer();

	void timerCallback() override;

	TransportLEDs& leds;

private:

};