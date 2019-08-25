#include "SelectAllButtonsUpdaterService.h"
#include "ParameterChoices.h"

SelectAllButtonsUpdaterService::SelectAllButtonsUpdaterService(
	std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons)
	:
	gateButtons(stepButtons),
	encoderSelectButtons(selectorButtons)
{
}

SelectAllButtonsUpdaterService::~SelectAllButtonsUpdaterService()
{
}

void SelectAllButtonsUpdaterService::UpdateParameters(int value)
{
	gateButtons->stepButtons[0]->isVisible() ? ToggleGateButtons() : ToggleEncoderSelectButtons();
}

void SelectAllButtonsUpdaterService::ToggleGateButtons()
{
	for (auto& stepButton : gateButtons->stepButtons)
	{
		GateButtonsAllSelected ? DeActivateButton(*stepButton) : ActivateButton(*stepButton);
	}

	GateButtonsAllSelected = !GateButtonsAllSelected;
}

void SelectAllButtonsUpdaterService::ToggleEncoderSelectButtons()
{
	for (auto& stepButton : encoderSelectButtons->stepButtons)
	{
		EncoderSelectButtonsAllSelected ? DeActivateButton(*stepButton) : ActivateButton(*stepButton);
	}

	EncoderSelectButtonsAllSelected = !EncoderSelectButtonsAllSelected;
}

void SelectAllButtonsUpdaterService::ActivateButton(StepButton& button)
{
	button.setToggleState(true, sendNotificationSync);
}

void SelectAllButtonsUpdaterService::DeActivateButton(StepButton& button)
{
	button.setToggleState(false, sendNotificationSync);
}