#include <iostream>
#include "sdl.h"
#include "draw.h"

extern int const windowLength;

SDL_Renderer* drawWindow()
{
    SDL_Point windowPosition = {
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED
    };
 
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;

        exit(EXIT_FAILURE);
    }

    SDL_Window *window = SDL_CreateWindow("Primes on a circle",  windowPosition.x,  windowPosition.y, windowLength, windowLength, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();

        exit(EXIT_FAILURE);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        
        exit(EXIT_FAILURE);
    }

    return renderer;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
        }
    }
}
