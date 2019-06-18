#include <SDL2/SDL.h>
#include <math.h>

const SDL_Color COLOR_RED = {255, 0, 55};
const SDL_Color COLOR_BLUE = {0, 0, 255};
const SDL_Color COLOR_YELLOW = {255, 255, 0};

void drawPointOnCircle(SDL_Renderer *renderer, double radian, double radius, SDL_Color color, bool makePointBig = false);
void drawCenteredPointOnPlan(SDL_Renderer *renderer, int x, int y, SDL_Color color, bool makePointBig = false);
void drawPointOnPlan(SDL_Renderer *renderer, int x, int y, SDL_Color color, bool makePointBig = false);
