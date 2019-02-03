#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"

void move_knight(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;

    /* UP */
    if (x - 1 > 0 && y - 1 >= 0) {
        if (map[x - 1][y - 1].is_empty)
            map[x - 1][y - 1].target = GREEN;
        else
            map[x - 1][y - 1].target = (map[x - 1][y - 1].chessman->color != color) ? RED : GREEN;
    }
    if (x - 1 >= 0 && y + 1 < 8) {
        if (map[x - 1][y + 1].is_empty)
            map[x - 1][y + 1].target = GREEN;
        else
            map[x - 1][y + 1].target = (map[x - 1][y + 1].chessman->color != color) ? RED : GREEN;
    }

    /* RIGHT */
    if (x - 1 >= 0 && y + 2 < 8) {
        if (map[x - 1][y + 2].is_empty)
            map[x - 1][y + 2].target = GREEN;
        else
            map[x - 1][y + 2].target = (map[x - 1][y + 2].chessman->color != color) ? RED : GREEN;
    }
    if (x + 1 < 8 && y + 2 < 8) {
        if (map[x + 1][y + 2].is_empty)
            map[x + 1][y + 2].target = GREEN;
        else
            map[x + 1][y + 2].target = (map[x + 1][y + 2].chessman->color != color) ? RED : GREEN;
    }

    /* LEFT */
    if (x - 1 > 0 && y - 2 >= 0) {
        if (map[x - 1][y - 2].is_empty)
            map[x - 1][y - 2].target = GREEN;
        else
            map[x - 1][y - 2].target = (map[x - 1][y - 2].chessman->color != color) ? RED : GREEN;
    }
    if (x + 1 < 8 && y - 2 > 0) {
        if (map[x + 1][y - 2].is_empty)
            map[x + 1][y - 2].target = GREEN;
        else
            map[x + 1][y - 2].target = (map[x + 1][y - 2].chessman->color != color) ? RED : GREEN;
    }

    /* DOWN */
    if (x + 2 < 8 && y - 1 >= 0) {
        if (map[x + 2][y - 1].is_empty)
            map[x + 2][y - 1].target = GREEN;
        else
            map[x + 2][y - 1].target = (map[x + 2][y - 1].chessman->color != color) ? RED : GREEN;
    }
    if (x + 2 < 8 && y + 1 < 8) {
        if (map[x + 2][y + 1].is_empty)
            map[x + 2][y + 1].target = GREEN;
        else
            map[x + 2][y + 1].target = (map[x + 2][y + 1].chessman->color != color) ? RED : GREEN;
    }
}