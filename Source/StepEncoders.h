#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Encoder.h"

class StepEncoders : public Component
{
public:

	StepEncoders();
	~StepEncoders();

	//void resized() override;

	OwnedArray<Encoder> encoders;

private:

};
