#include "Encoder.h"
#include "ComponentDimensions.h"

Encoder::Encoder(
	const String& name, 
	LED& led)
	:
	Slider(name),
	led(led)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(encoderLookAndFeel);
	setRotaryParameters(ComponentPositions::EncoderStartAngleRadians, ComponentPositions::EncoderEndAngleRadians, false);
}

Encoder::~Encoder()
{
}

void Encoder::mouseEnter(const MouseEvent& event)
{
	led.setState(Enums::LEDGreen);
}

void Encoder::mouseExit(const MouseEvent& event)
{
	led.setState(Enums::LEDOff);
}

void Encoder::buttonClicked(Button* button)
{
	int buttonType = button->getProperties().getWithDefault("type", Enums::SelectorButton);

	if(buttonType == Enums::IncButton)
	{
		setValue(getValue() + 1);
	}

	else if(buttonType == Enums::DecButton)
	{
		setValue(getValue() - 1);
	}

	else if (buttonType == Enums::MasterIncButton && isGrouped)
	{
		setValue(getValue() + 1);
	}

	else if (buttonType == Enums::MasterDecButton && isGrouped)
	{
		setValue(getValue() - 1);
	}

	else if (buttonType == Enums::SelectorButton)
	{
		isCourseMode = !isCourseMode;
		isGrouped = !isGrouped;
	}
}