#include "text.h"

Text::~Text()
{
	if(texture)
		SDL_DestroyTexture(texture);
}

void Text::set_text(SDL_Renderer* renderer, TTF_Font* font, std::string text)
{
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), FONT_COLOR);

    if (!surface)
    {
        printf("Error: Failed to create surface\nSDL Error: '%s'\n", SDL_GetError());
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!texture)
    {
        printf("Error: Failed to create texture\nSDL Error: '%s'\n", SDL_GetError());
        return;
    }

    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);
}

void Text::render(SDL_Renderer* renderer, SDL_FPoint position)
{
    if (!texture)
        return;

    SDL_Rect srcrect = { 0, 0, (int)rect.w, (int)rect.h };

    rect.x = position.x;
    rect.y = position.y;

    SDL_RenderCopyF(renderer, texture, &srcrect, &rect);
}
