#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "chessmaster.h"

struct s_rect
{
	int x;
	int y;
	int w;
	int h;
};
typedef struct s_rect t_rect;

void
load_images(t_map **map);
void init_screen();
void DrawChessBoard(t_map **map);
void pawn_transformation(t_chessman *pawn);
void draw_text(const char *content, t_rect rect, int fontSize);

#endif /* !DISPLAY_H_*/
