#include <iostream>
#include "prime.h"

using namespace std;

SDL_Renderer* drawWindow(int windowLength);
void pause();

int main(int argc, char** argv)
{
    int const windowLength(1000);

    int numberOfPrimes = 0, expensionFactor = 0;
    SDL_Renderer *window;

    if (argc == 3 && string(argv[1]) == "generate")
    {
        numberOfPrimes = stoi(argv[2]);

        generate(numberOfPrimes);

        exit(EXIT_SUCCESS);
    }
    if (argc == 4  && string(argv[1]).find("circle") != std::string::npos)
    {
        numberOfPrimes = stoi(argv[2]);
        expensionFactor = stod(argv[3]);

        window = drawWindow(windowLength);
        drawPrimesOnSpiral(window, windowLength, numberOfPrimes);
        if (string(argv[1]).find("logarithm") != std::string::npos) {
            drawSpiralLogarithm(window, windowLength, expensionFactor);
        }
       
        SDL_RenderPresent(window);
        pause();

        exit(EXIT_SUCCESS);
    }
    if (argc == 3  && string(argv[1]) == "ulma")
    {
        numberOfPrimes = stoi(argv[2]);

        window = drawWindow(windowLength);
        drawUlamSpiral(window, windowLength, numberOfPrimes);

        SDL_RenderPresent(window);
        pause();

        exit(EXIT_SUCCESS);
    }

    cout << "no enough argument provided: " << argc << " provided, 3 expected" << endl;

    exit(EXIT_FAILURE);
}

SDL_Renderer* drawWindow(int windowLength)
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

