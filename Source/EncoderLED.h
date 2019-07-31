#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class EncoderLED : public Component
{
public:

	EncoderLED();
	~EncoderLED();
	
	void paint(Graphics& g) override;
	void toggle(bool useOn);

	bool useOnImage{ false };

private:

	Image OnImage	{ ImageCache::getFromMemory(BinaryData::LEDOnGreen_png, BinaryData::LEDOnGreen_pngSize) };
	Image OffImage	{ ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) };
};