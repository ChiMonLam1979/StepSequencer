#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "DefaulValues.h"

class ParametersFactory
{
public:

	ParametersFactory();
	~ParametersFactory();

	std::vector<std::unique_ptr<RangedAudioParameter>> CreateParameters(int numberOfSteps = DefaultValues::NumberOfSteps);

private:

};