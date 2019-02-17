#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"

void put_chessman(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j].color = (i % 2 == 0) ? BLACK : WHITE;
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

t_map **init_map()
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
    while (quit == 0)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        while(SDL_PollEvent(&event)) {
            if ( event.key.keysym.sym == SDLK_ESCAPE )
                quit = true;
            if (event.type == SDL_QUIT ||
                    (event.type == SDL_WINDOWEVENT &&
                        event.window.event == SDL_WINDOWEVENT_CLOSE))
                        quit = true;
        }
        DrawChessBoard(renderer, map);
        SDL_Delay(2000);
    }
    SDL_Quit();
    return (0);
}


// map[1][0].is_empty = 1;
    // map[1][3].is_empty = 1;
    // map[1][4].is_empty = 1;
    // map[1][1].is_empty = 1;
    // printf("\n\n");

    // display_map(map);
    // //map[0][2].chessman->move(map, 0, 2);
    // map[0][3].chessman->move(map, 0, 3);
    // map[1][2].chessman->move(map, 1, 2);
    // printf("\n\n");
    // display_target(map);
    // display_chessmaster();