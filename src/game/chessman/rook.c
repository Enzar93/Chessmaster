#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"



void move_rook(t_map **map, int x, int y)
{
	enum e_color color = map[x][y].chessman->color;
	printf("line :%d / col :%d\n", x, y);
	for (int j = y + 1; j < 8; j++)
	{
		if (!map[x][j].is_empty)
		{
			if (map[x][j].chessman->color != color)
			{
				map[x][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[x][j].target = GREEN;
	}
	for (int j = y - 1; j >= 0; j--)
	{
		if (!map[x][j].is_empty)
		{
			if (map[x][j].chessman->color != color)
			{
				map[x][j].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[x][j].target = GREEN;
	}
	for (int i = x + 1; i < 8; i++)
	{
		if (map[i][y].is_empty == false)
		{
			if (map[i][y].chessman->color != color)
			{
				map[i][y].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[i][y].target = GREEN;
	}
	for (int i = x - 1; i >= 0; i--)
	{
		if (!map[i][y].is_empty)
		{
			if (map[i][y].chessman->color != color)
			{
				map[i][y].target = RED;
				break;
			}
			else
				break;
		}
		else
			map[x][y].target = GREEN;
	}
}
