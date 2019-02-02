#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"


void move_bigshop(t_map **map, int x, int y)
{
	enum e_color color = map[x][y].chessman->color;
	for (int i = x + 1, j = y + 1; j < 8 && i < 8; j++, i++)
	{
		if (!map[i][j].is_empty)
		{
			if (map[i][j].chessman->color != color)
			{
				map[i][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[i][j].target = GREEN;
	}
	for (int i = x - 1, j = y + 1; j < 8 && i > 0; j++, i--)
	{
		if (!map[i][j].is_empty)
		{
			if (map[i][j].chessman->color != color)
			{
				map[i][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[i][j].target = GREEN;
	}
	for (int i = x + 1, j = y - 1; j > 0 && i < 8; j--, i++)
	{
		if (map[i][j].is_empty == false)
		{
			if (map[i][j].chessman->color != color)
			{
				map[i][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[i][j].target = GREEN;
	}
	for (int i = x - 1, j = y - 1; j > 0 && i > 0; j--, i--)
	{
		if (!map[i][j].is_empty)
		{
			if (map[i][j].chessman->color != color)
			{
				map[i][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[i][j].target = GREEN;
	}
}
