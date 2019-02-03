#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"


void move_pawn(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;

    if (x - 1 > 0 && y - 1 >= 0 && map[x][y].chessman->color == BLACK) {
        if (map[x][y - 1].is_empty)
            map[x][y - 1].target = GREEN;
    }
    if (x - 1 >= 0 && y + 1 < 8 && map[x][y].chessman->color == WHITE) {
        if (map[x][y + 1].is_empty)
            map[x][y + 1].target = GREEN;
    }
    if (x + 1 >= 0 && y + 1 < 8 && map[x][y].chessman->color == BLACK) {
        if (!map[x + 1][y + 1].is_empty)
            map[x + 1][y + 1].target = (map[x + 1][y + 1].chessman->color != color) ? RED : GREEN;
    }
    if (x - 1 >= 0 && y + 1 < 8 && map[x][y].chessman->color == WHITE) {
        if (!map[x + 1][y - 1].is_empty)
            map[x + 1][y - 1].target = (map[x + 1][y - 1].chessman->color != color) ? RED : GREEN;
    }
}
