#pragma once

#include "input.h"
#include "time.h"
#include "entity.h"
#include <SDL.h>
#include <vector>

class Core
{
public:
	Core() = default;
	~Core() = default;

	int run(int _window_width, int _window_height, int _frame_rate);

protected:
	virtual void start() = 0;
	virtual void tick(float delta) = 0;

	SDL_Window* window;
	SDL_Renderer* renderer;
	int window_width, window_height;
	bool is_running = true;

	Input input;
	Time time;

	std::vector<std::shared_ptr<Entity>> entities;
};