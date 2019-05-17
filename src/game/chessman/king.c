#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"

void move_king(t_map **map, int x, int y)
{
    enum e_color color = map[x][y].chessman->color;
    bool stock;

    if (x + 1 < 8 && map[x + 1][y].target != RED) {
        swap(&map[x][y], &map[x + 1][y]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 1][y]);
    }
    if (x - 1 >= 0) {
        swap(&map[x][y], &map[x - 1][y]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 1][y]);
    }
    if (y - 1 >= 0) {
        swap(&map[x][y], &map[x][y - 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x][y - 1]);
    }
    if (y + 1 < 8) {
        swap(&map[x][y], &map[x][y + 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x][y + 1]);
    }

    if (x + 1 < 8 && y + 1 < 8 ) {
        swap(&map[x][y], &map[x + 1][y + 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 1][y + 1]);
    }
    if (x - 1 >= 0 && y + 1 < 8) {
        swap(&map[x][y], &map[x - 1][y + 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 1][y + 1]);
    }
    if (x - 1 >= 0 && y - 1 >= 0) {
        swap(&map[x][y], &map[x - 1][y - 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x - 1][y - 1]);
    }
    if (x + 1 < 8 && y - 1 >= 0) {
        swap(&map[x][y], &map[x + 1][y - 1]);
        stock = map[x][y].is_empty;
        map[x][y].is_empty = true;
        if (!is_mat(map, color)) {
            map[x][y].is_empty = stock;
            if (!map[x][y].is_empty && map[x][y].chessman->color != color && map[x][y].chessman->type != KING)
                map[x][y].target = RED;
            if (map[x][y].is_empty)
                map[x][y].target = GREEN;
        }
        map[x][y].is_empty = stock;
        swap(&map[x][y], &map[x + 1][y - 1]);
    }
}