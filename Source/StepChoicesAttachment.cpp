#include "StepChoicesAttachment.h"
#include "Parameters.h"

StepChoicesAttachment::StepChoicesAttachment
(
	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
	std::unique_ptr<StepEncoders>&	stepEncoders,
	AudioProcessorValueTreeState& treeState,
	String& parameterId
): 
	stepEncoderAttachments(stepEncoderAttachments),
	stepEncoders(stepEncoders),
	treeState(treeState),
	parameterId(parameterId)
{
	parameter = dynamic_cast<AudioParameterChoice*>(treeState.getParameter(parameterId));

	for(auto& choice: parameter->choices)
	{
		buttons.add(new StepButton(choice, DrawableButton::ButtonStyle::ImageFitted, true));
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

StepChoicesAttachment::~StepChoicesAttachment()
{
	
}

void StepChoicesAttachment::resized()
{
	auto area	= getLocalBounds();
	auto width	= getWidth() / int(buttons.size());

	for (auto& button : buttons)
	{
		button->setBounds(area.removeFromLeft(width));
	}
}

void StepChoicesAttachment::Clicked(const String& choice)
{
	auto index = std::find_if(ParameterChoices::StepChoices.begin(), ParameterChoices::StepChoices.end(), [choice](const auto b) { return b == choice; });

	*parameter = int(std::distance(ParameterChoices::StepChoices.begin(), index));
}

void StepChoicesAttachment::parameterChanged(const String& parameterID, float newValue)
{
	const auto choice = ParameterChoices::StepChoices[newValue];

	if(choice == ParameterChoices::Pitch)
	{
		AttachEncodersToPitch();
	}

	if (choice == ParameterChoices::NoteLength)
	{
		AttachEncodersToNoteLength();
	}

	if(choice == ParameterChoices::Velocity)
	{
		AttachEncodersToVelocity();
	}
}

void StepChoicesAttachment::AttachEncodersToPitch()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::PitchEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}

void StepChoicesAttachment::AttachEncodersToNoteLength()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::NoteLengthEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}

void StepChoicesAttachment::AttachEncodersToVelocity()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::VelocityEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}