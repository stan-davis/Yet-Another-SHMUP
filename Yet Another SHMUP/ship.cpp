#include "ship.h"

void Ship::tick(float delta)
{
	position.x += velocity.x * speed * delta;
	position.y += velocity.y * speed * delta;

	if (aabb)
		aabb->tick(position);
}
