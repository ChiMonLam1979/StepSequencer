#include "SliderAttachmentUpdaterService.h"
#include "ParameterIds.h"
#include "ParameterChoices.h"

SliderAttachmentUpdaterService::SliderAttachmentUpdaterService
(
	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
	std::unique_ptr<StepEncoders>&	stepEncoders,
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

void SliderAttachmentUpdaterService::UpdateParameters(String choice)
{
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
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::PitchEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}

void SliderAttachmentUpdaterService::AttachEncodersToNoteLength()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::NoteLengthEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}

void SliderAttachmentUpdaterService::AttachEncodersToVelocity()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(treeState, IDs::VelocityEncoderIDs[i], *stepEncoders->encoders[i]));
	}
}