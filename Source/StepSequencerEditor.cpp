#include "StepSequencerEditor.h"
#include "Parameters.h"

StepSequencerEditor::StepSequencerEditor(StepSequencerEngine& p) : AudioProcessorEditor (&p), processor (p)
{
	stepButtons					= std::make_unique<OwnedArray<StepButton>>();
	playPositionLedsOffArray	= std::make_unique<OwnedArray<Drawable>>();
	playPositionLedOn			= Drawable::createFromImageData(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize);
	//playPositionLedsOnArray		= std::make_unique<OwnedArray<Drawable>>();

	for(auto i = 0; i < 16; i++)
	{
		stepButtons					->add(std::make_unique<StepButton>(ParameterNames::StepButtonNames[i], DrawableButton::ButtonStyle::ImageFitted));
		playPositionLedsOffArray	->add(Drawable::createFromImageData(BinaryData::LEDOff_png,	BinaryData::LEDOff_pngSize));
		//playPositionLedsOnArray		->add(Drawable::createFromImageData(BinaryData::LEDOn_png,	BinaryData::LEDOn_pngSize));
	}

	underStepButtonsPanel = std::make_unique<BlankPanel>(ComponentSizes::windowWidth, ComponentSizes::UnderStepButtonsPanelHeight);

	backPlate = Drawable::createFromImageData(BinaryData::BackPanel_png, BinaryData::BackPanel_pngSize);

    setSize (ComponentSizes::windowWidth, ComponentSizes::windowHeight);
}

StepSequencerEditor::~StepSequencerEditor()
{
	playPositionLedsOffArray = nullptr;
}

void StepSequencerEditor::paint (Graphics& g)
{
	backPlate->drawWithin(g, getLocalBounds().toFloat(), RectanglePlacement(64), 1.0f);
	addAndMakeVisible(backPlate.get());

	addAndMakeVisible(underStepButtonsPanel.get());

	auto stepController = stepButtonsController;

	for (auto& stepButton : *stepButtons)
	{
		stepButton->onClick = [stepController, stepButton] { stepController.StepClicked(stepButton->getName()); };
		addAndMakeVisible(stepButton);
		stepButton->toFront(false);
	}

	auto firstLedXPos		= ComponentPositions::PixelsFromLeftEdgeToFirstLED;
	auto spaceBetweenLeds	= ComponentPositions::NumberOfPixelsBetweenLEDs;
	auto yPosOfLeds			= ComponentPositions::YPositionOfLEDs;
	auto ledBounds			= Rectangle<int>{ firstLedXPos, yPosOfLeds, ComponentSizes::LEDWidth, ComponentSizes::LEDHeight };
	auto ledShouldFlash		= true;
	auto indexOfFlashingLed = 13;

	for(auto i = 0; i < 16; i++)
	{
		auto leds = playPositionLedsOffArray.get();
		auto led = leds->getUnchecked(i);

		if(i == indexOfFlashingLed && ledShouldFlash)
		{
			paintLed(g, playPositionLedOn.get(), ledBounds);
		}
		else
		{
			paintLed(g, led, ledBounds);
		}

		ledBounds.setX(ledBounds.getX() + spaceBetweenLeds);
	}
}

void StepSequencerEditor::paintLed(Graphics& g, Drawable* led, Rectangle<int> bounds)
{
	addAndMakeVisible(led);
	led->setBounds(bounds);
	led->drawAt(g, 0, 0, 1);
	led->toFront(false);
}

void StepSequencerEditor::resized()
{
	auto window = getLocalBounds();

	FlexBox buttonBox;
	buttonBox.justifyContent	= FlexBox::JustifyContent::center;
	buttonBox.alignContent		= FlexBox::AlignContent::flexEnd;

	for(auto& stepButton : *stepButtons)
	{
		buttonBox.items.add(makeButtonBoxItem(*stepButton));
	}

	FlexItem underStepButtonsPanelItem	= makeUnderStepButtonsPanelItem(*underStepButtonsPanel);
	underStepButtonsPanelItem.alignSelf	= FlexItem::AlignSelf::center;

	FlexBox main;
	main.flexDirection = FlexBox::Direction::column;
	main.items.addArray({
								FlexItem(buttonBox).withFlex(1),
								FlexItem(underStepButtonsPanelItem)
	});

	main.performLayout(window);
}

FlexItem StepSequencerEditor::makeButtonBoxItem(Component& component)
{
	return FlexItem(component)
		.withMinHeight(ComponentSizes::StepButtonHeight)
		.withMinWidth(ComponentSizes::StepButtonWidth)
		.withMaxHeight(ComponentSizes::StepButtonHeight)
		.withMaxWidth(ComponentSizes::StepButtonWidth);
}

FlexItem StepSequencerEditor::makeUnderStepButtonsPanelItem(Component& component)
{
	return FlexItem(component)
		.withMinHeight(ComponentSizes::UnderStepButtonsPanelHeight)
		.withMaxHeight(ComponentSizes::UnderStepButtonsPanelHeight);
}