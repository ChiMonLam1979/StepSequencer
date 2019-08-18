#include "StepButtons.h"
#include "ParameterNames.h"

StepButtons::StepButtons()
{
	for (auto i = 0; i < 16; i++)
	{
		stepButtons.add(std::make_unique<StepButton>(ParameterNames::StepButtonNames[i], DrawableButton::ButtonStyle::ImageFitted, Enums::GateButton));
	}

	for (auto& stepButton : stepButtons)
	{
		stepButton->onClick = [this, stepButton] { StepClicked(stepButton->getName()); };
		addAndMakeVisible(stepButton);
	}

	setInterceptsMouseClicks(false, true);
}

StepButtons::~StepButtons()
{
}

void StepButtons::StepClicked(const String& stepButtonName) const
{
	
}