#include "aabb.h"

AABB::AABB(SDL_FPoint position, SDL_FPoint size)
{
	rect.x = position.x;
	rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;
}

void AABB::tick(SDL_FPoint position)
{
	rect.x = position.x;
	rect.y = position.y;
}

bool AABB::intersects(AABB* b)
{
	if (disabled || b->disabled)
		return false;

	if (rect.x < (b->rect.x + b->rect.w) && (rect.x + rect.w) > b->rect.x && 
		rect.y < (b->rect.y + b->rect.h) && (rect.y + rect.h) > b->rect.y)
	{
		return true;
	}

	return false;
}
