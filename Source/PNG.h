#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PNG : public Component
{
public:

	PNG(Image image);
	~PNG();

	void paint(Graphics& g) override;

private:

	Image image;
};