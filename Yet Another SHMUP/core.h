#pragma once

#include <SDL.h>

class Core
{
public:
	Core() = default;
	~Core() = default;

	int run(int _window_width, int _window_height, int _frame_rate);
	virtual void start() = 0;
	virtual void tick(float delta) = 0;
	virtual void render() = 0;

protected:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int window_width, window_height;
	bool is_running = true;
};