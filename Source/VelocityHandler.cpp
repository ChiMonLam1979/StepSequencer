#include "VelocityHandler.h"
#include "StepSequencerEngine.h"
#include "ParameterUtilities.h"


VelocityHandler::VelocityHandler(std::vector<uint8>& velocities) : velocities(velocities)
{
}

VelocityHandler::~VelocityHandler()
{
}

void VelocityHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto velocity = static_cast<uint8>(newValue);

	auto index = getParameterIndex(parameterID);

	velocities[index] = velocity;
}