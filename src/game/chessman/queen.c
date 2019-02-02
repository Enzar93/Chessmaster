#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"
#include "rook.h"

void move_queen(t_map **map, int x, int y)
{
    move_rook(map, x, y);
    move_bigshop(map, x, y);
}
