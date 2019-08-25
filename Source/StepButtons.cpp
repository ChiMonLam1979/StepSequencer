#include "StepButtons.h"
#include "ParameterNames.h"
#include "Extensions.h"

StepButtons::StepButtons(Enums::StepButtonType buttonType, const StringArray& names, int numberOfButtons)
{
	switch(buttonType)
	{
	case Enums::IncDecButtons: CreateIncDecButtons(numberOfButtons, names);
		break;
	case Enums::MasterIncDecButtons: CreateMasterIncDecButtons(numberOfButtons, names);
		break;
	default: CreateButtons(numberOfButtons, names, buttonType);
	}

	for (auto& stepButtonItem : stepButtons)
	{
		auto* stepButton = stepButtonItem.get();
		stepButton->onClick = [this, stepButton] { StepClicked(stepButton->getName()); };
		addAndMakeVisible(stepButton);
	}

	setInterceptsMouseClicks(false, true);
}

StepButtons::~StepButtons()
{
}

void StepButtons::CreateButtons(int numberOfButtons, const StringArray& names, Enums::StepButtonType buttonType)
{

	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto button = std::make_unique<StepButton>(names[i], DrawableButton::ButtonStyle::ImageFitted, buttonType);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::CreateIncDecButtons(int numberOfButtons, const StringArray& names)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto isEven = maths::mod(i, 2) == 0;
		auto button = std::make_unique<StepButton>(names[i], DrawableButton::ButtonStyle::ImageFitted, isEven ? Enums::DecButton : Enums::IncButton);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::CreateMasterIncDecButtons(int numberOfButtons, const StringArray& names)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto isEven = maths::mod(i, 2) == 0;
		auto button = std::make_unique<StepButton>(names[i], DrawableButton::ButtonStyle::ImageFitted, isEven ? Enums::MasterDecButton : Enums::MasterIncButton);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::StepClicked(const String& stepButtonName) const
{

}