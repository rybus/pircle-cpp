#include "prime.h"

void drawSpiralLogarithm(SDL_Renderer *renderer, int const windowLength, double a)
{
    SDL_Point center = {
        windowLength / 2,
        windowLength / 2
    };

    int x(0), y(0);
    double thetaRad(.0);
    double phi = (1 + sqrt(5)) / 2;
    double b = log(phi) / (M_PI / 2);
    SDL_Color yellow = {255, 255, 0};

    for (thetaRad = 0; x < 15000; thetaRad = thetaRad + (M_PI / 180))
    {
        x = exp(log(a) * b * thetaRad / 10) * cos(thetaRad);
        y = exp(log(a) * b * thetaRad / 10) * sin(thetaRad);

        SDL_SetRenderDrawColor(renderer, yellow.r, yellow.g, yellow.b, yellow.a);
        SDL_RenderDrawPoint(renderer, x / 20 + center.x, y / 20 + center.y);
    }
}

void drawPrimesOnSpiral(SDL_Renderer *renderer, int const windowLength, int expectedNumberOfPrimes)
{
    SDL_Color red = {255, 0, 55};
    SDL_Color blue = {0, 0, 255};
    double angle, radius;
    int displayedPrimeNumbers = 0;
    int previousPrime = 0;

    SDL_Point center = {
        windowLength / 2,
        windowLength / 2
    };

    std::vector<int> primeList = getPrimes(expectedNumberOfPrimes);
    if (primeList.size() < (unsigned) expectedNumberOfPrimes)
    {
        std::cout << "not enough primes found in the file, " << expectedNumberOfPrimes << "required, ";
        std::cout << primeList.size() << " provided." << std::endl;
    }

    std::vector<int>::iterator primeNumber = primeList.begin();
    while (displayedPrimeNumbers < expectedNumberOfPrimes && primeNumber != primeList.end())
    {
        angle = (*primeNumber * 2 * M_PI) / (expectedNumberOfPrimes);
        radius = (displayedPrimeNumbers*windowLength)/expectedNumberOfPrimes;

        drawPointOnCircle(renderer, center, angle, radius, red);

        displayedPrimeNumbers++;
        if (displayedPrimeNumbers < expectedNumberOfPrimes)
        {   
            previousPrime = *primeNumber;
            ++primeNumber;
        }
    }
}

bool isPythagorianPrimeNumber(int number)
{
    return (number - 1) % 8 == 0;
}

void drawUlamSpiral(SDL_Renderer *renderer, int const windowLength, int expectedNumberOfPrimes)
{
    SDL_Color red = {255, 0, 55};
    int X(windowLength/2), Y(windowLength/2);
    int x(0), y(0), i(0);
    int ample = 1;
    int number = 1;
    int XRepartition[windowLength];
    int YRepartition[windowLength];

    int displayedPrimeNumbers = 0;

    SDL_Point center = {
        windowLength / 2,
        windowLength / 2
    };

    std::vector<int> primeList = getPrimes(expectedNumberOfPrimes);
    if (primeList.size() < (unsigned) expectedNumberOfPrimes)
    {
        std::cout << "not enough primes found in the file, " << expectedNumberOfPrimes << "required, ";
        std::cout << primeList.size() << " provided." << std::endl;
    }

    for (i = 0; i < windowLength; i++) {
        XRepartition[i] = 0;
        YRepartition[i] = 0;
    }

    std::vector<int>::iterator primeNumber = primeList.begin();
    while (abs(x) < X  && abs(y) < Y && displayedPrimeNumbers <= expectedNumberOfPrimes && primeNumber != primeList.end()) {
        while (x <= ample) {
            if (number == *primeNumber) {
                drawPointOnPlan(renderer, center, x, y, red);
                XRepartition[x + windowLength/2]++;
                YRepartition[y + windowLength/2]++;
                displayedPrimeNumbers++;
                ++primeNumber;
            }
            x++;
            number++;
        }

        while (y <= ample) {
            if (number == *primeNumber) {
                drawPointOnPlan(renderer, center, x, y, red);
                XRepartition[x + windowLength/2]++;
                YRepartition[y + windowLength/2]++;
                displayedPrimeNumbers++;
                ++primeNumber;
            }
            y++;
            number++;
        }

        while (x >= -ample) {
            if (number == *primeNumber) {
                drawPointOnPlan(renderer, center, x, y, red);
                XRepartition[x + windowLength/2]++;
                YRepartition[y + windowLength/2]++;
                displayedPrimeNumbers++;
                ++primeNumber;
            }
            x--;
            number++;
        }

        while (y >= -ample) {
            if (number == *primeNumber) {
                drawPointOnPlan(renderer, center, x, y, red);
                XRepartition[x + windowLength/2]++;
                YRepartition[y + windowLength/2]++;
                displayedPrimeNumbers++;
                ++primeNumber;
            }
            y--;
            number++;
        }
        ample++;
    }

    drawXRepartition(renderer, XRepartition, windowLength);
    drawYRepartition(renderer, YRepartition, windowLength);
}

void drawXRepartition(SDL_Renderer *renderer, int repartitionX[], int windowLength)
{
    int i(0), j(0);
    SDL_Color color = {0, 153, 51};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (i = 0; i < windowLength; i++) 
    {
        for (j = windowLength; j > windowLength - repartitionX[i]; j--) 
        {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}

void drawYRepartition(SDL_Renderer *renderer, int repartitionY[], int windowLength)
{
    int i(0), j(0);
    SDL_Color color = {153, 0, 153};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (i = 0; i < windowLength; i++) 
    {
        for (j = windowLength; j > windowLength - repartitionY[i]; j--) 
        {
            SDL_RenderDrawPoint(renderer, i, j);
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

void drawPointOnPlan(SDL_Renderer *renderer, SDL_Point center, int x, int y, SDL_Color color, bool makePointBig)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

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
