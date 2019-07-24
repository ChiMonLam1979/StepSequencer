#include "Parameters.h"
#include "StepButtons.h"

StepButtons::StepButtons()
{
	for (auto i = 0; i < 16; i++)
	{
		stepButtons.add(std::make_unique<StepButton>(ParameterNames::StepButtonNames[i], DrawableButton::ButtonStyle::ImageFitted));
	}

	for (auto& stepButton : stepButtons)
	{
		stepButton->onClick = [this, stepButton] { StepClicked(stepButton->getName()); };
	}
}

StepButtons::~StepButtons()
{
}

void StepButtons::MakeVisible(Component& component)
{
	for (auto& stepButton : stepButtons)
	{
		component.addAndMakeVisible(stepButton);
		stepButton->toFront(false);
	}
}

void StepButtons::StepClicked(const String& stepButtonName) const
{
	
}