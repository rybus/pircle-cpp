#include <iostream>
#include <vector>

#include "prime.h"
#include "draw.h"

using namespace std;

extern int const windowLength;

void drawPrimesOnSquare(SDL_Renderer *renderer, vector<int> primeNumbers)
{
    int displayedPrimeNumbers = 0;
    int x = 0, y = 0;

    std::vector<int>::iterator primeNumber = primeNumbers.begin();

    while (primeNumber != primeNumbers.end())
    {
        x = (*primeNumber % 360);
        y = (*primeNumber / 360);

        drawPointOnPlan(renderer, x, y, COLOR_RED);

        displayedPrimeNumbers++;
        ++primeNumber;
    }
}
