#include "MasterEncoder.h"
#include "ComponentDimensions.h"

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

	for (auto i = 0; i < 16; ++i)
	{
		if (stepEncoders->encoders[i]->isGrouped)
		{
			stepEncoders->encoders[i]->mouseDown(event);
		}
	}
}

void MasterEncoder::mouseUp(const MouseEvent& event)
{
	Slider::mouseUp(event);

	for (auto i = 0; i < 16; ++i)
	{
		if (stepEncoders->encoders[i]->isGrouped)
		{
			stepEncoders->encoders[i]->mouseUp(event);
		}
	}
}

void MasterEncoder::mouseDrag(const MouseEvent& event)
{
	Slider::mouseDrag(event);

	for(auto i = 0; i < 16; ++i)
	{
		if(stepEncoders->encoders[i]->isGrouped)
		{
			stepEncoders->encoders[i]->mouseDrag(event);
		}
	}
}

void MasterEncoder::mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel)
{
	Slider::mouseWheelMove(event, wheel);

	for (auto i = 0; i < 16; ++i)
	{
		if (stepEncoders->encoders[i]->isGrouped)
		{
			stepEncoders->encoders[i]->mouseWheelMove(event, wheel);
		}
	}
}