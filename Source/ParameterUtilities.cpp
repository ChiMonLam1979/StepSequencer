#include "ParameterUtilities.h"
#include "DefaulValues.h"

int getParameterIndex(const String& parameterID)
{
	auto subStrings = StringArray::fromTokens(parameterID, DefaultValues::ParameterDelimiter, DefaultValues::QuoteCharacters);

	return subStrings.size() > 1 ? subStrings[1].getIntValue() : 0;
}