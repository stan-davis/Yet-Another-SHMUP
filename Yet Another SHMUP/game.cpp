#include "game.h"

void Game::start()
{
	//Player def
	player = std::make_unique<Ship>();
	player->position = { 240,240 };
	player->rotation = 180;
	player->sprite = std::make_unique<Sprite>(renderer, "assets/sprites/Ships/spaceShips_001.png");
	player->aabb = std::make_unique<AABB>(player->position, player->sprite->get_size());
	player->health = std::make_unique<Health>(100);
}

void Game::tick(float delta)
{
	player->tick(delta);
}

void Game::render()
{
	player->sprite->render(renderer, player->position, player->rotation);
}
