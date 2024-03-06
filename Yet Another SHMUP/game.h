#pragma once

#include "core.h"
#include "ship.h"

class Game : public Core
{
public:
	Game() = default;
	~Game() = default;

	void start() override;
	void tick(float delta) override;
	void render() override;

	std::shared_ptr<Ship> player;
};

