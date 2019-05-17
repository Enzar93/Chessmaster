#ifndef AI_H_
#define AI_H_

#include "chessmaster.h"

struct s_bestmove
{
    int posx; //pawn start
    int posy;
    int x; //pawn end
    int y;
};

typedef struct s_bestmove t_bestmove;


double minimax(t_map **map, int depth, bool isMaximizing);
void ai_turn(t_map **map);

#endif /* !AI_H_*/
