#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"

// bool check_mat(t_map **map, enum e_color color)
// {
//     for(size_t i = 0; i < 8; i++)
//     {
//         for(size_t j = 0; j < 8; j++)
//         {
//             if (!map[i][j].is_empty() && map[i][j].chessman->color != color)
//             {
//             }
//         }
//     }
    
// }

void move_chessman(int chessposx, int chessposy, t_map **map)
{
    static int old_chessposy = -1;
    static int old_chessposx = -1;

    if (!map[chessposx][chessposy].is_empty && map[chessposx][chessposy].chessman->color == BLACK) {
        reset_target(map);
        map[chessposx][chessposy].chessman->move(map, chessposx, chessposy);
        old_chessposx = chessposx;
        old_chessposy = chessposy;
    }
    else if ((map[chessposx][chessposy].target == RED ||\
    map[chessposx][chessposy].target == GREEN) && old_chessposx != -1) {
        map[chessposx][chessposy].chessman = map[old_chessposx][old_chessposy].chessman;
        map[chessposx][chessposy].is_empty = false;
        map[old_chessposx][old_chessposy].is_empty = true;
        map[old_chessposx][old_chessposy].chessman = NULL;
        reset_target(map);
        DrawChessBoard(map);
        if (map[chessposx][chessposy].chessman->type == PAWN && chessposx == 7)
            pawn_transformation(map[chessposx][chessposy].chessman);
        old_chessposx = -1;
        old_chessposy = -1;
        DrawChessBoard(map);
    }
    else
    {
        old_chessposx = -1;
        old_chessposy = -1;
        reset_target(map);
    }
}