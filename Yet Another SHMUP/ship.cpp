#include "ship.h"

void Ship::fire()
{
	for (int i = 0; i < projectile.amount; i++)
	{
		std::shared_ptr<Entity> p = std::make_shared<Entity>(projectile.entity);
		p->position.x = (position.x + sprite.center.x) + (sprite.center.x / projectile.amount) * i;
		p->position.y = (position.y + sprite.center.y);
		children.push_back(p);
	}
}