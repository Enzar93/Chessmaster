#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "chessmaster.h"

void load_images(t_map **map);
void init_screen();
void DrawChessBoard(t_map **map);
void pawn_transformation(t_chessman *pawn);
void draw_text(const char *content, SDL_Rect, int fontSize);

#endif /* !DISPLAY_H_*/
