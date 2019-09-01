#include "PatternLengthIncHandler.h"

PatternLengthIncHandler::PatternLengthIncHandler(int& patternLength) : patternLength(patternLength)
{
	
}

PatternLengthIncHandler::~PatternLengthIncHandler()
{
	
}

void PatternLengthIncHandler::parameterChanged(const String& parameterID, float newValue)
{
	 patternLength = patternLength < 16 ? ++patternLength : 16;
}