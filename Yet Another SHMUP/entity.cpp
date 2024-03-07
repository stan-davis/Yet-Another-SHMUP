#include "entity.h"

void Entity::tick(float delta)
{
	if (!sprite.visible)
		return;

	//Movement
	position.x += velocity.x * speed * delta;
	position.y += velocity.y * speed * delta;

	rect.x = position.x + rect_offset.x;
	rect.y = position.y + rect_offset.y;

	if (health.current <= 0)
	{
		sprite.visible = false;
	}
}