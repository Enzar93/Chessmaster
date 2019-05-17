#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"

void reset_target(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j].target = NONE;
		}
	}
}

static void put_chessman(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
            if (i % 2 == 0)
			    map[i][j].color = (j % 2 == 0) ? BLACK : WHITE;
            else
			    map[i][j].color = (j % 2 == 0) ? WHITE : BLACK;
            map[i][j].target = NONE;
			map[i][j].is_empty = true;
			if (i == 0 || i == 7 || i == 1 || i == 6)
			{
				map[i][j].chessman = malloc(sizeof(t_chessman));
				if (map[i][j].chessman == NULL)
					errx(84, "chessmaster: allocation error\n");
				map[i][j].chessman->color = (i == 0 || i == 1) ? BLACK : WHITE;
				if (j == 0 || j == 7) {
					map[i][j].chessman->type = ROOK;
                    map[i][j].chessman->cost = 50;
					map[i][j].chessman->move = &move_rook;
				}
				if (j == 1 || j == 6) {
					map[i][j].chessman->type = KNIGHT;
                    map[i][j].chessman->cost = 30;
                    map[i][j].chessman->move = &move_knight;
                }
				if (j == 2 || j == 5) {
					map[i][j].chessman->type = BIGSHOP;
                    map[i][j].chessman->cost = 30;
                    map[i][j].chessman->move = &move_bigshop;
                }
				if (j == 3) {
					map[i][j].chessman->type = QUEEN;
                    map[i][j].chessman->cost = 90;
                    map[i][j].chessman->move = &move_queen;
                }
				if (j == 4) {
					map[i][j].chessman->type = KING;
                    map[i][j].chessman->cost = 900;
                    map[i][j].chessman->move = &move_king;
                }
				if (i == 1 || i == 6) {
					map[i][j].chessman->type = PAWN;
                    map[i][j].chessman->cost = 10;
                    map[i][j].chessman->move = &move_pawn;
                }
				map[i][j].is_empty = false;
			}
		}
	}
}

static void which_chessman(int x, int y, t_map **map)
{
    size_t chessposx = 0;
    size_t chessposy = 0;

    for (int starty = 560; starty + 100 < x; starty += 100)
        chessposy += 1;
    for (int startx = 140; startx + 100 < y; startx += 100)
        chessposx += 1;
    if (move_chessman(chessposx, chessposy, map) && map[0][0].player2 == false)
        ai_turn(map);
    DrawChessBoard(map);
}

static t_map **init_map()
{
    t_map **map = malloc(sizeof(t_map *) * 8);

    if (map == NULL)
        errx(84, "chessmaster: allocation error\n");
    for (size_t i = 0; i < 8; i++)
    {
        map[i] = malloc(sizeof(t_map) * 8);
        if (map[i] == NULL)
            errx(84, "chessmaster: allocation error\n");
    }
    return map;
}

int lunch_chessgame(bool player2)
{
    t_map **map = init_map();
    map[0][0].player2 = player2;
    int quit = 0;

    put_chessman(map);
    init_screen();
    load_images(map);
    DrawChessBoard(map);
    while (quit == 0)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        while (SDL_PollEvent(&event)) {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                quit = true;
            if (event.type == SDL_QUIT ||
                    (event.type == SDL_WINDOWEVENT &&
                        event.window.event == SDL_WINDOWEVENT_CLOSE))
                        quit = true;
            if (event.type == SDL_MOUSEBUTTONDOWN)
                which_chessman(event.button.x, event.button.y, map);
        }
        SDL_Delay(500);
    }
    SDL_Quit();
    return 0;
}