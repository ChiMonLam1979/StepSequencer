#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "StepSequencerEngine.h"
#include "StepButtons.h"
#include "StepEncoders.h"
#include "ChaseLEDs.h"
#include "DrawablesCache.h"
#include "SliderAttachmentUpdaterService.h"
#include "RadioButtonChoiceAttachment.h"
#include "MasterEncoder.h"
#include "IncDecButtonListenerService.h"
#include "EncodersSelectorHandler.h"
#include "SelectAllButtonHandler.h"

class StepSequencerEditor : public AudioProcessorEditor
{
public:
	StepSequencerEditor(StepSequencerEngine&);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	SharedResourcePointer<DrawablesCache>		svgCache;
	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

	std::unique_ptr<Drawable>						backPlate;
	std::unique_ptr<StepEncoders>					stepEncoders;
	std::unique_ptr<StepButtons>					stepButtons;
	std::unique_ptr<StepButtons>					selectorButtons;
	std::unique_ptr<ChaseLEDs>						transportLEDs;
	std::unique_ptr<LED>							masterEncoderLED;
	std::unique_ptr<MasterEncoder>					masterEncoder;
	std::unique_ptr<StepButtons>					stepIncDecButtons;
	std::unique_ptr<StepButtons>					masterIncDecButtons;
	std::unique_ptr<IncDecButtonListenerService>	incDecButtonListenerService;

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>	stepEncoderAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	stepButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	selectorButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	incDecButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	masterIncDecButtonAttachments;

	std::unique_ptr<SliderAttachmentUpdaterService>				encoderAttachmentUpdater;
	std::unique_ptr<RadioButtonChoiceAttachment>				stepEncoderChoicesAttachment;

	std::unique_ptr<StepButton>										stepButtonSelectorToggleButton;
	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> stepButtonSelectorToggleButtonAttachment;
	std::unique_ptr<EncodersSelectorHandler>						encodersSelectorHandler;

	std::unique_ptr<StepButton>										selectAllButtonsToggleButton;
	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> selectAllButtonsToggleButtonAttachment;
	std::unique_ptr<SelectAllButtonHandler>							selectAllButtonsHandler;

private:

    StepSequencerEngine& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};
