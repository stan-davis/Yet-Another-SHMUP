#pragma once

#include <SDL.h>
#include <string>

class Sprite
{
public:
	Sprite() = default;
	~Sprite();

	void set_texture(SDL_Renderer* renderer, std::string file_path);
	void render(SDL_Renderer* renderer, SDL_FPoint position, float rotation);

	bool visible = true;
	SDL_FRect rect = { 0,0,0,0 };
	SDL_FPoint center = { 0,0 };

private:
	SDL_Texture* texture = NULL;
};