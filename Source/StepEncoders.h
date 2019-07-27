#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Encoder.h"

class StepEncoders : public Component
{
public:

	StepEncoders();
	~StepEncoders();

	OwnedArray<Encoder> encoders;

private:

};