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
#include "ParameterNames.h"

class StepSequencerEditor : public AudioProcessorEditor
{


public:
	StepSequencerEditor(StepSequencerEngine& processor);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	SharedResourcePointer<DrawablesCache>		svgCache;
	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

private:

	StepSequencerEngine& processor;

	std::unique_ptr<Drawable>	backPlate { Drawable::createFromImageData(BinaryData::BackPanelTextured_png, BinaryData::BackPanelTextured_pngSize) };
	std::unique_ptr<ChaseLEDs>	transportLEDs;

	StepEncoders				stepEncoders;
	StepButtons					stepButtons					{ Enums::GateButton, ParameterNames::StepButtonName };
	StepButtons					selectorButtons				{ Enums::EncoderGroupSelectorButton, ParameterNames::EncoderSelectButtonName };
	StepButtons					stepIncDecButtons			{ Enums::IncDecButtons, ParameterNames::ButtonName, 32 };
	StepButtons					masterIncDecButtons			{ Enums::MasterIncDecButtons, ParameterNames::ButtonName, 2 };
	LED							masterEncoderLED;
	MasterEncoder				masterEncoder				{ ParameterNames::MasterEncoderName, stepEncoders, masterEncoderLED };

	IncDecButtonListenerService	incDecButtonListenerService	{ stepEncoders, masterEncoder, stepIncDecButtons, masterIncDecButtons };

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>	stepEncoderAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	stepButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	selectorButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	incDecButtonAttachments;
	OwnedArray<AudioProcessorValueTreeState::ButtonAttachment>	masterIncDecButtonAttachments;

	std::unique_ptr<SliderAttachmentUpdaterService>				encoderAttachmentUpdater;
	std::unique_ptr<RadioButtonChoiceAttachment>				stepEncoderChoicesAttachment;

	StepButton stepButtonSelectorToggleButton { ParameterNames::EncodersSelectName, DrawableButton::ButtonStyle::ImageFitted, Enums::StepButtonType::ToggleButton };

	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> stepButtonSelectorToggleButtonAttachment;
	std::unique_ptr<EncodersSelectorHandler>						encodersSelectorHandler;

	StepButton selectAllButtonsToggleButton{ ParameterNames::SelectAllButtonName, DrawableButton::ButtonStyle::ImageFitted, Enums::StepButtonType::SelectAllToggleButton };

	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> selectAllButtonsToggleButtonAttachment;
	std::unique_ptr<SelectAllButtonHandler>							selectAllButtonsHandler;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};
