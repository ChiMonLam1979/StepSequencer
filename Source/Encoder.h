#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class Encoder : public Slider
{
public:

	Encoder(const String& name);
	~Encoder();

	void paint(Graphics& g) override;

private:

	Image image{ ImageCache::getFromMemory(BinaryData::Encoder_png, BinaryData::Encoder_pngSize) };

};