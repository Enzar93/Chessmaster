#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "chessmaster.h"

void load_images(t_map **map);
void init_screen();
void DrawChessBoard(t_map **map);
void pawn_transformation(t_chessman *pawn);

#endif /* !DISPLAY_H_*/
