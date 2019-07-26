 #pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "LED.h"


class TransportLEDs : public Component
{
public:

	TransportLEDs(StepSequencerEngine& processor);
	~TransportLEDs();

	OwnedArray<LED> leds;

	void resized() override;

	void UpdateFlashingLED();

	bool shouldFlash{ false };
	int	 lastIndex	{ 0 };
	int	 index		{ 0 };

	StepSequencerEngine& processor;

private:

};
