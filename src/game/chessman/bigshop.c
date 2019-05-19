#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"


void move_bigshop(t_map **map, int x, int y)
{
	enum e_color color = map[x][y].chessman->color;
	bool stock;
	bool stop = false;

	for (int i = x + 1, j = y + 1; j < 8 && i < 8 && stop == false; j++, i++)
	{
		swap(&map[x][y], &map[i][j]);
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
		swap(&map[x][y], &map[i][j]);
	}
	stop = false;
	for (int i = x - 1, j = y + 1; j < 8 && i >= 0 && stop == false; j++, i--)
	{
		swap(&map[x][y], &map[i][j]);
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
		swap(&map[x][y], &map[i][j]);
	}
	stop = false;
	for (int i = x + 1, j = y - 1; j >= 0 && i < 8 && stop == false; j--, i++)
	{
		swap(&map[x][y], &map[i][j]);
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
		swap(&map[x][y], &map[i][j]);
	}
	stop = false;
	for (int i = x - 1, j = y - 1; j >= 0 && i >= 0 && stop == false; j--, i--)
	{
		swap(&map[x][y], &map[i][j]);
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
		swap(&map[x][y], &map[i][j]);
	}
}
