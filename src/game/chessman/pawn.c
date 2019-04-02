#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "rook.h"
#include "chessmaster.h"

void move_pawn(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;

    if (x - 1 >= 0 && y - 1 >= 0 && !(map[x - 1][y - 1].is_empty) && map[x - 1][y - 1].chessman->color != color)
        map[x - 1][y - 1].target = RED;
    if (x - 1 >= 0 && y + 1 < 8 && !(map[x - 1][y + 1].is_empty) && map[x - 1][y + 1].chessman->color != color)
        map[x - 1][y + 1].target = RED;
    if (x + 1 < 8 && y - 1 >= 0 && !(map[x + 1][y - 1].is_empty) && map[x + 1][y - 1].chessman->color != color)
        map[x + 1][y - 1].target = RED;
    if (x + 1 < 8 && y + 1 < 8 && !(map[x + 1][y + 1].is_empty) && map[x + 1][y + 1].chessman->color != color)
        map[x + 1][y + 1].target = RED;
    if (color == BLACK)
    {
        if (x + 1 < 8 && map[x + 1][y].is_empty) {
            map[x + 1][y].target = GREEN;
            if (x == 1 && map[x + 2][y].is_empty)
                map[x + 2][y].target = GREEN;
        }
    }
    else
    {
        if (x - 1 >= 0 && map[x - 1][y].is_empty) {
            map[x - 1][y].target = GREEN;
            if (x == 6 && map[x - 2][y].is_empty)
                map[x - 2][y].target = GREEN;
        }
    }
}
