#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "chessmaster.h"
#include "rook.h"
#include "display.h"


bool check_mat2(t_map **map, int x, int y, enum e_color color)
{
    for(int i = x - 1; i >= 0; i--)
    {
        if (!map[i][y].is_empty && map[i][y].chessman->color == color)
            break;
        else if (!map[i][y].is_empty && map[i][y].chessman->color != color && (map[i][y].chessman->type == ROOK || 
        map[i][y].chessman->type == QUEEN || map[i][y].chessman->type == KING))
            return true;
        else if (map[x][i].is_empty)
            continue;
        else
            break;
    }
    for (int i = x + 1; i < 8; i++)
    {
        if (!map[i][y].is_empty && map[i][y].chessman->color == color)
            break;
        else if (!map[i][y].is_empty && map[i][y].chessman->color != color && (map[i][y].chessman->type == ROOK || 
        map[i][y].chessman->type == QUEEN || map[i][y].chessman->type == KING))
            return true;
        else if (map[x][i].is_empty)
            continue;
        else
            break;
    }
    for (int i = y - 1; i < 8; i++)
    {
        if (!map[x][i].is_empty && map[x][i].chessman->color == color)
            break;
        else if (!map[x][i].is_empty && map[x][i].chessman->color != color && (map[x][i].chessman->type == ROOK ||
        map[x][i].chessman->type == QUEEN || map[x][i].chessman->type == KING))
            return true;
        else if (map[x][i].is_empty)
            continue;
        else
            break;
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (!map[x][i].is_empty && map[x][i].chessman->color == color)
            break;
        else if (!map[x][i].is_empty && map[x][i].chessman->color != color && (map[x][i].chessman->type == ROOK ||
        map[x][i].chessman->type == QUEEN || map[x][i].chessman->type == KING))
            return true;
        else if (map[x][i].is_empty)
            continue;
        else
            break;
    }

    // DIAGONAL
    if (color == BLACK) {
    if (x + 1 < 8 && y + 1 < 8 && !map[x + 1][y + 1].is_empty && map[x + 1][y + 1].chessman->color != color && map[x + 1][y + 1].chessman->type == PAWN)
        return true;
    if (x + 1 < 8 && y - 1 >= 0 && !map[x + 1][y - 1].is_empty && map[x + 1][y - 1].chessman->color != color && map[x + 1][y - 1].chessman->type == PAWN)
        return true;
    }
    else {
        if (x - 1 >= 0 && y + 1 < 8 && !map[x - 1][y + 1].is_empty && map[x - 1][y + 1].chessman->color != color && map[x - 1][y + 1].chessman->type == PAWN)
            return true;
        if (x - 1 >= 0 && y - 1 >= 0 && !map[x - 1][y - 1].is_empty && map[x - 1][y - 1].chessman->color != color && map[x - 1][y - 1].chessman->type == PAWN)
            return true;
    }
    for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
    {
        if (!map[i][j].is_empty && map[i][j].chessman->color == color)
            break;
        else if (!map[i][j].is_empty && map[i][j].chessman->color != color && (
        map[i][j].chessman->type == QUEEN || map[i][j].chessman->type == KING || map[i][j].chessman->type == BIGSHOP))
            return true;
        else if (map[i][j].is_empty)
            continue;
        else
            break;
    }
    for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
    {
        if (!map[i][j].is_empty && map[i][j].chessman->color == color)
            break;
        else if (!map[i][j].is_empty && map[i][j].chessman->color != color && (
            map[i][j].chessman->type == QUEEN || map[i][j].chessman->type == KING || map[i][j].chessman->type == BIGSHOP))
            return true;
        else if (map[i][j].is_empty)
            continue;
        else
            break;
    }
    for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
    {
        if (!map[i][j].is_empty && map[i][j].chessman->color == color)
            break;
        else if (!map[i][j].is_empty && map[i][j].chessman->color != color && (
        map[i][j].chessman->type == QUEEN || map[i][j].chessman->type == KING || map[i][j].chessman->type == BIGSHOP))
            return true;
        else if (map[i][j].is_empty)
            continue;
        else
            break;
    }
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (!map[i][j].is_empty && map[i][j].chessman->color == color)
            break;
        else if (!map[i][j].is_empty && map[i][j].chessman->color != color && (
        map[i][j].chessman->type == QUEEN || map[i][j].chessman->type == KING || map[i][j].chessman->type == BIGSHOP))
            return true;
        else if (map[i][j].is_empty)
            continue;
        else
            break;
    }
    return false;
}

bool is_mat(t_map **map, enum e_color color)
{
    for(size_t i = 0; i < 8; i++)
    {
        for(size_t j = 0; j < 8; j++)
        {
            if (!map[i][j].is_empty &&
            map[i][j].chessman->color == color &&
            map[i][j].chessman->type == KING)
                return check_mat2(map, i, j, color);
        }
    }
    return false;
}

bool move_chessman(int chessposx, int chessposy, t_map **map)
{
    static int old_chessposy = -1;
    static int old_chessposx = -1;

    if ((map[chessposx][chessposy].target == RED ||\
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
        return true;
    }
    else if (!map[chessposx][chessposy].is_empty) {
        reset_target(map);
        map[chessposx][chessposy].chessman->move(map, chessposx, chessposy);
        old_chessposx = chessposx;
        old_chessposy = chessposy;
        return false;
    }
    else
    {
        old_chessposx = -1;
        old_chessposy = -1;
        reset_target(map);
        return false;
    }
    return false;
}