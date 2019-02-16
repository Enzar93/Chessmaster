#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include "display.h"


int done;

void DrawChessBoard(SDL_Renderer *renderer, t_map **map)
{
    SDL_Rect rect, darea;

    // Get the Size of drawing surface
    SDL_RenderGetViewport(renderer, &darea);
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
          SDL_SetRenderDrawColor(renderer, 10, 20, 30, 0);
          rect.w = darea.w/8;
          rect.h = darea.h/8;
          rect.x = j * rect.w;
          rect.y = i * rect.h;
          SDL_RenderFillRect(renderer, &rect);
        }
    }
  SDL_UpdateWindowSurface(pWindow);
}

void display_chessmaster()
{
    printf("1");
     /* Initialisation simple */
     if(SDL_Init(SDL_INIT_VIDEO) == -1)
        errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
    /* Création de la fenêtre */
    printf("1");
    pWindow = SDL_CreateWindow(
        "Chessmaster",                     // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1080,                               // width, in pixels
        720,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    printf("1");
    if (pWindow == NULL)
        errx(84, "Could not create window: %s\n", SDL_GetError());
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    printf("2");
}


