#include "Encoder.h"
#include "EncoderLookAndFeel.h"

Encoder::Encoder(const String& name) : Slider(name)
{
	setOpaque(true);
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	setLookAndFeel(&encoderLookAndFeel);
}

Encoder::~Encoder()
{
	
}