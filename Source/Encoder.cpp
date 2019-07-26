#include "Encoder.h"

Encoder::Encoder(const String& name) : Slider(name)
{
	setOpaque(true);
	setSliderStyle(SliderStyle::Rotary);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

Encoder::~Encoder()
{
	
}

void Encoder::paint(Graphics& g)
{
	g.drawImage(image, getLocalBounds().toFloat());
}