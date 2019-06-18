#include "draw.h"

using namespace std;

extern int const windowLength;

void drawCenteredPointOnPlan(SDL_Renderer *renderer, int x, int y, SDL_Color color, bool makePointBig)
{
    SDL_Point center = {
        windowLength / 2,
        windowLength / 2
    };

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

void drawPointOnPlan(SDL_Renderer *renderer, int x, int y, SDL_Color color, bool makePointBig)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    if (makePointBig) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++)
                SDL_RenderDrawPoint(renderer, x + i, y + j);
        }
       
    } else {
        SDL_RenderDrawPoint(renderer, x, y);
    }
}


void drawPointOnCircle(SDL_Renderer *renderer, double radian, double radius, SDL_Color color, bool makePointBig)
{
    double x, y;
    SDL_Point center = {
        windowLength / 2,
        windowLength / 2
    };
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    x = cos(radian) * radius;
    y = sin(radian) * radius;

    if (makePointBig) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++)
                SDL_RenderDrawPoint(renderer, x + center.x + i, y + center.y + j);
        }
       
    } else {
        SDL_RenderDrawPoint(renderer, x + center.x, y + center.y);
    }
}
