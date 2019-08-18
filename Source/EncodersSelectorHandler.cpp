#include "EncodersSelectorHandler.h"

EncodersSelectorHandler::EncodersSelectorHandler()
{
	
}EncodersSelectorHandler::~EncodersSelectorHandler()
{
	
}

void EncodersSelectorHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto value = static_cast<bool>(newValue);
}