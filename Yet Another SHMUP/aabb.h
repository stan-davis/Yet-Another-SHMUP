#pragma once

#include <SDL.h>

class AABB
{
public:
	AABB(SDL_FPoint position, SDL_FPoint size);
	~AABB() = default;
	
	void tick(SDL_FPoint position);
	bool intersects(AABB* b);
	bool disabled = false;

	SDL_FRect rect = { 0,0,0,0 };
};