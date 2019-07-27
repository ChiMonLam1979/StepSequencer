#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"

class Encoder : public Slider
{
public:

	Encoder(const String& name);
	~Encoder();

private:

	EncoderLookAndFeel encoderLookAndFeel;
};