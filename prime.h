#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
#include "store.h"

void drawPointOnCircle(SDL_Renderer *renderer, SDL_Point center, double radian, double radius, SDL_Color color, bool makePointBig = false);
void drawPointOnPlan(SDL_Renderer *renderer, SDL_Point center, int x, int y, SDL_Color color, bool makePointBig = false);
void drawPrimesOnSpiral(SDL_Renderer *renderer, int windowLength, int numberOfPrimes);
void drawSpiralLogarithm(SDL_Renderer* renderer,  int windowLength, double a);
void drawUlamSpiral(SDL_Renderer *renderer, int windowLength, int expectedNumberOfPrimes);