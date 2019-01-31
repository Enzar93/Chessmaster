#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"
#include "rook.h"

void put_chessman(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			map[i][j].color = (i % 2 == 0) ? BLACK : WHITE;
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
				if (j == 1 || j == 6)
					map[i][j].chessman->type = KNIGHT;
				if (j == 2 || j == 5)
					map[i][j].chessman->type = BIGSHOP;
				if (j == 3)
					map[i][j].chessman->type = KING;
				if (j == 4)
					map[i][j].chessman->type = QUEEN;
				if (i == 1 || i == 6)
					map[i][j].chessman->type = PAWN;
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

    put_chessman(map);
    display_map(map);
    map[0][0].chessman->move(map, 0, 0);
    return (0);
}
