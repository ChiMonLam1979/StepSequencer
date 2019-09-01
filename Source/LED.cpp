#include "LED.h"
#include "ImageUtilities.h"

LED::LED()
{
	setState(Enums::LEDOff);
}

LED::~LED()
{
}

void LED::paint(Graphics& g)
{
	g.drawImage(led, getLocalBounds().toFloat());
}

void LED::setState(Enums::LEDState state)
{
	led = getLedImage(state);
	repaint();
}