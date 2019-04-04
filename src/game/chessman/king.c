#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"

void move_king(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;

    if (x + 1 < 8 && map[x + 1][y].target != RED) {
        if (!map[x + 1][y].is_empty && map[x + 1][y].chessman->color != color)
            map[x + 1][y].target = RED;
        if (map[x + 1][y].is_empty)
            map[x + 1][y].target = GREEN;
    }
    if (x - 1 >= 0) {
        if (!map[x - 1][y].is_empty && map[x - 1][y].chessman->color != color)
            map[x - 1][y].target = RED;
        if (map[x - 1][y].is_empty)
            map[x - 1][y].target = GREEN;
    }
    if (y - 1 >= 0) {
        if (!map[x][y - 1].is_empty && map[x][y - 1].chessman->color != color)
            map[x][y - 1].target = RED;
        if (map[x][y - 1].is_empty)
            map[x][y - 1].target = GREEN;
    }
    if (y + 1 < 8) {
        if (!map[x][y + 1].is_empty && map[x][y + 1].chessman->color != color)
            map[x][y + 1].target = RED;
        if (map[x][y + 1].is_empty)
            map[x][y + 1].target = GREEN;
    }

}