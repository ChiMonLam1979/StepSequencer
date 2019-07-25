 #pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PNG.h"
#include "StepSequencerEngine.h"


class TransportLEDs : public Component
{
public:

	TransportLEDs(StepSequencerEngine& processor);
	~TransportLEDs();

	OwnedArray<PNG> onLeds;
	OwnedArray<PNG> offLeds;

	void resized() override;

	void UpdateFlashingLED();

	bool shouldFlash{ false };
	int	 lastIndex{ 0 };
	int	 index{ 0 };

	StepSequencerEngine& processor;

private:

};