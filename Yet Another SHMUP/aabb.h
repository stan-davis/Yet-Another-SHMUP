#pragma once

#include "types.h"
#include <SDL.h>

class AABB
{
public:
	AABB(vec2 position, vec2 size);
	~AABB() = default;
	
	void tick(vec2 position);
	bool intersects(AABB* b);

	SDL_Rect rect = { 0,0,0,0 };
};