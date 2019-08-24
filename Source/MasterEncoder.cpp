#include "MasterEncoder.h"
#include "ComponentDimensions.h"
#include "ParameterIds.h"

MasterEncoder::MasterEncoder(const String& name, std::unique_ptr<StepEncoders>& stepEncoders, LED& led): Slider(name), led(led), stepEncoders(stepEncoders)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setRotaryParameters(ComponentPositions::EncoderStartAngleRadians, ComponentPositions::EncoderEndAngleRadians, false);
	setLookAndFeel(encoderLookAndFeel);
	led.setState(Enums::LEDOff);
}

MasterEncoder::~MasterEncoder()
{
}

void MasterEncoder::buttonClicked(Button* button)
{
	int buttonType = button->getProperties().getWithDefault(IDs::ButtonTypePropertyID, Enums::SelectorButton);

	switch(buttonType)
	{
	case Enums::MasterIncButton: setValue(getValue() + 1);
		break;
	case Enums::MasterDecButton: setValue(getValue() - 1);
		break;
	}
}

void MasterEncoder::mouseEnter(const MouseEvent& event)
{
	led.setState(Enums::LEDGreen);
}

void MasterEncoder::mouseExit(const MouseEvent& event)
{
	led.setState(Enums::LEDOff);
}

void MasterEncoder::mouseDown(const MouseEvent& event)
{
	Slider::mouseDown(event);

	ForwardMouseEvent(event, Enums::MouseDown);
}

void MasterEncoder::mouseUp(const MouseEvent& event)
{
	Slider::mouseUp(event);

	ForwardMouseEvent(event, Enums::MouseUp);
}

void MasterEncoder::mouseDrag(const MouseEvent& event)
{
	Slider::mouseDrag(event);

	ForwardMouseEvent(event, Enums::MouseDrag);
}

void MasterEncoder::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel)
{
	Slider::mouseWheelMove(event, wheel);

	ForwardMouseEvent(event, Enums::MouseWheelMove, wheel);
}

void MasterEncoder::ForwardMouseEvent(const MouseEvent& event, Enums::MouseEventType mouseEventType, const MouseWheelDetails& wheel)
{
	for (auto i = 0; i < 16; ++i)
	{
		if (stepEncoders->encoders[i]->isGrouped)
		{
			switch(mouseEventType)
			{
			case Enums::MouseDown:		stepEncoders->encoders[i]->mouseDown(event);
				break;
			case Enums::MouseUp:		stepEncoders->encoders[i]->mouseUp(event);
				break;
			case Enums::MouseDrag:		stepEncoders->encoders[i]->mouseDrag(event);
				break;
			case Enums::MouseWheelMove:	stepEncoders->encoders[i]->mouseWheelMove(event, wheel);
				break;
			}
		}
	}
}