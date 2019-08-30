#include "EncodersSelectorHandler.h"
#include "ParameterChoices.h"

EncodersSelectorHandler::EncodersSelectorHandler(
	std::unique_ptr<StepButtons>& stepButtons,
	std::unique_ptr<StepButtons>& selectorButtons,
	std::unique_ptr<StepEncoders>&	stepEncoders)
	:
	stepButtons(stepButtons),
	selectorButtons(selectorButtons),
	stepEncoders(stepEncoders)
{
}

EncodersSelectorHandler::~EncodersSelectorHandler()
{
}

void EncodersSelectorHandler::ShowEncoderSelectButtons()
{
	for (auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(true);
		stepButtons->stepButtons[i]->setVisible(false);
		selectorButtons->stepButtons[i]->addListener(stepEncoders->encoders[i].get());
	}
}

void EncodersSelectorHandler::ShowGateButtons()
{
	for (auto i = 0; i < 16; ++i)
	{
		selectorButtons->stepButtons[i]->setVisible(false);
		stepButtons->stepButtons[i]->setVisible(true);
		selectorButtons->stepButtons[i]->removeListener(stepEncoders->encoders[i].get());
	}
}

void EncodersSelectorHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto value = static_cast<bool>(newValue);

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