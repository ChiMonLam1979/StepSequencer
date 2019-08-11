#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Encoder.h"

class StepEncoders : public Component
{
public:

	StepEncoders();
	~StepEncoders();

	EncoderLookAndFeel		encoderLookAndFeel;

	OwnedArray<Encoder>		encoders;
	OwnedArray<LED>			encoderLeds;

	void resized() override;

private:

	void encoderValueChanged(const String& encoderName) const;
};