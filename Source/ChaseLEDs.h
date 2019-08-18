 #pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "LED.h"

class ChaseLEDs : public Component, public Timer
{
public:

	ChaseLEDs(StepSequencerEngine& processor);
	~ChaseLEDs();

	std::vector<std::unique_ptr<LED>> leds;

	void resized() override;

	void timerCallback() override;

	bool shouldFlash{ false };
	int	 lastIndex	{ 0 };
	int	 index		{ 0 };

	StepSequencerEngine& processor;

private:

};
