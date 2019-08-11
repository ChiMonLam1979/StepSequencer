#include "StepSequencerEditor.h"
#include "ParameterIds.h"
#include "FlexFactory.h"
#include "ComponentDimensions.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	backPlate				= Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);
	blankSidePanel			= std::make_unique<BlankPanel>(ComponentSizes::blankSidePanelWidth, ComponentSizes::StepButtonHeight);
	stepEncoders			= std::make_unique<StepEncoders>();
	stepButtons				= std::make_unique<StepButtons>();
	transportLEDs			= std::make_unique<ChaseLEDs>(p);
	underStepButtonsPanel	= std::make_unique<BlankPanel>(ComponentSizes::windowWidth, ComponentSizes::UnderStepButtonsPanelHeight);

	for(auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::PitchEncoderIDs[i], *stepEncoders->encoders[i]));

		stepButtonAttachments .add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::StepButtonIDs[i],  *stepButtons->stepButtons[i]));
	}

	encoderAttachmentUpdater	= std::make_unique<SliderAttachmentUpdaterService>(stepEncoderAttachments, stepEncoders, processor.treeState);
	stepChoicesAttachment		= std::make_unique<RadioButtonChoiceAttachment>(*encoderAttachmentUpdater, processor.treeState, IDs::StepChoicesID);

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);

	addAndMakeVisible(backPlate.get());
	addAndMakeVisible(blankSidePanel.get());
	addAndMakeVisible(stepEncoders.get());
	stepButtons->MakeVisible(*this);
	addAndMakeVisible(transportLEDs.get());
	addAndMakeVisible(underStepButtonsPanel.get());
	addAndMakeVisible(stepChoicesAttachment.get());
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
	transportLEDs->setBounds(ComponentBounds::ChaseLEDStripBounds);
	stepEncoders->setBounds(getLocalBounds());

	auto window = getLocalBounds();

	FlexBox stepChoicesButtonsBox = FlexBoxFactory::makeStepChoicesButtonsBox();

	stepChoicesButtonsBox.items.addArray({ 
											FlexItemFactory::makeBlankSidePanelItem(*blankSidePanel),
											FlexItemFactory::makeStepChoicesButtonsBoxItem(*stepChoicesAttachment, 3)
	});

	FlexBox encoderBox = FlexBoxFactory::maketEncodersBox();

	for(auto& encoder : stepEncoders->encoders)
	{
		encoderBox.items.add(FlexItemFactory::makeEncoderBoxItem(*encoder));
	}

	FlexBox buttonBox = FlexBoxFactory::makeStepButtonsBox();

	for (auto& stepButton : stepButtons->stepButtons)
	{
		buttonBox.items.add(FlexItemFactory::makeButtonBoxItem(*stepButton));
	}

	FlexItem underStepButtonsPanelItem	= FlexItemFactory::makeUnderStepButtonsPanelItem(*underStepButtonsPanel);

	FlexBox main = FlexBoxFactory::makeMasterBox();
	main.items.addArray({
								FlexItem(stepChoicesButtonsBox).withFlex(0.71),
								FlexItem(encoderBox).withFlex(0.3),
								FlexItem(buttonBox).withFlex(0.18),
								FlexItem(underStepButtonsPanelItem)
	});

	main.performLayout(window);
}