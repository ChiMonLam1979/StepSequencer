#include "SelectAllButtonHandler.h"
#include "ParameterChoices.h"

SelectAllButtonHandler::SelectAllButtonHandler(std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons)
	:
	gateButtons(stepButtons),
	encoderSelectButtons(selectorButtons)
{
}

SelectAllButtonHandler::~SelectAllButtonHandler()
{
	
}

void SelectAllButtonHandler::parameterChanged(const String& parameterID, float newValue)
{
	gateButtons->stepButtons[0]->isVisible() ? ToggleGateButtons() : ToggleEncoderSelectButtons();
}

void SelectAllButtonHandler::ToggleGateButtons()
{
	for (auto& stepButton : gateButtons->stepButtons)
	{
		GateButtonsAllSelected ? DeActivateButton(*stepButton) : ActivateButton(*stepButton);
	}

	GateButtonsAllSelected = !GateButtonsAllSelected;
}

void SelectAllButtonHandler::ToggleEncoderSelectButtons()
{
	for (auto& stepButton : encoderSelectButtons->stepButtons)
	{
		EncoderSelectButtonsAllSelected ? DeActivateButton(*stepButton) : ActivateButton(*stepButton);
	}

	EncoderSelectButtonsAllSelected = !EncoderSelectButtonsAllSelected;
}

void SelectAllButtonHandler::ActivateButton(StepButton& button)
{
	button.setToggleState(true, sendNotificationSync);
}

void SelectAllButtonHandler::DeActivateButton(StepButton& button)
{
	button.setToggleState(false, sendNotificationSync);
}