#include "StepSequencerEditor.h"
#include "ParameterIds.h"
#include "FlexFactory.h"
#include "ComponentDimensions.h"
#include "ParameterNames.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	transportLEDs					= std::make_unique<ChaseLEDs>(p);

	for(auto i = 0; i < DefaultValues::NumberOfSteps; i++)
	{
		auto number = String(i);

		stepEncoderAttachments.add(new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, IDs::PitchEncoderID + number, *stepEncoders.encoders[i]));

		stepButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::StepButtonID + number,  *stepButtons.stepButtons[i]));

		selectorButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::SelectedEncoderID + number, *selectorButtons.stepButtons[i]));

		incDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::IncButtonID + number, *stepIncDecButtons.stepButtons[(i * 2) + 1]));

		incDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::DecButtonID + number, *stepIncDecButtons.stepButtons[(i * 2)]));
	}

	masterIncDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::MasterDecButtonID, *masterIncDecButtons.stepButtons[0]));
	masterIncDecButtonAttachments.add(new AudioProcessorValueTreeState::ButtonAttachment(processor.treeState, IDs::MasterIncButtonID, *masterIncDecButtons.stepButtons[1]));

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
	addAndMakeVisible(transportLEDs.get());
	addAndMakeVisible(stepEncoderChoicesAttachment.get());
	addAndMakeVisible(stepButtonSelectorToggleButton);
	addAndMakeVisible(masterEncoder);
	addAndMakeVisible(masterEncoderLED);
	addAndMakeVisible(stepIncDecButtons);
	addAndMakeVisible(masterIncDecButtons);
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
	transportLEDs		->setBounds(ComponentBounds::ChaseLEDStripBounds);
	stepEncoders		.setBounds(getLocalBounds());
	stepButtons			.setBounds(getLocalBounds());
	selectorButtons		.setBounds(getLocalBounds());
	masterEncoder		.setBounds(getLocalBounds());
	masterEncoderLED	.setBounds(ComponentBounds::masterEncoderLEDBounds);
	stepIncDecButtons	.setBounds(getLocalBounds());
	masterIncDecButtons	.setBounds(getLocalBounds());

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

	for(auto& button: masterIncDecButtons.stepButtons)
	{
		leftColumnIncButtonsBox.items.add(FlexItemFactory::makeIncDecButtonsItem(*button));
	}

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
		centralIncButtonsBox.items.add(FlexItemFactory::makeDecButtonsItem(*stepIncDecButtons.stepButtons[i * 2]));
		centralIncButtonsBox.items.add(FlexItemFactory::makeIncButtonsItem(*stepIncDecButtons.stepButtons[(i * 2) + 1]));
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