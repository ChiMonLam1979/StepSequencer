#include "StepSequencerEditor.h"
#include "ParameterIds.h"
#include "FlexFactory.h"
#include "ComponentDimensions.h"
#include "ParameterNames.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	backPlate				= Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);
	stepEncoders			= std::make_unique<StepEncoders>();
	stepButtons				= std::make_unique<StepButtons>(Enums::GateButton,		ParameterNames::StepButtonNames);
	selectorButtons			= std::make_unique<StepButtons>(Enums::SelectorButton,	ParameterNames::EncoderSelectButtonsNames);
	transportLEDs			= std::make_unique<ChaseLEDs>(p);
	masterEncoderLED		= std::make_unique<LED>();
	masterEncoder			= std::make_unique<MasterEncoder>(ParameterNames::GroupEncoderName, stepEncoders, *masterEncoderLED);

	for(auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::PitchEncoderIDs[i], *stepEncoders->encoders[i]));

		stepButtonAttachments .add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::StepButtonIDs[i],  *stepButtons->stepButtons[i]));

		selectorButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::SelectedEncoderIDs[i], *selectorButtons->stepButtons[i]));
	}

	encoderAttachmentUpdater			= std::make_unique<SliderAttachmentUpdaterService>(stepEncoderAttachments, stepEncoders, processor.treeState);
	stepEncoderChoicesAttachment		= std::make_unique<RadioButtonChoiceAttachment>(*encoderAttachmentUpdater, processor.treeState, IDs::StepChoicesID);

	buttonAttachmentUpdater				= std::make_unique<ButtonAttachmentUpdaterService>(stepButtons, selectorButtons, stepEncoders);
	stepButtonSelectorAttachment		= std::make_unique<BoolButtonAttachment>(*buttonAttachmentUpdater, processor.treeState, IDs::EncodersSelectID);

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);

	addAndMakeVisible(backPlate.get());
	addAndMakeVisible(stepEncoders.get());
	addAndMakeVisible(stepButtons.get());
	addAndMakeVisible(selectorButtons.get());
	addAndMakeVisible(transportLEDs.get());
	addAndMakeVisible(stepEncoderChoicesAttachment.get());
	addAndMakeVisible(stepButtonSelectorAttachment.get());
	addAndMakeVisible(masterEncoder.get());

	selectorButtons->toBehind(stepButtons.get());
}

StepSequencerEditor::~StepSequencerEditor()
{
}

void StepSequencerEditor::paint (Graphics& g)
{
	backPlate->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement(64), 1.0f);
}

void StepSequencerEditor::resized()
{
	transportLEDs	->setBounds(ComponentBounds::ChaseLEDStripBounds);
	stepEncoders	->setBounds(getLocalBounds());
	stepButtons		->setBounds(getLocalBounds());
	selectorButtons	->setBounds(getLocalBounds());
	masterEncoder	->setBounds(getLocalBounds());

	auto buttonBounds = ComponentBounds::StepButtonBounds;

	for(auto& button : selectorButtons->stepButtons)
	{
		button->setBounds(buttonBounds.removeFromLeft(ComponentSizes::StepButtonWidth));
	}

	auto window = getLocalBounds();

	FlexBox stepChoicesButtonsBox = FlexBoxFactory::makeStepChoicesButtonsBox();

	stepChoicesButtonsBox.items.addArray({ 
											FlexItemFactory::makeStepChoicesButtonsBoxItem(*stepEncoderChoicesAttachment, 3)
	});

	FlexBox encoderBox = FlexBoxFactory::makeEncodersBox();

	for(auto& encoder : stepEncoders->encoders)
	{
		encoderBox.items.add(FlexItemFactory::makeEncoderItem(*encoder));
	}

	FlexBox buttonBox = FlexBoxFactory::makeStepButtonsBox();

	for (auto& stepButton : stepButtons->stepButtons)
	{
		buttonBox.items.add(FlexItemFactory::makeButtonItem(*stepButton));
	}

	FlexBox leftEncoderBox = FlexBoxFactory::makeLeftColumnEncodersBox();
	leftEncoderBox.items.add(FlexItemFactory::makeEncoderItem(*masterEncoder));

	FlexBox leftButtonBox = FlexBoxFactory::makeLeftColumnStepButtonsBox();
	leftButtonBox.items.add(FlexItemFactory::makeButtonItem(*stepButtonSelectorAttachment));

	FlexBox leftColumnBox = FlexBoxFactory::makeLeftColumnBox();
	leftColumnBox.items.addArray({
								FlexItem().withFlex(0.53),
								FlexItem(leftEncoderBox).withFlex(0.23),
								FlexItem(leftButtonBox).withFlex(0.14),
								FlexItem().withFlex(0.1)
		});

	FlexBox centralBox = FlexBoxFactory::makeCentralBox();
	centralBox.items.addArray({
								FlexItem(stepChoicesButtonsBox).withFlex(0.53),
								FlexItem(encoderBox).withFlex(0.23),
								FlexItem(buttonBox).withFlex(0.14),
								FlexItem().withFlex(0.1)
		});

	FlexBox main = FlexBoxFactory::makeMasterBox();
	main.items.addArray({
							FlexItem(leftColumnBox).withFlex(0.088),
							FlexItem(centralBox).withFlex(0.912)
		});

	main.performLayout(window);
}