#include "StepSequencerEditor.h"
#include "Parameters.h"
#include "FlexFactory.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	backPlate				= Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);
	stepEncoders			= std::make_unique<StepEncoders>();
	stepButtons				= std::make_unique<StepButtons>();
	transportLEDs			= std::make_unique<ChaseLEDs>(p);
	underStepButtonsPanel	= std::make_unique<BlankPanel>(ComponentSizes::windowWidth, ComponentSizes::UnderStepButtonsPanelHeight);

	for(auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::StepEncoderIDs[i], *stepEncoders->encoders[i]));

		encodersAttachedToPitch = true;

		stepButtonAttachments .add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::StepButtonIDs[i],  *stepButtons->stepButtons[i]));
	}

	toggleButton.onClick = [this] { ToggleEncoderAttachment(); };

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);

	addAndMakeVisible(backPlate.get());
	addAndMakeVisible(stepEncoders.get());
	stepButtons->MakeVisible(*this);
	addAndMakeVisible(transportLEDs.get());
	addAndMakeVisible(underStepButtonsPanel.get());

	addAndMakeVisible(toggleButton);
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

	FlexItem toggleButtonItem = FlexItemFactory::makeButtonBoxItem(toggleButton);

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
								FlexItem(toggleButtonItem),
								FlexItem(encoderBox).withFlex(0.83),
								FlexItem(buttonBox).withFlex(0.18),
								FlexItem(underStepButtonsPanelItem)
	});

	main.performLayout(window);
}

void StepSequencerEditor::ToggleEncoderAttachment()
{
	encodersAttachedToPitch ? AttachEncodersToVelocity() : AttachEncodersToPitch();
}

void StepSequencerEditor::AttachEncodersToPitch()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::StepEncoderIDs[i], *stepEncoders->encoders[i]));
	}

	encodersAttachedToPitch = true;
}

void StepSequencerEditor::AttachEncodersToVelocity()
{
	stepEncoderAttachments.clear();

	for (auto i = 0; i < 16; i++)
	{
		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::VelocityEncoderIDs[i], *stepEncoders->encoders[i]));
	}

	encodersAttachedToPitch = false;
}