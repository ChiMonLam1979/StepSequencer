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
	for(auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(true);
		stepButtons->stepButtons[i]->setVisible(false);
	}
}

void ButtonAttachmentUpdaterService::ShowGateButtons()
{
	for (auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(false);
		stepButtons->stepButtons[i]->setVisible(true);
	}
}