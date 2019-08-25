#include "SelectorButtonUpdaterService.h"
#include "ParameterChoices.h"

SelectorButtonUpdaterService::SelectorButtonUpdaterService(
	std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons,
	std::unique_ptr<StepEncoders>&	stepEncoders)
	:
	stepButtons(stepButtons),
	selectorButtons(selectorButtons),
	stepEncoders(stepEncoders)
{
}

SelectorButtonUpdaterService::~SelectorButtonUpdaterService()
{
}

void SelectorButtonUpdaterService::UpdateParameters(int value)
{
	const auto choice = ParameterChoices::stepSelectorChoices[value];

	if (choice == ParameterChoices::stepEncodersSelect)
	{
		ShowEncoderSelectButtons();
	}

	if (choice == ParameterChoices::stepButtonsSelect)
	{
		ShowGateButtons();
	}
}

void SelectorButtonUpdaterService::ShowEncoderSelectButtons()
{
	for(auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(true);
		stepButtons->stepButtons[i]->setVisible(false);
		selectorButtons->stepButtons[i]->addListener(stepEncoders->encoders[i].get());
	}
}

void SelectorButtonUpdaterService::ShowGateButtons()
{
	for (auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(false);
		stepButtons->stepButtons[i]->setVisible(true);
		selectorButtons->stepButtons[i]->removeListener(stepEncoders->encoders[i].get());
	}
}