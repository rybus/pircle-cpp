#include <SDL2/SDL.h>
#include <math.h>
#include <iostream>
#include "store.h"

void drawPointOnCircle(SDL_Renderer *renderer, SDL_Point center, double radian, double radius, SDL_Color color, bool makePointBig = false);
void drawPrimesOnSpiral(SDL_Renderer *renderer, SDL_Point center, int window_length, int expected_number_of_primes);
void drawSpiralLogarithm(SDL_Renderer* renderer,  SDL_Point center, double a, int expected_number_of_primes);
