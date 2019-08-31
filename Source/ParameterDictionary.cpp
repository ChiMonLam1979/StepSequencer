#include "ParameterDictionary.h"
#include "ParameterIds.h"

Image getLedImage(Enums::LEDState state)
{
	static const std::map<Enums::LEDState, juce::Image> ledDictionary
	{
		{ Enums::LEDState::LEDOff,		ImageCache::getFromMemory(BinaryData::LEDOff_png, BinaryData::LEDOff_pngSize) },
		{ Enums::LEDState::LEDGreen,	ImageCache::getFromMemory(BinaryData::LEDOnGreen_png, BinaryData::LEDOnGreen_pngSize) },
		{ Enums::LEDState::LEDRed,		ImageCache::getFromMemory(BinaryData::LEDOnRed_png, BinaryData::LEDOnRed_pngSize) }
	};

	const auto it = ledDictionary.find(state);
	return it != ledDictionary.cend() ? it->second : Image{};
}

int getParameterIndex(const String& genericParameterID, const String& IDToFind, int numberOfParameters)
{
	std::map<String, int> parameterDictionary;

	for(auto i = 0; i < numberOfParameters; ++i)
	{
		auto index = String(i);
		auto key = genericParameterID + index;
		parameterDictionary[key] = i;
	}

	const auto it = parameterDictionary.find(IDToFind);
	return it != parameterDictionary.cend() ? it->second : 0;
}