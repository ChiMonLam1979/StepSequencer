#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class EncoderLED : public Component
{
public:

	EncoderLED();
	~EncoderLED();
	
	void paint(Graphics& g) override;

	bool useOnImage{ false };

	void toggle(bool useOn);

private:

	Image OnImage{ ImageCache::getFromMemory(BinaryData::LEDOnGreen_png, BinaryData::LEDOnGreen_pngSize) };
	Image OffImage{ ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) };
};