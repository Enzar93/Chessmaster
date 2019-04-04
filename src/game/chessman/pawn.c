#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "rook.h"
#include "chessmaster.h"

static void swap(t_map *case1, t_map *case2)
{
    t_map block;

    block = *case2;
    *case2 = *case1;
    *case1 = block;
}

static void display(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
            if (!map[i][j].is_empty)
			    printf("[%d]", map[i][j].chessman->type);
            else
                printf("[ ]");
		}
        printf("\n");
	}
}

void move_pawn(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;

    if (x - 1 >= 0 && y - 1 >= 0 && !(map[x - 1][y - 1].is_empty) && map[x - 1][y - 1].chessman->color != color)
    {
        swap(&map[x][y], &map[x - 1][y - 1]);
        map[x][y].is_empty = true;
        if (!is_mat(map, color))
            map[x][y].target = RED;
        map[x][y].is_empty = false;
        swap(&map[x][y], &map[x - 1][y - 1]);
    }
    if (x - 1 >= 0 && y + 1 < 8 && !(map[x - 1][y + 1].is_empty) && map[x - 1][y + 1].chessman->color != color)
    {
        swap(&map[x][y], &map[x - 1][y + 1]);
        map[x][y].is_empty = true;
        if (!is_mat(map, color))
            map[x][y].target = RED;
        map[x][y].is_empty = false;
        swap(&map[x][y], &map[x - 1][y + 1]);
    }
    if (x + 1 < 8 && y - 1 >= 0 && !(map[x + 1][y - 1].is_empty) && map[x + 1][y - 1].chessman->color != color)
    {
        swap(&map[x][y], &map[x + 1][y - 1]);
        map[x][y].is_empty = true;
        if (!is_mat(map, color))
            map[x][y].target = RED;
        map[x][y].is_empty = false;
        swap(&map[x][y], &map[x + 1][y - 1]);
    }
    if (x + 1 < 8 && y + 1 < 8 && !(map[x + 1][y + 1].is_empty) && map[x + 1][y + 1].chessman->color != color)
    {
        swap(&map[x][y], &map[x + 1][y + 1]);
        map[x][y].is_empty = true;
        if (!is_mat(map, color))
            map[x][y].target = RED;
        map[x][y].is_empty = false;
        swap(&map[x][y], &map[x + 1][y + 1]);
    }
    if (color == BLACK)
    {
        if (x + 1 < 8 && map[x + 1][y].is_empty) {
            swap(&map[x][y], &map[x + 1][y]);
            if (!is_mat(map, color))
                map[x][y].target = GREEN;
            swap(&map[x][y], &map[x + 1][y]);
            if (x == 1 && map[x + 2][y].is_empty) {
                swap(&map[x][y], &map[x + 2][y]);
                if (!is_mat(map, color))
                    map[x][y].target = GREEN;
                swap(&map[x][y], &map[x + 2][y]);
            }
        }
    }
    else
    {
        if (x - 1 >= 0 && map[x - 1][y].is_empty) {
            swap(&map[x][y], &map[x - 1][y]);
            if (!is_mat(map, color))
                map[x][y].target = GREEN;
            swap(&map[x][y], &map[x - 1][y]);
            if (x == 6 && map[x - 2][y].is_empty) {
                swap(&map[x][y], &map[x - 2][y]);
                if (!is_mat(map, color))
                    map[x][y].target = GREEN;
                swap(&map[x][y], &map[x - 2][y]);
            }
        }
    }
}
