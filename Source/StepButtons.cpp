#include "StepButtons.h"
#include "ParameterNames.h"
#include "Extensions.h"

StepButtons::StepButtons(Enums::StepButtonType buttonType, const String& name, int numberOfButtons)
{
	switch(buttonType)
	{
	case Enums::IncDecButtons: CreateIncDecButtons(numberOfButtons, name);
		break;
	case Enums::MasterIncDecButtons: CreateMasterIncDecButtons(numberOfButtons, name);
		break;
	default: CreateButtons(numberOfButtons, name, buttonType);
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

void StepButtons::CreateButtons(int numberOfButtons, const String& name, Enums::StepButtonType buttonType)
{

	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto number = String(i);
		auto button = std::make_unique<StepButton>((name + number), DrawableButton::ButtonStyle::ImageFitted, buttonType);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::CreateIncDecButtons(int numberOfButtons, const String& name)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto number = String(i);
		auto isEven = maths::mod(i, 2) == 0;
		auto namePrefix = isEven ? ParameterNames::DecPrefix : ParameterNames::IncPrefix;
		auto button = std::make_unique<StepButton>((namePrefix + name + number), DrawableButton::ButtonStyle::ImageFitted, isEven ? Enums::DecButton : Enums::IncButton);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::CreateMasterIncDecButtons(int numberOfButtons, const String& name)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto number = String(i);
		auto isEven = maths::mod(i, 2) == 0;
		auto namePrefix = isEven ? ParameterNames::MasterDecPrefix : ParameterNames::MasterIncPrefix;
		auto button = std::make_unique<StepButton>((namePrefix + name + number), DrawableButton::ButtonStyle::ImageFitted, isEven ? Enums::MasterDecButton : Enums::MasterIncButton);
		stepButtons.push_back(std::move(button));
	}
}

void StepButtons::StepClicked(const String& stepButtonName) const
{
}