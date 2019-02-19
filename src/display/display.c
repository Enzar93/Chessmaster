#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "chessmaster.h"
#include "display.h"

SDL_Window *pWindow;
SDL_Renderer *renderer;
SDL_Surface *surface;

void load_images(t_map **map)
{
	SDL_Surface* black_king = IMG_Load("src/display/img/black_king.png");
	SDL_Surface* white_king = IMG_Load("src/display/img/white_king.png");
	SDL_Surface* black_pawn = IMG_Load("src/display/img/black_pawn.png");
	SDL_Surface* white_pawn = IMG_Load("src/display/img/white_pawn.png");
	SDL_Surface* black_queen = IMG_Load("src/display/img/black_queen.png");
	SDL_Surface* white_queen = IMG_Load("src/display/img/white_queen.png");
	SDL_Surface* black_rook = IMG_Load("src/display/img/black_rook.png");
	SDL_Surface* white_rook = IMG_Load("src/display/img/white_rook.png");
	SDL_Surface* black_bigshop = IMG_Load("src/display/img/black_bigshop.png");
	SDL_Surface* white_bigshop = IMG_Load("src/display/img/white_bigshop.png");
	SDL_Surface* black_knight = IMG_Load("src/display/img/black_knight.png");
	SDL_Surface* white_knight = IMG_Load("src/display/img/white_knight.png");
	if(!black_king || !white_king || !black_pawn || !white_pawn || !black_queen ||
	!white_queen || !black_rook || !white_rook || !black_bigshop || !white_bigshop || !black_knight || !white_knight)
	{
    	printf("Erreur de chargement de l'image : %s", SDL_GetError());
    	exit(84);
	}
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (!map[i][j].is_empty)
			{
				if (map[i][j].chessman->type == PAWN && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_pawn;
				else if (map[i][j].chessman->type == PAWN && map[i][j].chessman->color == WHITE)
					map[i][j].chessman->image = white_pawn;
				else if (map[i][j].chessman->type == KING && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_king;
				else if (map[i][j].chessman->type == KING && map[i][j].chessman->color == WHITE)
					map[i][j].chessman->image = white_king;
				else if (map[i][j].chessman->type == BIGSHOP && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_bigshop;
				else if (map[i][j].chessman->type == BIGSHOP && map[i][j].chessman->color == WHITE)
					map[i][j].chessman->image = white_bigshop;
				else if (map[i][j].chessman->type == QUEEN && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_queen;
				else if (map[i][j].chessman->type == QUEEN && map[i][j].chessman->color == WHITE)
					map[i][j].chessman->image = white_queen;
				else if (map[i][j].chessman->type == ROOK && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_rook;
				else if (map[i][j].chessman->type == ROOK && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_rook;
				else

					map[i][j].chessman->image = white_rook;
			}
		}
	}
}

void DrawChessBoard(t_map **map)
{
	size_t posx = 560;
	size_t posy = 140;
	SDL_Texture *texture;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			SDL_Rect rect = {posx, posy, 280, 120};
			if (map[i][j].color == BLACK)
				SDL_SetRenderDrawColor(renderer, 185, 93, 41, 255);
			else
				SDL_SetRenderDrawColor(renderer, 252, 246, 181, 255);
			SDL_RenderFillRect(renderer, &rect);
			if (!map[i][j].is_empty) {
				SDL_Rect dstrect = {posx, posy, 100, 100};
				texture = SDL_CreateTextureFromSurface(renderer, map[i][j].chessman->image);
				SDL_RenderCopy(renderer, texture, NULL, &dstrect);
			}
			SDL_RenderPresent(renderer);
			posx += 100;
		}
		posy += 100;
		posx = 560;
	}
	SDL_UpdateWindowSurface(pWindow);
}

void init_screen()
{
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
	surface = SDL_GetWindowSurface(pWindow);
  	renderer = SDL_CreateSoftwareRenderer(surface);
	if(renderer == NULL)
      exit(84);
	SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
	SDL_RenderClear(renderer);
	SDL_UpdateWindowSurface(pWindow);
}
