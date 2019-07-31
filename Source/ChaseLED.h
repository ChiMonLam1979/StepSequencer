#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class ChaseLED : public Component
{
public:

	ChaseLED();
	~ChaseLED();

	void paint(Graphics& g) override;
	void toggle(bool useOn);

	bool useOnImage{ false };

private:

	Image OnImage { ImageCache::getFromMemory(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize) };
	Image OffImage{ ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) };
};