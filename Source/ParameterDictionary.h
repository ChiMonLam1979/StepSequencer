#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Enums.h"

Image getLedImage(Enums::LEDState state);

int getParameterIndex(const String& genericParameterID, const String& IDToFind, int numberOfParameters);