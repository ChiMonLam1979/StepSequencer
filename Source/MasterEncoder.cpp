#include "MasterEncoder.h"

MasterEncoder::MasterEncoder(const String& name, std::unique_ptr<StepEncoders>& stepEncoders, LED& led): Slider(name), led(led), stepEncoders(stepEncoders)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(encoderLookAndFeel);
	addAndMakeVisible(led);
	setRotaryParameters(2.61779, 8.90118, false);
	addAndMakeVisible(led);
	led.setState(Enums::LEDOff);
}

MasterEncoder::~MasterEncoder()
{
}

void MasterEncoder::resized()
{
	/*led.setBounds(getLocalBounds())*/;
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