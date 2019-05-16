#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include "chessmaster.h"
#include "rook.h"
#include "ai.h"

static void move(t_map **map, size_t x, size_t y, size_t i, size_t j)
{

for (size_t i = 0; i < 8; i++)
{
    for (size_t j = 0; j < 8; j++)
    {
        if (map[i][j].target != NONE)
        {
            t_tree *brother = malloc(sizeof(t_tree));
            if (map[i][j].target == RED)
                brother->value = map[i][j].chessman->cost;
            else
                brother->value = 0;
        }
            map[i][j]
    }
    
}


void play(t_map **map)
{
    tree->value = 0;
    tree->map = map;

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (!map[i][j].is_empty && map[i][j].chessman->color == BLACK) {
                map[i][j].chessman->move(map, i, j);
            }
        }
        
    }
}



void ai_turn(t_map **map)
{
    
}
