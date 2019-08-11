#include "StepHandler.h"
#include "ParameterDictionary.h"

StepHandler::StepHandler(std::vector<bool>& gates) : gates(gates)
{

}

StepHandler::~StepHandler()
{
	
}

void StepHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto gate = static_cast<bool>(newValue);
	auto index = ParameterDictionaries::gateDictionary[parameterID];

	gates[index] = gate;
}