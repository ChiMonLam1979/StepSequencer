#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Encoder.h"

class StepEncoders : public Component
{
public:

	StepEncoders(std::unique_ptr<GroupEncoder>& groupEncoder);
	~StepEncoders();

	std::vector<std::unique_ptr<Encoder>>	encoders;
	std::vector<std::unique_ptr<LED>>		encoderLeds;

	void resized() override;

private:

	void encoderValueChanged(const String& encoderName) const;
};