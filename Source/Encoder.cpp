#include "Encoder.h"
#include "ComponentDimensions.h"
#include "ParameterIds.h"

Encoder::Encoder(const String& name, LED& led): Slider(name), led(led)
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
	int buttonType = button->getProperties().getWithDefault(IDs::ButtonTypePropertyID, Enums::NotInUse);

	switch (buttonType)
	{
	case Enums::IncButton: setValue(getValue() + 1);
		break;
	case Enums::DecButton: setValue(getValue() - 1);
		break;
	case Enums::EncoderSelectorButton: SwitchGroupedState();
		break;
	}

	if(isGrouped)
	{
		UpdateGroupedEncoderValues((Enums::StepButtonType)buttonType);
	}
}

void Encoder::UpdateGroupedEncoderValues(Enums::StepButtonType buttonType)
{
	switch (buttonType)
	{
	case Enums::MasterIncButton: setValue(getValue() + 1);
		break;
	case Enums::MasterDecButton: setValue(getValue() - 1);
		break;
	}
}

void Encoder::SwitchGroupedState()
{
	isGrouped = !isGrouped;
}

void Encoder::SwitchCoarseMode()
{
	isCourseMode = !isCourseMode;
}