#include <iostream>
#include "prime.h"

using namespace std;

#define WINDOW_LENGTH 1000
SDL_Renderer* drawWindow();
void pause();

int main(int argc, char** argv)
{
    //double expensionFactor;
    int numberOfPrimes = 0;
    SDL_Renderer *window;
    SDL_Point center = {
        WINDOW_LENGTH / 2,
        WINDOW_LENGTH / 2
    };

    if (argc == 3)
    {
        window = drawWindow();
        if (string(argv[1]) == "generate")
        {
            numberOfPrimes = stoi(argv[2]);
            
            generate(numberOfPrimes);

            return 0;
        }
        else
        {
            numberOfPrimes = stoi(argv[1]);
            //expensionFactor = stod(argv[2]);

            drawPrimesOnSpiral(window, center, WINDOW_LENGTH, numberOfPrimes);
        }

        SDL_RenderPresent(window);
        pause();

        exit(EXIT_SUCCESS);
    }

    cout << "no enough argument provided: " << argc << " provided, 3 expected" << endl;

    exit(EXIT_FAILURE);
}

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

    SDL_Window *window = SDL_CreateWindow("Primes on a circle",  windowPosition.x,  windowPosition.y, WINDOW_LENGTH, WINDOW_LENGTH, SDL_WINDOW_SHOWN);
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

