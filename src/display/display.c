#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <SDL2/SDL.h>
#include "chessmaster.h"
#include "display.h"

void DrawChessBoard(SDL_Renderer *renderer, t_map **map)
{
    size_t posx = 0;
    size_t posy = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (!map[i][j].is_empty && map[i][j].color == BLACK)
            {
                SDL_Rect rect = {posx, posy, 280, 120};
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_RenderPresent(renderer);
                fprintf(stderr, "eeee");
            }
            posx += 240;
        }
        posy += 180;
    }
}

void init_screen()
{
     /* Initialisation simple */
SDL_Renderer *renderer;
     if(SDL_Init(SDL_INIT_VIDEO) == -1)
        errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
    /* Création de la fenêtre */
    pWindow = SDL_CreateWindow(
        "Chessmaster",                     // window title
        SDL_WINDOWPOS_CENTERED,           // initial x position
        SDL_WINDOWPOS_CENTERED,           // initial y position
        1920,                               // width, in pixels
        1080,                               // height, in pixels
        0
    );
    if (pWindow == NULL)
        errx(84, "Could not create window: %s\n", SDL_GetError());
    renderer =  SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent( renderer);
    SDL_Delay(5000);
}


