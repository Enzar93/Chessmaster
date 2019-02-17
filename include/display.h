#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include "chessmaster.h"

SDL_Window *pWindow;
SDL_Renderer *renderer;
SDL_Surface *surface;

void init_screen();
void DrawChessBoard(SDL_Renderer *renderer, t_map **map);

#endif /* !DISPLAY_H_*/
