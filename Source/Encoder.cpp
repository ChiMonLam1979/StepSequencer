#include "Encoder.h"
#include "EncoderLookAndFeel.h"

Encoder::Encoder(const String& name, LED& led, EncoderLookAndFeel& encoderLookAndFeel) : Slider(name), encoderLookAndFeel(encoderLookAndFeel), led(led)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setRange(0, 127, 1);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(&encoderLookAndFeel);
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