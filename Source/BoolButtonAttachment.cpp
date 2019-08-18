#include "BoolButtonAttachment.h"
#include "ParameterNames.h"
#include "ParameterChoices.h"

BoolButtonAttachment::BoolButtonAttachment(
	ChoiceUpdaterService& updaterService,
	AudioProcessorValueTreeState& treeState,
	String& parameterId)
: 
	updaterService(updaterService)
{
	parameter = dynamic_cast<AudioParameterBool*>(treeState.getParameter(parameterId));

	button = std::make_unique<StepButton>(ParameterNames::EncodersSelectName, DrawableButton::ButtonStyle::ImageFitted, Enums::SelectButton);
	addAndMakeVisible(button.get());
	auto boolButton = button.get();
	button->setClickingTogglesState(true);
	button->onClick = [this, boolButton] { Clicked(boolButton->getToggleState()); };

	treeState.addParameterListener(parameterId, this);
}

BoolButtonAttachment::~BoolButtonAttachment()
{
	
}


void BoolButtonAttachment::Clicked(bool value)
{
	*parameter = value;
}

void BoolButtonAttachment::parameterChanged(const String& parameterID, float newValue)
{
	const auto value = static_cast<int>(newValue);

	const auto choice = ParameterChoices::stepSelectorChoices[value];

	updaterService.UpdateParameters(choice);
}