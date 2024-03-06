#include "aabb.h"

AABB::AABB(vec2 position, vec2 size)
{
	rect.x = (int)position.x;
	rect.y = (int)position.y;
	rect.w = (int)size.x;
	rect.h = (int)size.y;
}

void AABB::tick(vec2 position)
{
	rect.x = (int)position.x;
	rect.y = (int)position.y;
}

bool AABB::intersects(AABB* b)
{
	if (disabled)
		return false;

	if (rect.x < (b->rect.x + b->rect.w) && (rect.x + rect.w) > b->rect.x && 
		rect.y < (b->rect.y + b->rect.h) && (rect.y + rect.h) > b->rect.y)
	{
		return true;
	}

	return false;
}
