#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "StepButtons.h"

class EncodersSelectorHandler : public AudioProcessorValueTreeState::Listener
{
public:

	EncodersSelectorHandler
	(
		StepButtons& stepButtons,
		StepButtons& selectorButtons,
		StepEncoders& stepEncoders
	);

	~EncodersSelectorHandler();

	void ShowGateButtons();
	void ShowEncoderSelectButtons();

	bool showingGateButtons{ true };

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	StepButtons&	stepButtons;
	StepButtons&	selectorButtons;
	StepEncoders&	stepEncoders;
};