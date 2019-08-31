#include "StepSequencerEditor.h"
#include "ParameterIds.h"
#include "FlexFactory.h"
#include "ComponentDimensions.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	for(auto i = 0; i < DefaultValues::NumberOfSteps; i++)
	{
		auto number = String(i);

		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::PitchEncoderID + number, *stepEncoders.encoders[i]));

		stepButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::StepButtonID + number,  *stepButtons.stepButtons[i]));

		selectorButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::SelectedEncoderID + number, *selectorButtons.stepButtons[i]));

		incDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::IncButtonID + number, *stepIncButtons.stepButtons[i]));

		incDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::DecButtonID + number, *stepDecButtons.stepButtons[i]));
	}

	masterIncDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::MasterDecButtonID, masterIncButton));
	masterIncDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::MasterIncButtonID, masterDecButton));

	encoderAttachmentUpdater					= std::make_unique<SliderAttachmentUpdaterService>(stepEncoderAttachments, stepEncoders, processor.treeState);

	stepEncoderChoicesAttachment				= std::make_unique<RadioButtonChoiceAttachment>(*encoderAttachmentUpdater, processor.treeState, IDs::StepChoicesID);

	stepButtonSelectorToggleButtonAttachment	= std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, IDs::EncodersSelectID, stepButtonSelectorToggleButton);
	encodersSelectorHandler						= std::make_unique<EncodersSelectorHandler>(stepButtons, selectorButtons, stepEncoders);

	selectAllButtonsToggleButtonAttachment		= std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, IDs::SelectAllButtonID, selectAllButtonsToggleButton);
	selectAllButtonsHandler						= std::make_unique<SelectAllButtonHandler>(stepButtons, selectorButtons);

	processor.treeState.addParameterListener(IDs::EncodersSelectID, encodersSelectorHandler.get());
	processor.treeState.addParameterListener(IDs::SelectAllButtonID, selectAllButtonsHandler.get());

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);

	addAndMakeVisible(backPlate.get());
	addAndMakeVisible(stepEncoders);
	addAndMakeVisible(stepButtons);
	addAndMakeVisible(selectorButtons);
	addAndMakeVisible(transportLEDs);
	addAndMakeVisible(stepEncoderChoicesAttachment.get());
	addAndMakeVisible(stepButtonSelectorToggleButton);
	addAndMakeVisible(masterEncoder);
	addAndMakeVisible(masterEncoderLED);
	addAndMakeVisible(stepIncButtons);
	addAndMakeVisible(stepDecButtons);
	addAndMakeVisible(masterIncButton);
	addAndMakeVisible(masterDecButton);
	addAndMakeVisible(selectAllButtonsToggleButton);

	selectorButtons.toBehind(&stepButtons);
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
	transportLEDs		.setBounds(ComponentBounds::ChaseLEDStripBounds);
	stepEncoders		.setBounds(getLocalBounds());
	stepButtons			.setBounds(getLocalBounds());
	selectorButtons		.setBounds(getLocalBounds());
	masterEncoder		.setBounds(getLocalBounds());
	masterEncoderLED	.setBounds(ComponentBounds::masterEncoderLEDBounds);
	stepIncButtons		.setBounds(getLocalBounds());
	stepDecButtons		.setBounds(getLocalBounds());
	masterIncButton		.setBounds(getLocalBounds());
	masterDecButton		.setBounds(getLocalBounds());


	auto buttonBounds = ComponentBounds::StepButtonBounds;

	for(auto& button : selectorButtons.stepButtons)
	{
		button->setBounds(buttonBounds.removeFromLeft(ComponentSizes::StepButtonWidth));
	}

	auto window = getLocalBounds();

	FlexBox stepChoicesButtonsBox = FlexBoxFactory::makeStepChoicesButtonsBox();

	stepChoicesButtonsBox.items.addArray({ 
											FlexItemFactory::makeStepChoicesButtonsBoxItem(*stepEncoderChoicesAttachment, 3)
	});

	FlexBox encoderBox = FlexBoxFactory::makeEncodersBox();

	for(auto& encoder : stepEncoders.encoders)
	{
		encoderBox.items.add(FlexItemFactory::makeEncoderItem(*encoder));
	}

	FlexBox buttonBox = FlexBoxFactory::makeStepButtonsBox();

	for (auto& stepButton : stepButtons.stepButtons)
	{
		buttonBox.items.add(FlexItemFactory::makeButtonItem(*stepButton));
	}

	FlexBox leftColumnMiddleButtonBox = FlexBoxFactory::makeLeftColumnStepButtonsBox();
	leftColumnMiddleButtonBox.items.add(FlexItemFactory::makeButtonItem(selectAllButtonsToggleButton));


	FlexBox leftColumnEncoderBox = FlexBoxFactory::makeLeftColumnEncodersBox();
	leftColumnEncoderBox.items.add(FlexItemFactory::makeEncoderItem(masterEncoder));

	FlexBox leftColumnLowerButtonBox = FlexBoxFactory::makeLeftColumnStepButtonsBox();
	leftColumnLowerButtonBox.items.add(FlexItemFactory::makeButtonItem(stepButtonSelectorToggleButton));


	FlexBox leftColumnIncButtonsBox = FlexBoxFactory::makeLeftColumnIncButtonsBox();
	leftColumnIncButtonsBox.items.addArray({ 
								FlexItemFactory::makeIncDecButtonsItem(masterIncButton),
								FlexItemFactory::makeIncDecButtonsItem(masterDecButton)
		});

	FlexBox leftColumnBox = FlexBoxFactory::makeLeftColumnBox();
	leftColumnBox.items.addArray({
								FlexItem(leftColumnMiddleButtonBox).withFlex(0.53),
								FlexItem(leftColumnEncoderBox).withFlex(0.18),
								FlexItem().withFlex(0.01),
								FlexItem(leftColumnIncButtonsBox).withFlex(0.04),
								FlexItem(leftColumnLowerButtonBox).withFlex(0.14),
								FlexItem().withFlex(0.1)
		});

	FlexBox centralIncButtonsBox = FlexBoxFactory::makeCentralIncButtonsBox();

	for (auto i = 0; i < 16; ++i)
	{
		centralIncButtonsBox.items.add(FlexItemFactory::makeDecButtonsItem(*stepIncButtons.stepButtons[i]));
		centralIncButtonsBox.items.add(FlexItemFactory::makeIncButtonsItem(*stepDecButtons.stepButtons[i]));
	}

	FlexBox centralBox = FlexBoxFactory::makeCentralBox();
	centralBox.items.addArray({
								FlexItem(stepChoicesButtonsBox).withFlex(0.53),
								FlexItem(encoderBox).withFlex(0.18),
								FlexItem().withFlex(0.01),
								FlexItem(centralIncButtonsBox).withFlex(0.04),
								FlexItem(buttonBox).withFlex(0.14),
								FlexItem().withFlex(0.1)
		});

	FlexBox rightColumnBox = FlexBoxFactory::makeRightColumnBox();

	FlexBox main = FlexBoxFactory::makeMasterBox();
	main.items.addArray({
							FlexItem(leftColumnBox).withFlex(0.088),
							FlexItem(centralBox).withFlex(0.824),
							FlexItem(rightColumnBox).withFlex(0.088)
		});

	main.performLayout(window);
}