#ifndef ROOK_H_
#define ROOK_H_

#include "chessmaster.h"

void swap(t_map *case1, t_map *case2);

void move_rook(t_map **map, int x, int y);
void move_bigshop(t_map **map, int x, int y);
void move_queen(t_map **map, int x, int y);
void move_king(t_map **map, int x, int y);
void move_knight(t_map **map, int x, int y);
void move_pawn(t_map **map, int x, int y);


#endif
