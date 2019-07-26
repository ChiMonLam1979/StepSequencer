 #pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "LED.h"

class TransportLEDs : public Component, public Timer
{
public:

	TransportLEDs(StepSequencerEngine& processor);
	~TransportLEDs();

	OwnedArray<LED> leds;

	void resized() override;

	void timerCallback() override;

	bool shouldFlash{ false };
	int	 lastIndex	{ 0 };
	int	 index		{ 0 };

	StepSequencerEngine& processor;

private:

};