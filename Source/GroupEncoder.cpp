#include "GroupEncoder.h"
#include "EncoderLookAndFeel.h"

GroupEncoder::GroupEncoder(const String& name, LED& led) : Slider(name), led(led)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(encoderLookAndFeel);
	addAndMakeVisible(led);
}

GroupEncoder::~GroupEncoder()
{

}

void GroupEncoder::mouseEnter(const MouseEvent& event)
{
	led.setState(Enums::LEDGreen);
}

void GroupEncoder::mouseExit(const MouseEvent& event)
{
	led.setState(Enums::LEDOff);
}