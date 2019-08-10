#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class DrawablesCache
{
public:

	DrawablesCache();
	~DrawablesCache();

	Drawable* GetOrUpdateDrawableFromCache(void* cacheKey, int size);

private:

	std::map<int64, std::unique_ptr<Drawable>> drawableCache;
};