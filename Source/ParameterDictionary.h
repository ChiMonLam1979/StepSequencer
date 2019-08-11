#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Enums.h"

extern const std::map<String, int> pitchDictionary;

extern const std::map<String, int> noteLengthDictionary;

extern const std::map<String, int> velocityDictionary;

extern const std::map<String, int> gateDictionary;

Image getLedImage(Enums::LEDState state);