#include "SelectAllButtonHandler.h"

SelectAllButtonHandler::SelectAllButtonHandler()
{
	
}

SelectAllButtonHandler::~SelectAllButtonHandler()
{
	
}

void SelectAllButtonHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto value = static_cast<bool>(newValue);
}