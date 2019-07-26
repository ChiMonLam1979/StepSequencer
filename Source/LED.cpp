#include "LED.h"

LED::LED()
{
	setOpaque(true);
}

LED::~LED()
{
}

void LED::paint(Graphics& g)
{
	g.drawImage(useOnImage ? OnImage : OffImage, getLocalBounds().toFloat());
}

void LED::toggle(bool useOn)
{
	useOnImage = useOn;
	repaint();
}