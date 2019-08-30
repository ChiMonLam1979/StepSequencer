#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepButtons.h"

class SelectAllButtonHandler : public AudioProcessorValueTreeState::Listener
{
public:

	SelectAllButtonHandler
	(
		std::unique_ptr<StepButtons>& stepButtons,
		std::unique_ptr<StepButtons>& selectorButtons
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

	std::unique_ptr<StepButtons>&	gateButtons;
	std::unique_ptr<StepButtons>&	encoderSelectButtons;
};
