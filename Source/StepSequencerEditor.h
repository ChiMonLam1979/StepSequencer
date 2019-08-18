#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButtons.h"
#include "StepEncoders.h"
#include "ChaseLEDs.h"
#include "DrawablesCache.h"
#include "SliderAttachmentUpdaterService.h"
#include "RadioButtonChoiceAttachment.h"
#include "BoolButtonAttachment.h"
#include "ButtonAttachmentUpdaterService.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	SharedResourcePointer<DrawablesCache>		svgCache;
	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

	std::unique_ptr<Drawable>			backPlate;
	std::unique_ptr<StepEncoders>		stepEncoders;
	std::unique_ptr<StepButtons>		stepButtons;
	std::unique_ptr<ChaseLEDs>			transportLEDs;

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment> stepEncoderAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment> stepButtonAttachments;

	std::unique_ptr<SliderAttachmentUpdaterService>					encoderAttachmentUpdater;
	std::unique_ptr<RadioButtonChoiceAttachment>					stepEncoderChoicesAttachment;

	std::unique_ptr<ButtonAttachmentUpdaterService>					buttonAttachmentUpdater;
	std::unique_ptr<BoolButtonAttachment>							stepButtonSelectorAttachment;

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};
