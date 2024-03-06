#pragma once

#include "ship.h"
#include "input.h"

class Player : public Ship
{
public:
	Player(SDL_Renderer* renderer);
	~Player() = default;

	void tick(float delta) override;

private:
	Input input;
};

