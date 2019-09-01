#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Encoder.h"
#include "StepSequencerEngine.h"
#include "EncoderAttachmentUpdater.h"
#include "RadioButtonChoiceAttachment.h"

class StepEncoders : public Component
{

public:

	StepEncoders(StepSequencerEngine& processor);

	~StepEncoders();

	std::vector<std::unique_ptr<Encoder>>	encoders;
	std::vector<std::unique_ptr<LED>>		encoderLeds;

	void resized() override;

private:

	void encoderValueChanged(const String& encoderName) const;
	void AttachToParameters();

	StepSequencerEngine& processor;

public:

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>	stepEncoderAttachments;

	EncoderAttachmentUpdater	encoderAttachmentUpdater	{ stepEncoderAttachments, encoders, processor.treeState };

	RadioButtonChoiceAttachment stepEncoderChoicesAttachment{ encoderAttachmentUpdater, processor.treeState, IDs::StepChoicesID };
};