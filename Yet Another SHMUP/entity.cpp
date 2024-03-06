#include "entity.h"

void Entity::tick(float delta)
{
	//Movement
	position.x += velocity.x * speed * delta;
	position.y += velocity.y * speed * delta;

	if (aabb)
		aabb->tick(position);

	if (sprite && health && aabb)
	{
		if (health->current <= 0)
		{
			sprite->visible = false;
			aabb->disabled = true;
		}
	}
}