#include "SelectedEncodersHandler.h"

SelectedEncodersHandler::SelectedEncodersHandler()
{

}SelectedEncodersHandler::~SelectedEncodersHandler()
{

}

void SelectedEncodersHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto value = static_cast<bool>(newValue);
}