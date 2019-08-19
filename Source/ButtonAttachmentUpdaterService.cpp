#include "ButtonAttachmentUpdaterService.h"
#include "ParameterChoices.h"

ButtonAttachmentUpdaterService::ButtonAttachmentUpdaterService(
	std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons,
	std::unique_ptr<StepEncoders>&	stepEncoders)
	:
	stepButtons(stepButtons),
	selectorButtons(selectorButtons),
	stepEncoders(stepEncoders)
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
		selectorButtons->stepButtons[i]->addListener(stepEncoders->encoders[i].get());
	}
}

void ButtonAttachmentUpdaterService::ShowGateButtons()
{
	for (auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(false);
		stepButtons->stepButtons[i]->setVisible(true);
		selectorButtons->stepButtons[i]->removeListener(stepEncoders->encoders[i].get());
	}
}