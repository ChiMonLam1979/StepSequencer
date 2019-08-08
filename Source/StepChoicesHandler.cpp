#include "StepChoicesHandler.h"
#include "ParameterChoices.h"

StepChoicesHandler::StepChoicesHandler()
{
	
}

StepChoicesHandler::~StepChoicesHandler()
{
	
}

void StepChoicesHandler::parameterChanged(const String& parameterID, float newValue)
{
	const auto choice = ParameterChoices::StepChoices[newValue];
}