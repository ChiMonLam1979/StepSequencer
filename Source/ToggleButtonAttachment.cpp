#include "ToggleButtonAttachment.h"
#include "ParameterNames.h"

ToggleButtonAttachment::ToggleButtonAttachment(
	ChoiceUpdaterService& updaterService,
	AudioProcessorValueTreeState& treeState,
	const String& parameterId,
	const String& paramterName,
	Enums::StepButtonType buttonType)
: 
	updaterService(updaterService)
{
	parameter	= dynamic_cast<AudioParameterBool*>(treeState.getParameter(parameterId));
	button		= std::make_unique<StepButton>(paramterName, DrawableButton::ButtonStyle::ImageFitted, buttonType);

	auto* boolButton = button.get();
	addAndMakeVisible(boolButton);
	boolButton->setClickingTogglesState(true);
	boolButton->onClick = [this, boolButton] { Clicked(boolButton->getToggleState()); };

	treeState.addParameterListener(parameterId, this);
}

ToggleButtonAttachment::~ToggleButtonAttachment()
{
	
}

void ToggleButtonAttachment::Clicked(bool value)
{
	*parameter = value;
}

void ToggleButtonAttachment::parameterChanged(const String& parameterID, float newValue)
{
	const auto value = static_cast<int>(newValue);

	updaterService.UpdateParameters(value);
}