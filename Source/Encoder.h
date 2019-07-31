#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "EncoderLookAndFeel.h"
#include "EncoderLED.h"

class Encoder : public Slider
{
public:

	Encoder(const String& name, EncoderLED& led, EncoderLookAndFeel& encoderLookAndFeel);
	~Encoder();

	void mouseEnter(const MouseEvent& event) override;

	void mouseExit(const MouseEvent& event) override;

	EncoderLookAndFeel& encoderLookAndFeel;

	EncoderLED& led;

private:
};