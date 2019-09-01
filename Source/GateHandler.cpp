#include "GateHandler.h"
#include "DefaulValues.h"
#include "ParameterUtilities.h"

GateHandler::GateHandler(std::vector<bool>& gates) : gates(gates)
{
}

GateHandler::~GateHandler()
{
}

void GateHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto gate = static_cast<bool>(newValue);

	auto index = getParameterIndex(parameterID);

	gates[index] = gate;
}