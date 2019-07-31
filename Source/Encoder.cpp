#include "Encoder.h"
#include "EncoderLookAndFeel.h"

Encoder::Encoder(const String& name, EncoderLED& led, EncoderLookAndFeel& encoderLookAndFeel) : Slider(name), led(led), encoderLookAndFeel(encoderLookAndFeel)
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
	led.toggle(true);
}

void Encoder::mouseExit(const MouseEvent& event)
{
	led.toggle(false);
}