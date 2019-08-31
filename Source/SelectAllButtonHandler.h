#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButtons.h"

class SelectAllButtonHandler : public AudioProcessorValueTreeState::Listener
{
public:

	SelectAllButtonHandler
	(
		StepButtons& stepButtons,
		StepButtons& selectorButtons
	);

	~SelectAllButtonHandler();

	void ToggleGateButtons();
	void ToggleEncoderSelectButtons();

	void ActivateButton(StepButton& button);
	void DeActivateButton(StepButton& button);

	bool GateButtonsAllSelected{ false };
	bool EncoderSelectButtonsAllSelected{ false };

private:

	void parameterChanged(const String& parameterID, float newValue) override;

	StepButtons&	gateButtons;
	StepButtons&	encoderSelectButtons;
};
