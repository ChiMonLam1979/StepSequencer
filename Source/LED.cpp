#include "LED.h"
#include "ParameterDictionary.h"

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