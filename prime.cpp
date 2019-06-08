#include "prime.h"

void drawSpiralLogarithm(SDL_Renderer *renderer, SDL_Point center, double a, int expectedNumberOfPrimes)
{
    int x = 0;
    int y = 0;
    double theta_rad = 0;
    double phi = (1 + sqrt(5)) / 2;
    double b = log(phi) / (M_PI / 2);
    SDL_Color yellow = {255, 255, 0};

    for (theta_rad = 0; x < 15000; theta_rad = theta_rad + M_PI / 180)
    {
        x = exp(a * b * theta_rad * 2) * cos(theta_rad);
        y = exp(a * b * theta_rad * 2) * sin(theta_rad);

        SDL_SetRenderDrawColor(renderer, yellow.r, yellow.g, yellow.b, yellow.a);
        SDL_RenderDrawPoint(renderer, x / 20 + center.x, y / 20 + center.y);
    }
}

void drawPrimesOnSpiral(SDL_Renderer *renderer, SDL_Point center, int window_length, int expectedNumberOfPrimes)
{
    SDL_Color red = {255, 0, 55};
    double angle, radius;
    int displayedPrimeNumbers = 0;

    std::vector<int> primeList = getPrimes(expectedNumberOfPrimes);
    if (primeList.size() < expectedNumberOfPrimes)
    {
        std::cout << "not enough primes found in the file, " << expectedNumberOfPrimes << "required, ";
        std::cout << primeList.size() << " provided." << std::endl;
    }

    std::vector<int>::iterator primeNumber = primeList.begin();
    while (displayedPrimeNumbers < expectedNumberOfPrimes && primeNumber != primeList.end())
    {
        std::cout << *primeNumber << std::endl;
        angle = (*primeNumber * 2 * M_PI) / (displayedPrimeNumbers - 1);
        radius = (displayedPrimeNumbers*window_length)/expectedNumberOfPrimes;

        drawPointOnCircle(renderer, center, angle, radius, red);

        displayedPrimeNumbers++;
        if (displayedPrimeNumbers < expectedNumberOfPrimes)
        {   
            ++primeNumber;
        }
    }
}

void drawPointOnCircle(SDL_Renderer *renderer, SDL_Point center, double radian, double radius, SDL_Color color, bool makePointBig)
{
    double x, y;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    x = cos(radian) * radius;
    y = sin(radian) * radius;

    if (makePointBig) {
        SDL_RenderDrawPoint(renderer, x + center.x, y + center.y);
        SDL_RenderDrawPoint(renderer, x + center.x + 1, y + center.y);
        SDL_RenderDrawPoint(renderer, x + center.x, y + center.y + 1);
        SDL_RenderDrawPoint(renderer, x + center.x - 1, y + center.y);
        SDL_RenderDrawPoint(renderer, x + center.x, y + center.y - 1);
    } else {
        SDL_RenderDrawPoint(renderer, x + center.x, y + center.y);
    }
}
