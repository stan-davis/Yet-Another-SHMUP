#include "ship.h"

void Ship::tick(float delta)
{
	if (!sprite.visible)
		return;

	projectile.timer--;

	if (projectile.timer < 0)
	{
		projectile.timer = projectile.fire_rate;
		fire();
	}

	Entity::tick(delta);
}

void Ship::fire()
{
	for (int i = 0; i < projectile.amount; i++)
	{
		std::shared_ptr<Projectile> p = std::make_shared<Projectile>(projectile.entity);

		//Center projectile
		p->position.x = (position.x + sprite.center.x) - p->sprite.center.x;
		p->position.y = (position.y + sprite.center.y) - p->sprite.center.y;
		
		const int spread = 24;
		float offset = i - ((float)(projectile.amount - 1) / 2);
		p->position.x += offset * 24;

		//Angle projectiles outwards
		int mid = projectile.amount / 2;

		if (projectile.angle != 0 && i != mid)
		{
			if (i < mid)
			{
				p->velocity.x = -1 / (float)projectile.amount;
			}
			else if (i > mid)
			{
				p->velocity.x = 1 / (float)projectile.amount;
			}
		}

		children.push_back(p);
	}
}
