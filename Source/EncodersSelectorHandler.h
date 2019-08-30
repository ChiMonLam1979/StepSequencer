#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "StepButtons.h"

class EncodersSelectorHandler : public AudioProcessorValueTreeState::Listener
{
public:

	EncodersSelectorHandler
	(
		std::unique_ptr<StepButtons>& stepButtons,
		std::unique_ptr<StepButtons>& selectorButtons,
		std::unique_ptr<StepEncoders>&	stepEncoders
	);

	~EncodersSelectorHandler();

	void ShowGateButtons();
	void ShowEncoderSelectButtons();

	bool showingGateButtons{ true };

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	std::unique_ptr<StepButtons>&	stepButtons;
	std::unique_ptr<StepButtons>&	selectorButtons;
	std::unique_ptr<StepEncoders>&	stepEncoders;
};