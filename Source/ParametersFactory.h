#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class ParametersFactory
{
public:

	ParametersFactory();
	~ParametersFactory();

	std::vector<std::unique_ptr<RangedAudioParameter>> CreateParameters();

private:

};