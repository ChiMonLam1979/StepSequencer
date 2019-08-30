#include "ParameterDictionary.h"
#include "GateHandler.h"

GateHandler::GateHandler(std::vector<bool>& gates) : gates(gates)
{
}

GateHandler::~GateHandler()
{
}

void GateHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto gate = static_cast<bool>(newValue);
	auto index = gateDictionary.find(parameterID);

	gates[index->second] = gate;
}