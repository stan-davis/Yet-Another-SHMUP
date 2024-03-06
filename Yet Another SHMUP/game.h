#pragma once

#include "core.h"
#include "ship.h"

#include <vector>

class Game : public Core
{
public:
	Game() = default;
	~Game() = default;

	void start() override;
	void tick(float delta) override;
	
	std::shared_ptr<Ship> player;
	std::shared_ptr<Ship> enemy;
};

