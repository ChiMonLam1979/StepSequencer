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

	StepSequencerEngine& processor;

	std::unique_ptr<Drawable>	backPlate					{ Drawable::createFromImageData(BinaryData::BackPanelTextured_png, BinaryData::BackPanelTextured_pngSize) };

	ChaseLEDs					transportLEDs				{ processor };
	StepEncoders				stepEncoders;
	StepButtons					stepButtons					{ Enums::GateButton, ParameterNames::StepButtonName, processor };
	StepButtons					selectorButtons				{ Enums::EncoderSelectorButton, ParameterNames::EncoderSelectButtonName, processor };
	StepButtons					stepIncButtons				{ Enums::IncButton, ParameterNames::IncButtonName, processor }; 
	StepButtons					stepDecButtons				{ Enums::DecButton, ParameterNames::DecButtonName, processor };
	StepButtons					masterIncButtons			{ Enums::MasterIncButton, ParameterNames::MasterIncButtonName, processor, 1 };
	StepButtons					masterDecButtons			{ Enums::MasterDecButton, ParameterNames::MasterDecButtonName, processor, 1 };
	LED							masterEncoderLED;
	MasterEncoder				masterEncoder				{ ParameterNames::MasterEncoderName, stepEncoders, masterEncoderLED };

	IncDecButtonListenerService	incDecButtonListenerService{ stepEncoders, masterEncoder, stepIncButtons, stepDecButtons, masterIncButtons, masterDecButtons };

	OwnedArray<AudioProcessorValueTreeState::SliderAttachment>	stepEncoderAttachments;

	std::unique_ptr<SliderAttachmentUpdaterService>				encoderAttachmentUpdater;

	std::unique_ptr<RadioButtonChoiceAttachment>				stepEncoderChoicesAttachment;

	StepButton stepButtonSelectorToggleButton { ParameterNames::EncodersSelectName, DrawableButton::ButtonStyle::ImageFitted, Enums::StepButtonType::ToggleButton };

	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> stepButtonSelectorToggleButtonAttachment;
	std::unique_ptr<EncodersSelectorHandler>						encodersSelectorHandler;

	StepButton selectAllButtonsToggleButton{ ParameterNames::SelectAllButtonName, DrawableButton::ButtonStyle::ImageFitted, Enums::StepButtonType::SelectAllToggleButton };

	std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> selectAllButtonsToggleButtonAttachment;
	std::unique_ptr<SelectAllButtonHandler>							selectAllButtonsHandler;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepSequencerEditor)
};