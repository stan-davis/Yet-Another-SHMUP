#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Text
{
public:
	Text() = default;
	~Text();

	void set_text(SDL_Renderer* renderer, TTF_Font* font, std::string text);
	void render(SDL_Renderer* renderer, SDL_FPoint position);
	SDL_FRect rect;

private:
	const SDL_Color FONT_COLOR = {255, 255, 255, 255}; //white
	SDL_Texture* texture = NULL;
};