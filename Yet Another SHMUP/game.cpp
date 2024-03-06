#include "game.h"

void Game::start()
{
	//Player def
	player = std::make_unique<Ship>();
	player->position = { 300, 250 };
	player->rotation = 180;
	player->speed = 250;
	player->sprite = std::make_unique<Sprite>(renderer, "assets/sprites/Ships/spaceShips_001.png");
	player->aabb = std::make_unique<AABB>(player->position, player->sprite->size);
	player->health = std::make_unique<Health>(50);
	entities.push_back(player);

	//enemy def
	enemy = std::make_unique<Ship>();
	enemy->position = { 300, 64 };
	enemy->rotation = 180;
	enemy->speed = 250;
	enemy->sprite = std::make_unique<Sprite>(renderer, "assets/sprites/Ships/spaceShips_004.png");
	enemy->aabb = std::make_unique<AABB>(enemy->position, enemy->sprite->size);
	enemy->health = std::make_unique<Health>(3);
	entities.push_back(enemy);
}

void Game::tick(float delta)
{
	player->velocity.x = (float)input.is_key_held(SDL_SCANCODE_RIGHT) - (float)input.is_key_held(SDL_SCANCODE_LEFT);
	player->velocity.y = (float)input.is_key_held(SDL_SCANCODE_DOWN) - (float)input.is_key_held(SDL_SCANCODE_UP);

	if (input.is_key_pressed(SDL_SCANCODE_Z))
	{
		std::shared_ptr<Entity> projectile = std::make_shared<Entity>();
		projectile->speed = 400;
		projectile->velocity = { 0, -1 };
		projectile->sprite = std::make_unique<Sprite>(renderer, "assets/sprites/Missiles/spaceMissiles_015.png");
		projectile->aabb = std::make_unique<AABB>(player->position, projectile->sprite->size);
		projectile->health = std::make_unique<Health>(1);
		projectile->position = { player->position.x + player->sprite->center.x, player->position.y + player->sprite->center.y };
		entities.push_back(projectile);
		player->projectiles.push_back(projectile);
	}

	for (auto& p : player->projectiles)
	{
		if (p->aabb->intersects(enemy->aabb.get()))
		{
			p->health->change_health(-1);
			enemy->health->change_health(-1);
		}
	}

	for (auto& p : enemy->projectiles)
	{
		if (p->aabb->intersects(player->aabb.get()))
		{
			p->health->change_health(-1);
			enemy->health->change_health(-1);
		}
	}
}