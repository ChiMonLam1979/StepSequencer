#include "VelocityHandler.h"
#include "ParameterDictionary.h"


VelocityHandler::VelocityHandler(std::vector<uint8>& velocities) : velocities(velocities)
{
	
}

VelocityHandler::~VelocityHandler()
{
	
}

void VelocityHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto velocity = static_cast<uint8>(newValue);
	auto index = ParameterDictionaries::velocityDictionary[parameterID];

	velocities[index] = velocity;
}