#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class LED : public Component
{
public:

	LED();
	~LED();

	void paint(Graphics& g) override;

	bool useOnImage{ false };

	void toggle(bool useOn);

private:

	Image OnImage { ImageCache::getFromMemory(BinaryData::LEDOn_png, BinaryData::LEDOn_pngSize) };
	Image OffImage{ ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) };
};