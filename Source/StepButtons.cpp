#include "StepButtons.h"
#include "ParameterNames.h"
#include "Extensions.h"

StepButtons::StepButtons(Enums::StepButtonType buttonType, const StringArray& names, int numberOfButtons)
{
	if(buttonType == Enums::IncDecButtons)
	{
		for (auto i = 0; i < numberOfButtons; i++)
		{
			auto isEven = maths::mod(i, 2) == 0;
			auto button = std::make_unique<StepButton>(names[i], DrawableButton::ButtonStyle::ImageFitted, isEven ? Enums::DecButton : Enums::IncButton);
			stepButtons.push_back(std::move(button));
		}
	}
	else
	{
		for (auto i = 0; i < numberOfButtons; i++)
		{
			auto button = std::make_unique<StepButton>(names[i], DrawableButton::ButtonStyle::ImageFitted, buttonType);
			stepButtons.push_back(std::move(button));
		}
	}

	for (auto& stepButtonItem : stepButtons)
	{
		auto* stepButton = stepButtonItem.get();
		stepButton->getProperties().set("type", stepButton->buttonType);
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