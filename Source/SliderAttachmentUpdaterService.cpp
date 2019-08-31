#include "SliderAttachmentUpdaterService.h"
#include "ParameterIds.h"
#include "ParameterChoices.h"

SliderAttachmentUpdaterService::SliderAttachmentUpdaterService
(
	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
	StepEncoders&	stepEncoders,
	AudioProcessorValueTreeState& treeState
) :
	stepEncoderAttachments(stepEncoderAttachments),
	stepEncoders(stepEncoders),
	treeState(treeState)
{
}

SliderAttachmentUpdaterService::~SliderAttachmentUpdaterService()
{
}

void SliderAttachmentUpdaterService::UpdateParameters(int value)
{
	const auto choice = ParameterChoices::StepChoices[value];

	if (choice == ParameterChoices::Pitch)
	{
		AttachEncodersToPitch();
	}

	if (choice == ParameterChoices::NoteLength)
	{
		AttachEncodersToNoteLength();
	}

	if (choice == ParameterChoices::Velocity)
	{
		AttachEncodersToVelocity();
	}
}

void SliderAttachmentUpdaterService::AttachEncodersToPitch()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::PitchEncoderID + number, *stepEncoders.encoders[i]));
	}
}

void SliderAttachmentUpdaterService::AttachEncodersToNoteLength()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::NoteLengthEncoderID + number, *stepEncoders.encoders[i]));
	}
}

void SliderAttachmentUpdaterService::AttachEncodersToVelocity()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		auto number = String(i);
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::VelocityEncoderID + number, *stepEncoders.encoders[i]));
	}
}