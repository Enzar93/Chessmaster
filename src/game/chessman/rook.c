#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"
#include "rook.h"

void move_rook(t_map **map, int x, int y)
{
	enum e_color color = map[x][y].chessman->color;
	bool stock;
	bool stop = false;

	for (int j = y + 1; j < 8 && stop == false; j++)
	{
		if (!map[x][j].is_empty && map[x][j].chessman->color == map[x][y].chessman->color)
			break;
        swap(&map[x][y], &map[x][j]);
        stock = map[x][y].is_empty;
		map[x][y].is_empty = true;
		if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
			if (!map[x][y].is_empty)
			{
				if (map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
					map[x][y].target = RED;
				stop = true;
			}
			else
				map[x][y].target = GREEN;
		}
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x][j]);
	}
	stop = false;
	for (int j = y - 1; j >= 0 && stop == false; j--)
	{
		if (!map[x][j].is_empty && map[x][j].chessman->color == map[x][y].chessman->color)
			break;
		swap(&map[x][y], &map[x][j]);
        stock = map[x][y].is_empty;
		map[x][y].is_empty = true;
		if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
			if (!map[x][y].is_empty)
			{
				if (map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
					map[x][y].target = RED;
				stop = true;
			}
			else
				map[x][y].target = GREEN;
		}
        map[x][y].is_empty = stock;
		swap(&map[x][y], &map[x][j]);
	}
	stop = false;
	for (int i = x + 1; i < 8 && stop == false; i++)
	{
		if (!map[i][y].is_empty && map[i][y].chessman->color == map[x][y].chessman->color)
			break;
		swap(&map[x][y], &map[i][y]);
        stock = map[x][y].is_empty;
		map[x][y].is_empty = true;
		if (!is_mat(map, color)) {
			map[x][y].is_empty = stock;
			if (!map[x][y].is_empty)
			{
				if (map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
					map[x][y].target = RED;
				stop = true;
			}
			else
				map[x][y].target = GREEN;
		}
        map[x][y].is_empty = stock;
		swap(&map[x][y], &map[i][y]);
	}
	stop = false;
	for (int i = x - 1; i >= 0 && stop == false; i--)
	{
		if (!map[i][y].is_empty && map[i][y].chessman->color == map[x][y].chessman->color)
			break;
		swap(&map[x][y], &map[i][y]);
        stock = map[x][y].is_empty;
		map[x][y].is_empty = true;
		if (!is_mat(map, color)) {
			map[x][y].is_empty = stock;
			if (!map[x][y].is_empty)
			{
				if (map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
					map[x][y].target = RED;
				stop = true;
			}
			else
				map[x][y].target = GREEN;
		}
        map[x][y].is_empty = stock;
		swap(&map[x][y], &map[i][y]);
	}
}
