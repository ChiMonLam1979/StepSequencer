#include "DrawablesCache.h"

DrawablesCache::DrawablesCache()
{

}

DrawablesCache::~DrawablesCache()
{

}

Drawable* DrawablesCache::GetOrUpdateDrawableFromCache(void* cacheKey, int size)
{
	auto it = drawableCache.find(int64(cacheKey));

	if (it != drawableCache.end())
	{
		return it->second.get();
	}
	else
	{
		auto newDrawable = Drawable::createFromImageData(cacheKey, size);

		drawableCache[int64(cacheKey)] = std::move(newDrawable);

		return drawableCache[int64(cacheKey)].get();
	}
}