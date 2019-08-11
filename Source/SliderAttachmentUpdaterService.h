#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepEncoders.h"
#include "ChoiceUpdaterService.h"

class SliderAttachmentUpdaterService : public ChoiceUpdaterService
{
public:
	SliderAttachmentUpdaterService
	(
		OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments,
		std::unique_ptr<StepEncoders>&	stepEncoders,
		AudioProcessorValueTreeState& treeState
	);

	~SliderAttachmentUpdaterService();

	void UpdateParameters(String choice) override;

	void AttachEncodersToPitch();
	void AttachEncodersToNoteLength();
	void AttachEncodersToVelocity();

private:

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>& stepEncoderAttachments;
	std::unique_ptr<StepEncoders>&	stepEncoders;
	AudioProcessorValueTreeState& treeState;
};
