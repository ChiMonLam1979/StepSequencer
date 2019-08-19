#include "GroupEncoderHandler.h"

GroupEncoderHandler::GroupEncoderHandler()
{
}

GroupEncoderHandler::~GroupEncoderHandler()
{

}

void GroupEncoderHandler::parameterChanged(const String& parameterID, float newValue)
{
	auto value = static_cast<int>(newValue);
}