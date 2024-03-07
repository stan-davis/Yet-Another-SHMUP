#pragma once

#include "input.h"
#include "time.h"
#include "entity.h"

#include <SDL.h>
#include <SDL_ttf.h>
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
	virtual void render() = 0;

	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	int window_width, window_height;
	bool is_running = true;
	bool is_debug = true;

	Time time;

	std::vector<std::shared_ptr<Entity>> entities;

private:
	void draw_debug_rect(SDL_FRect& rect);
};