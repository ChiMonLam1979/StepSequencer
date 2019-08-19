#include "ButtonAttachmentUpdaterService.h"
#include "ParameterChoices.h"

ButtonAttachmentUpdaterService::ButtonAttachmentUpdaterService(
	std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons)
	:
	stepButtons(stepButtons),
	selectorButtons(selectorButtons)
{
}

ButtonAttachmentUpdaterService::~ButtonAttachmentUpdaterService()
{
}

void ButtonAttachmentUpdaterService::UpdateParameters(String choice)
{
	if (choice == ParameterChoices::stepEncodersSelect)
	{
		ShowEncoderSelectButtons();
	}

	if (choice == ParameterChoices::stepButtonsSelect)
	{
		ShowGateButtons();
	}
}

void ButtonAttachmentUpdaterService::ShowEncoderSelectButtons()
{
	for(auto& button: stepButtons->stepButtons)
	{
		button->setVisible(false);
	}

	for (auto& button : selectorButtons->stepButtons)
	{
		button->setVisible(true);
	}
}

void ButtonAttachmentUpdaterService::ShowGateButtons()
{
	for (auto& button : stepButtons->stepButtons)
	{
		button->setVisible(true);
	}

	for (auto& button : selectorButtons->stepButtons)
	{
		button->setVisible(false);
	}
}