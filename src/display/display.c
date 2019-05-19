#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"

SDL_Window *pWindow;
SDL_Renderer *renderer;
SDL_Surface *surface;
SDL_Surface *promotion;

void load_images(t_map **map)
{
	SDL_Surface *black_king = IMG_Load("src/display/img/black_queen.png");
	SDL_Surface *white_king = IMG_Load("src/display/img/white_queen.png");
	SDL_Surface *black_pawn = IMG_Load("src/display/img/black_pawn.png");
	SDL_Surface *white_pawn = IMG_Load("src/display/img/white_pawn.png");
	SDL_Surface *black_queen = IMG_Load("src/display/img/black_king.png");
	SDL_Surface *white_queen = IMG_Load("src/display/img/white_king.png");
	SDL_Surface *black_rook = IMG_Load("src/display/img/black_rook.png");
	SDL_Surface *white_rook = IMG_Load("src/display/img/white_rook.png");
	SDL_Surface *black_bigshop = IMG_Load("src/display/img/black_bigshop.png");
	SDL_Surface *white_bigshop = IMG_Load("src/display/img/white_bigshop.png");
	SDL_Surface *black_knight = IMG_Load("src/display/img/black_knight.png");
	SDL_Surface *white_knight = IMG_Load("src/display/img/white_knight.png");
	promotion = IMG_Load("src/display/img/promotion.png");
	if (!black_king || !white_king || !black_pawn || !white_pawn || !black_queen ||
		!white_queen || !black_rook || !white_rook || !black_bigshop || !white_bigshop || !black_knight || !white_knight)
	{
		printf("Error loading image : %s", SDL_GetError());
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
				else if (map[i][j].chessman->type == KNIGHT && map[i][j].chessman->color == BLACK)
					map[i][j].chessman->image = black_knight;
				else if (map[i][j].chessman->type == KNIGHT && map[i][j].chessman->color == WHITE)
					map[i][j].chessman->image = white_knight;
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

void pawn_transformation(t_chessman *pawn)
{
	int quit = 0;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, promotion);
	SDL_Rect rect = {100, 100, 300, 600};
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(pWindow);
	while (quit == 0)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		while (SDL_PollEvent(&event))
		{
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_1:
				pawn->type = QUEEN;
				pawn->move = &move_queen;
				pawn->image = IMG_Load("src/display/img/black_queen.png");
				quit = 1;
				break;
			case SDL_SCANCODE_2:
				pawn->type = ROOK;
				pawn->move = &move_rook;
				pawn->image = IMG_Load("src/display/img/black_rook.png");
				quit = 1;
				break;
			case SDL_SCANCODE_3:
				pawn->type = BIGSHOP;
				pawn->move = &move_bigshop;
				pawn->image = IMG_Load("src/display/img/black_bigshop.png");
				quit = 1;
				break;
			case SDL_SCANCODE_4:
				pawn->type = KNIGHT;
				pawn->move = &move_knight;
				pawn->image = IMG_Load("src/display/img/black_knight.png");
				quit = 1;
				break;
			default:
				continue;
			}
		}
		SDL_Delay(500);
	}
	SDL_DestroyTexture(texture);
	SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
	SDL_RenderClear(renderer);
}

void DrawChessBoard(t_map **map)
{
	size_t posx = 560;
	size_t posy = 160;
	SDL_Texture *texture;
	SDL_Rect rect;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			rect.x = posx;
			rect.y = posy;
			rect.w = 100;
			rect.h = 100;
			if (map[i][j].color == BLACK)
				SDL_SetRenderDrawColor(renderer, 185, 93, 41, 255);
			else
				SDL_SetRenderDrawColor(renderer, 252, 246, 181, 255);
			SDL_RenderFillRect(renderer, &rect);
			if (map[i][j].target == RED)
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 90);
			if (map[i][j].target == GREEN)
				SDL_SetRenderDrawColor(renderer, 0, 128, 0, 150);
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			SDL_RenderFillRect(renderer, &rect);
			if (!map[i][j].is_empty)
			{
				rect.x = posx;
				rect.y = posy;
				rect.w = 100;
				rect.h = 100;
				texture = SDL_CreateTextureFromSurface(renderer, map[i][j].chessman->image);
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
			SDL_RenderPresent(renderer);
			posx += 100;
		}
		posy += 100;
		posx = 560;
	}
	SDL_UpdateWindowSurface(pWindow);
}

static void attach_texture(TTF_Font *font, const char *content, SDL_Color color, SDL_Rect rect)
{
	SDL_Surface *surfaceMessage = TTF_RenderText_Solid(font, content, color);
	SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect Message_rect = {.x = rect.x, .y = rect.y, .w = rect.w, .h = rect.h};
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(pWindow);
}

void draw_text(const char *content, SDL_Rect rect, int fontSize)
{
	TTF_Font *font = TTF_OpenFont("src/display/font/ARCADEPI.TTF", fontSize);
	SDL_Color White = {.r = 255, .g = 255, .b = 255};
	const char *fake = "";

	if (!font)
	{
		errx(1, "TTF_OpenFont: %s\n", TTF_GetError());
		return;
	}
	SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
	attach_texture(font, content, White, rect);
}

void init_screen()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		errx(1, "Could not initialize SDL: %s.\n", SDL_GetError());
	if (TTF_Init() == -1)
		errx(1, "TTF_Init: %s\n", TTF_GetError());

	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow(
		"Chessmaster",			// window title
		SDL_WINDOWPOS_CENTERED, // initial x position
		SDL_WINDOWPOS_CENTERED, // initial y position
		1920,					// width, in pixels
		1080,					// height, in pixels
		0);
	if (pWindow == NULL)
		errx(84, "Could not create window: %s\n", SDL_GetError());
	surface = SDL_GetWindowSurface(pWindow);
	renderer = SDL_CreateSoftwareRenderer(surface);
	if (renderer == NULL)
		exit(84);
	SDL_SetRenderDrawColor(renderer, 255, 69, 0, 255);
	SDL_RenderClear(renderer);
	SDL_UpdateWindowSurface(pWindow);
}
