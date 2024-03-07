#include "player.h"

Player::Player(SDL_Renderer* renderer)
{
	//Player def
	sprite.set_texture(renderer, "assets/sprites/Ships/spaceShips_001.png");
	health.set_max(50);
	rotation = 180;
	position = { 600, 700 };
	speed = 500;
	rect = { 0, 0, 40, 40 };
	rect_offset = { 35, 40 };

	//Base projectile
	projectile.entity.velocity.y = -1;
	projectile.entity.speed = 600;
	projectile.entity.sprite.set_texture(renderer, "assets/sprites/Missiles/spaceMissiles_015.png");
	projectile.entity.health.set_max(1);
	projectile.fire_rate = 10;
	projectile.amount = 2;
	projectile.entity.rect = projectile.entity.sprite.rect;
}

void Player::tick(float delta)
{
	if (!sprite.visible)
		return;

	//Some way of polling the window width & height would probably be good here
	if (position.x < 0 || position.x >= 1280 - sprite.rect.w || position.y < 0 || position.y >= 960 - sprite.rect.h)
	{
		position.x -= velocity.x * speed * delta;
		position.y -= velocity.y * speed * delta;
	}

	velocity.x = (float)input.is_key_held(SDL_SCANCODE_RIGHT) - (float)input.is_key_held(SDL_SCANCODE_LEFT);
	velocity.y = (float)input.is_key_held(SDL_SCANCODE_DOWN) - (float)input.is_key_held(SDL_SCANCODE_UP);

	if (input.is_key_held(SDL_SCANCODE_Z))
	{
		projectile.timer--;

		if (projectile.timer < 0)
		{
			projectile.timer = projectile.fire_rate;
			fire();
		}
	}
	else if (input.is_key_released(SDL_SCANCODE_Z))
	{
		projectile.timer = 0;
	}

	input.tick();
	Entity::tick(delta);
}
