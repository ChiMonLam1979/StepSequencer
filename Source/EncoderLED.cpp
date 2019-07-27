#include "EncoderLED.h"

EncoderLED::EncoderLED()
{
}

EncoderLED::~EncoderLED()
{
}

void EncoderLED::paint(Graphics& g)
{
	g.drawImage(useOnImage ? OnImage : OffImage, getLocalBounds().toFloat());
}

void EncoderLED::toggle(bool useOn)
{
	useOnImage = useOn;
	repaint();
}