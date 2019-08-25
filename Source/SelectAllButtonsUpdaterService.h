#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "StepButtons.h"
#include "StepEncoders.h"

class SelectAllButtonsUpdaterService : public ChoiceUpdaterService
{
public:

	SelectAllButtonsUpdaterService
	(
		std::unique_ptr<StepButtons>& stepButtons,
		std::unique_ptr<StepButtons>& selectorButtons
	);

	~SelectAllButtonsUpdaterService();

	void UpdateParameters(int value) override;

	void ToggleGateButtons();
	void ToggleEncoderSelectButtons();

	void ActivateButton(StepButton& button);
	void DeActivateButton(StepButton& button);

	bool GateButtonsAllSelected			{ false };
	bool EncoderSelectButtonsAllSelected{ false };

private:

	std::unique_ptr<StepButtons>&	gateButtons;
	std::unique_ptr<StepButtons>&	encoderSelectButtons;
};