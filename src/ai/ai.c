#include <stdlib.h>
#include <err.h>
#include <stdio.h>
#include <math.h>
#include "chessmaster.h"
#include "rook.h"
#include "ai.h"

static void display(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
            if (!map[i][j].is_empty)
			    printf("[%d]", map[i][j].chessman->type);
            else
                printf("[ ]");
		}
        printf("\n");
	}
}

static void display_target(t_map **map)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
            printf("[%d]", map[i][j].target);
		}
        printf("\n");
	}
    printf("\n\n");
}

static double evaluate(t_map **map)
{
    double white_score = 0;
    double black_score = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (!map[i][j].is_empty) {
                if (map[i][j].chessman->color == WHITE)
                    white_score += map[i][j].chessman->cost;
                else
                    black_score += map[i][j].chessman->cost;
            }
        }
    }
    if (is_mat(map, BLACK))
        white_score += 1000;
    if (is_mat(map, WHITE))
        black_score += 1000;
    return black_score - white_score;
}

static void simulation(t_map **map, size_t posx, size_t posy, bool isMaximizing, double *bestVal, int depth)
{
    t_chessman *stock = malloc(sizeof(t_chessman));
    double ret;
    int array[8][8];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++) {
            if (map[i][j].target == GREEN || map[i][j].target == RED) { //SIMULATING MOVE
                stock = map[i][j].chessman;
                map[i][j].chessman = map[posx][posy].chessman;
                map[i][j].is_empty = false;
                map[posx][posy].is_empty = true;
                map[posx][posy].chessman = NULL;
                for (size_t i = 0; i < 8; i++)
                {
                    for (size_t j = 0; j < 8; j++)
                    {
                        array[i][j] = map[i][j].target;
                    }
                }
                ret = minimax(map, depth-1, !isMaximizing);
                for (size_t i = 0; i < 8; i++)
                {
                    for (size_t j = 0; j < 8; j++)
                    {
                        map[i][j].target = array[i][j];
                    }
                }
                if (isMaximizing && ret > *bestVal)
                    *bestVal = ret;
                else if (!isMaximizing && ret < *bestVal)
                    *bestVal = ret;
                map[posx][posy].chessman = map[i][j].chessman; //UNDO
                map[posx][posy].is_empty = false;
                map[i][j].chessman = stock;
                if (stock == NULL)
                    map[i][j].is_empty = true;
            }
        }
    }
}

double minimax(t_map **map, int depth, bool isMaximizing)
{
    double score = evaluate(map);
    if (depth == 0)
        return score;
    reset_target(map);
    if (isMaximizing) {
        double bestval = -INFINITY;
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++) //POUR TOUT LES COUPS POSSIBLES
            {
                if (!map[i][j].is_empty && map[i][j].chessman->color == BLACK) {
                    map[i][j].chessman->move(map, i, j);
                    simulation(map, i, j, isMaximizing, &bestval, depth);
                    reset_target(map);
                }
            }
        }
        return bestval;
    }
    else {
        double bestval = INFINITY;
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++) //POUR TOUT LES COUPS POSSIBLES
            {
                if (!map[i][j].is_empty && map[i][j].chessman->color == WHITE) {
                    map[i][j].chessman->move(map, i, j);
                    simulation(map, i, j, isMaximizing, &bestval, depth);
                    reset_target(map);
                }
            }
        }
        return bestval;
    }
}

void ai_turn_simulate(t_map **map, t_bestmove *bestmove, double *bestval, size_t posx, size_t posy)
{
    t_chessman *stock;
    double moveval;
    int array[8][8];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++) {
            if (map[i][j].target == GREEN || map[i][j].target == RED) { //SIMULATING MOVE
                stock = map[i][j].chessman;
                map[i][j].chessman = map[posx][posy].chessman;
                map[i][j].is_empty = false;
                map[posx][posy].is_empty = true;
                map[posx][posy].chessman = NULL;
                for (size_t i = 0; i < 8; i++)
                {
                    for (size_t j = 0; j < 8; j++)
                    {
                        array[i][j] = map[i][j].target;
                    }
                }
                moveval = minimax(map, 2, false);
                for (size_t i = 0; i < 8; i++)
                {
                    for (size_t j = 0; j < 8; j++)
                    {
                        map[i][j].target = array[i][j];
                    }
                }
                map[posx][posy].chessman = map[i][j].chessman; //UNDO
                map[posx][posy].is_empty = false;
                map[i][j].chessman = stock;
                if (stock == NULL)
                    map[i][j].is_empty = true;
                if (moveval > *bestval) {
                    bestmove->posx = posx;
                    bestmove->posy = posy;
                    bestmove->x = i;
                    bestmove->y = j;
                    *bestval = moveval;
                }
            }
        }
    }
}

void ai_turn(t_map **map)
{
    double bestval = -INFINITY;
    t_bestmove *bestmove = malloc(sizeof(t_bestmove));
    bestmove->x = -1;
    bestmove->y = -1;
    bestmove->posx = -1;
    bestmove->posy = -1;
    for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++) //POUR TOUT LES COUPS POSSIBLES
            {
                if (!map[i][j].is_empty && map[i][j].chessman->color == BLACK) {
                        map[i][j].chessman->move(map, i, j);
                        ai_turn_simulate(map, bestmove, &bestval, i, j);
                        reset_target(map);
                    }
            }
        }
    map[bestmove->x][bestmove->y].chessman = map[bestmove->posx][bestmove->posy].chessman;
    map[bestmove->x][bestmove->y].is_empty = false;
    map[bestmove->posx][bestmove->posy].is_empty = true;
    map[bestmove->posx][bestmove->posy].chessman = NULL;
}
