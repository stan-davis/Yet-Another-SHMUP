#include "core.h"

#include <SDL_image.h>
#include <cstdio>

int Core::run(int _window_width, int _window_height, int _frame_rate)
{
    window_width = _window_width;
    window_height = _window_height;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Error: SDL failed to initialize.\n '%s'\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Yet Another Shmup (YAS)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!window || !renderer)
    {
        printf("Error: Failed to create window or renderer.\n '%s'\n", SDL_GetError());
        return 1;
    }

    int img_flags = IMG_INIT_PNG;
    if (IMG_Init(img_flags) != img_flags)
    {
        printf("Error: IMG failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    time.set_target_frame_rate(_frame_rate);

    start();

    while (is_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_running = false;
                break;
            default:
                break;
            }
        }

        time.tick();
        SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255); //Blue
        SDL_RenderClear(renderer);

        //Tick core
        tick(time.get_delta_time());

        //Tick entities
        for (auto& entity : entities)
            entity->tick(time.get_delta_time());

        //Render entities
        for (auto& entity : entities)
        {
            if (entity->sprite)
                entity->sprite->render(renderer, entity->position, entity->rotation);
        }

        SDL_RenderPresent(renderer);
        time.late_tick();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}