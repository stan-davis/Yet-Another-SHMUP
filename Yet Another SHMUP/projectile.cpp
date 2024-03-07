#include "projectile.h"

void Projectile::tick(float delta)
{
	if (!sprite.visible)
		return;

	if (position.x < -32 || position.x > 1280 || position.y < -32 || position.y > 960)
	{
		sprite.visible = false;
	}

	Entity::tick(delta);
}
