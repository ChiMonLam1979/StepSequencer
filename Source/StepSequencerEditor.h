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

	StepSequencerEditor(StepSequencerEngine& p);
    ~StepSequencerEditor();

    void paint (Graphics&) override;
	void resized() override;

	SharedResourcePointer<DrawablesCache>		svgCache;
	SharedResourcePointer<EncoderLookAndFeel>	encoderLookAndFeel;

private:

	StepSequencerEngine&		processor;

	std::unique_ptr<Drawable>	backPlate					{ Drawable::createFromImageData(BinaryData::BackPanelTextured_png, BinaryData::BackPanelTextured_pngSize) };

	ChaseLEDs					transportLEDs				{ processor };
	StepEncoders				stepEncoders				{ processor };
	StepButtons					stepButtons					{ Enums::GateButton, ParameterNames::StepButtonName, processor };
	StepButtons					selectorButtons				{ Enums::EncoderSelectorButton, ParameterNames::EncoderSelectButtonName, processor };
	StepButtons					stepIncButtons				{ Enums::IncButton, ParameterNames::IncButtonName, processor }; 
	StepButtons					stepDecButtons				{ Enums::DecButton, ParameterNames::DecButtonName, processor };
	StepButtons					masterIncButtons			{ Enums::MasterIncButton, ParameterNames::MasterIncButtonName, processor, 1 };
	StepButtons					masterDecButtons			{ Enums::MasterDecButton, ParameterNames::MasterDecButtonName, processor, 1 };
	LED							masterEncoderLED;
	MasterEncoder				masterEncoder				{ ParameterNames::MasterEncoderName, stepEncoders, masterEncoderLED };

	IncDecButtonListenerService						incDecButtonListenerService					{ stepEncoders, masterEncoder, stepIncButtons, stepDecButtons, masterIncButtons, masterDecButtons };

	std::unique_ptr<SliderAttachmentUpdaterService>	encoderAttachmentUpdater;
	std::unique_ptr<RadioButtonChoiceAttachment>	stepEncoderChoicesAttachment;

	StepButton										stepButtonSelectorToggleButton				{ ParameterNames::EncodersSelectName, DrawableButton::ImageFitted, Enums::ToggleButton };
	AudioProcessorValueTreeState::ButtonAttachment	stepButtonSelectorToggleButtonAttachment	{ processor.treeState, IDs::EncodersSelectID, stepButtonSelectorToggleButton };

	StepButton										selectAllButtonsToggleButton				{ ParameterNames::SelectAllButtonName, DrawableButton::ImageFitted, Enums::SelectAllToggleButton };
	AudioProcessorValueTreeState::ButtonAttachment	selectAllButtonsToggleButtonAttachment		{ processor.treeState, IDs::SelectAllButtonID, selectAllButtonsToggleButton };

	EncodersSelectorHandler							encodersSelectorHandler						{ stepButtons, selectorButtons, stepEncoders };
	SelectAllButtonHandler							selectAllButtonsHandler						{ stepButtons, selectorButtons };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};