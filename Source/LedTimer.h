#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "TransportLEDs.h"

class LedTimer : public Timer
{
public:

	LedTimer(TransportLEDs& transportLEDs);
	~LedTimer();

	void timerCallback() override;

	TransportLEDs& transportLEDs;

private:

};