#include "NoteLengthHandler.h"
#include "ParameterDictionary.h"

NoteLengthHandler::NoteLengthHandler(std::vector<int>& noteLengths, double& samplesPerNoteDivision) 
:
	noteLengths(noteLengths),
	samplesPerNoteDivision(samplesPerNoteDivision)
{
	
}

NoteLengthHandler::~NoteLengthHandler()
{
	
}

void NoteLengthHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto length = static_cast<float>(newValue);
	auto index = ParameterDictionaries::noteLengthDictionary[parameterID];

	noteLengths[index] = std::ceil(length *samplesPerNoteDivision);
}