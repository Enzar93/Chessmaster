#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

void check_knight(t_map **map)
{
    map[1][0].is_empty = 1;
    map[2][2] = map[6][0];
    map[0][1].chessman->move(map, 0, 1);
}

void check_pawn(t_map **map)
{
  map[1][0].chessman->move(map, 1, 1);
  map[2][1] = map[6][1];
}
