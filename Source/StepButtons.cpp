#include "StepButtons.h"
#include "ParameterNames.h"

StepButtons::StepButtons(Enums::StepButtonType buttonType, const String& name, int numberOfButtons)
{
	for (auto i = 0; i < numberOfButtons; i++)
	{
		auto number = String(i);
		auto button = std::make_unique<StepButton>((name + number), DrawableButton::ButtonStyle::ImageFitted, buttonType);
		stepButtons.push_back(std::move(button));
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

void StepButtons::StepClicked(const String& stepButtonName) const
{
}