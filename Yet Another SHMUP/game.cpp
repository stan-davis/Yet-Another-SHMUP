#include "game.h"

void Game::start()
{
	//Player def
	player = std::make_unique<Ship>();
	player->position = { 240,240 };
	player->rotation = 180;
	player->speed = 250;
	player->sprite = std::make_unique<Sprite>(renderer, "assets/sprites/Ships/spaceShips_001.png");
	player->aabb = std::make_unique<AABB>(player->position, player->sprite->size);
	player->health = std::make_unique<Health>(100);
	entities.push_back(player);
}

void Game::tick(float delta)
{
	input.tick(*player);
}