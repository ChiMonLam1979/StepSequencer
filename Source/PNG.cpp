#include "PNG.h"

PNG::PNG(Image image):image(image)
{
	
}

PNG::~PNG()
{
	
}

void PNG::paint(Graphics& g)
{
	g.drawImage(image, getLocalBounds().toFloat());
}