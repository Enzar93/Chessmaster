#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"

static void reset_target(t_map **map)
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
					map[i][j].chessman->move = &move_rook;
				}
				if (j == 1 || j == 6) {
					map[i][j].chessman->type = KNIGHT;
                    map[i][j].chessman->move = &move_knight;
                }
				if (j == 2 || j == 5) {
					map[i][j].chessman->type = BIGSHOP;
                    map[i][j].chessman->move = &move_bigshop;
                }
				if (j == 3) {
					map[i][j].chessman->type = KING;
                    map[i][j].chessman->move = &move_king;
                }
				if (j == 4) {
					map[i][j].chessman->type = QUEEN;
                    map[i][j].chessman->move = &move_queen;
                }
				if (i == 1 || i == 6) {
					map[i][j].chessman->type = PAWN;
                    map[i][j].chessman->move = &move_pawn;
                }
				map[i][j].is_empty = false;
			}
		}
	}
}

static void move_chessman(int x, int y, t_map **map)
{

}

static void which_chessman(int x, int y, t_map **map)
{
    size_t chessposx = 0;
    size_t chessposy = 0;
    static int old_chessposx = -1;
    static int old_chessposy = -1;

    for (int starty = 560; starty + 100 < x; starty += 100)
        chessposy += 1;
    for (int startx = 140; startx + 100 < y; startx += 100)
        chessposx += 1;
    if (!map[chessposx][chessposy].is_empty && map[chessposx][chessposy].chessman->color == BLACK) {
        reset_target(map);
        map[chessposx][chessposy].chessman->move(map, chessposx, chessposy);
        old_chessposx = chessposx;
        old_chessposy = chessposy;
    }
    else if ((map[chessposx][chessposy].target == RED ||\
    map[chessposx][chessposy].target == GREEN) && old_chessposx != -1) {
        map[chessposx][chessposy].chessman = map[old_chessposx][old_chessposy].chessman;
        map[chessposx][chessposy].is_empty = false;
        map[old_chessposx][old_chessposy].is_empty = true;
        map[old_chessposx][old_chessposy].chessman = NULL;
        old_chessposx = -1;
        old_chessposy = -1;
        reset_target(map);
    }
    else
    {
        old_chessposx = -1;
        old_chessposy = -1;
        reset_target(map);
    }
    DrawChessBoard(map);
    fprintf(stderr, "%lu %lu\n", chessposx, chessposy);
}

static void display_map(t_map **map)
{

    for(size_t i = 0; i < 8; i++)
    {

        for(size_t j = 0; j < 8; j++)
        {
            if (map[i][j].is_empty)
                printf("*");
            else {
                if (map[i][j].chessman->type == PAWN)
                    printf("P");
                if (map[i][j].chessman->type == KING)
                    printf("K");
                if (map[i][j].chessman->type == ROOK)
                    printf("T");
                if (map[i][j].chessman->type == QUEEN)
                    printf("Q");
                if (map[i][j].chessman->type == KNIGHT)
                    printf("L");
                if (map[i][j].chessman->type == BIGSHOP)

                    printf("F");
            }
        }
        printf("\n");

    }

}

static void display_target(t_map **map)
{
    for(size_t i = 0; i < 8; i++)
    {

        for(size_t j = 0; j < 8; j++)
        {
            if (map[i][j].target == RED)
                printf("R");
            else if (map[i][j].target == GREEN)
                printf("G");
            else
                printf("N");
        }
        printf("\n");
    }
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

int lunch_chessgame()
{
    t_map **map = init_map();
    int quit = 0;

    put_chessman(map);
    display_map(map);
    init_screen();
    load_images(map);
    printf("\n");
    display_target(map);
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
        DrawChessBoard(map);
    }
    SDL_Quit();
    return 0;
}