#include "NoteLengthHandler.h"
#include "ParameterDictionary.h"
#include "DefaulValues.h"

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
	auto length = static_cast<float>(newValue) / DefaultValues::MidiUppperRangeValue;
	auto index = noteLengthDictionary.find(parameterID);

	noteLengths[index->second] = std::ceil(length *samplesPerNoteDivision);
}