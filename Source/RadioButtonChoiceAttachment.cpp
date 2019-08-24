#include "ParameterIds.h"
#include "ParameterChoices.h"
#include "RadioButtonChoiceAttachment.h"

RadioButtonChoiceAttachment::RadioButtonChoiceAttachment
(
	ChoiceUpdaterService& updaterService,
	AudioProcessorValueTreeState& treeState,
	const String& parameterId
): 
	updaterService(updaterService)
{
	parameter = dynamic_cast<AudioParameterChoice*>(treeState.getParameter(parameterId));

	for(auto& choice: parameter->choices)
	{
		buttons.add(new StepButton(choice, DrawableButton::ButtonStyle::ImageFitted, Enums::RadioButton));
	}

	for(auto& button : buttons)
	{
		addAndMakeVisible(button);
		button->setRadioGroupId(100);
		button->onClick = [this, button] { Clicked(button->getName()); };
	}

	buttons[0]->setToggleState(true, sendNotificationSync);

	treeState.addParameterListener(parameterId, this);	
}

RadioButtonChoiceAttachment::~RadioButtonChoiceAttachment()
{
}

void RadioButtonChoiceAttachment::resized()
{
	auto area	= getLocalBounds();
	auto width	= getWidth() / int(buttons.size());

	for (auto& button : buttons)
	{
		button->setBounds(area.removeFromLeft(width));
	}
}

void RadioButtonChoiceAttachment::Clicked(const String& choice)
{
	auto index = std::find_if(ParameterChoices::StepChoices.begin(), ParameterChoices::StepChoices.end(), [choice](const auto b) { return b == choice; });

	*parameter = int(std::distance(ParameterChoices::StepChoices.begin(), index));
}

void RadioButtonChoiceAttachment::parameterChanged(const String& parameterID, float newValue)
{
	const auto choice = ParameterChoices::StepChoices[newValue];

	updaterService.UpdateParameters(choice);
}