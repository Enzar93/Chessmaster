#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "rook.h"
#include "chessmaster.h"

void move_knight(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;
    bool stock;

    /* UP */
    if (x - 2 >= 0 && y - 1 >= 0) {
        swap(&map[x][y], &map[x - 2][y - 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty) {
                map[x][y].target = GREEN;
            }
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 2][y - 1]);
    }
    if (x - 2 >= 0 && y + 1 < 8) {
        swap(&map[x][y], &map[x - 2][y + 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 2][y + 1]);
    }

    /* RIGHT */
    if (x - 1 >= 0 && y + 2 < 8) {
        swap(&map[x][y], &map[x - 1][y + 2]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 1][y + 2]);
    }
    if (x + 1 < 8 && y + 2 < 8) {
        swap(&map[x][y], &map[x + 1][y + 2]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 1][y + 2]);
    }

    /* LEFT */
    if (x - 1 >= 0 && y - 2 >= 0) {
        swap(&map[x][y], &map[x - 1][y - 2]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 1][y - 2]);
    }
    if (x + 1 < 8 && y - 2 >= 0) {
        swap(&map[x][y], &map[x + 1][y - 2]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 1][y - 2]);
    }

    /* DOWN */
    if (x + 2 < 8 && y - 1 >= 0) {
        swap(&map[x][y], &map[x + 2][y - 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 2][y - 1]);
    }
    if (x + 2 < 8 && y + 1 < 8) {
        swap(&map[x][y], &map[x + 2][y + 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
            else
                map[x][y].target = (map[x][y].chessman->color != color && map[x][y].chessman->type != KING) ? RED : NONE;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 2][y + 1]);
    }
}