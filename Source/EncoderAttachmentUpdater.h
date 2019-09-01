#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ChoiceUpdaterService.h"
#include "Encoder.h"

class EncoderAttachmentUpdater : public ChoiceUpdaterService
{
public:

	EncoderAttachmentUpdater
	(
		OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
		std::vector<std::unique_ptr<Encoder>>&	encoders,
		AudioProcessorValueTreeState& treeState);

	~EncoderAttachmentUpdater();

	void UpdateParameters(int value) override;

private:

	void AttachEncodersToPitch();
	void AttachEncodersToNoteLength();
	void AttachEncodersToVelocity();

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments;
	std::vector<std::unique_ptr<Encoder>>&	encoders;
	AudioProcessorValueTreeState& treeState;
};