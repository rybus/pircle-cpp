#include <vector>

#include "draw.h"

extern int const windowLength;

void drawUlamSpiral(SDL_Renderer *renderer, std::vector<int>& primeNumbers)
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

   
    for (i = 0; i < windowLength; i++) {
        XRepartition[i] = 0;
        YRepartition[i] = 0;
    }

    std::vector<int>::iterator primeNumber = primeNumbers.begin();
    while (abs(x) < X  && abs(y) < Y && primeNumber != primeNumbers.end()) {
        while (x <= ample) {
            if (number == *primeNumber) {
                drawPointOnPlan(renderer, x, y, red);
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
                drawPointOnPlan(renderer, x, y, red);
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
                drawPointOnPlan(renderer, x, y, red);
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
                drawPointOnPlan(renderer, x, y, red);
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
}

