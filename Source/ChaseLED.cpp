#include "ChaseLED.h"

ChaseLED::ChaseLED()
{
}

ChaseLED::~ChaseLED()
{
}

void ChaseLED::paint(Graphics& g)
{
	g.drawImage(useOnImage ? OnImage : OffImage, getLocalBounds().toFloat());
}

void ChaseLED::toggle(bool useOn)
{
	useOnImage = useOn;
	repaint();
}