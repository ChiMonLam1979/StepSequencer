#include "PatternLengthDecHandler.h"

PatternLengthDecHandler::PatternLengthDecHandler(int& patternLength) : patternLength(patternLength)
{

}

PatternLengthDecHandler::~PatternLengthDecHandler()
{

}

void PatternLengthDecHandler::parameterChanged(const String& parameterID, float newValue)
{
	patternLength = patternLength > 1 ? --patternLength : 1;
}