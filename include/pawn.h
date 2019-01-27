#ifndef PAWN_H_
#define PAWN_H_


enum e_familly {BLACK, WHITE};

struct s_pawn
{
    enum e_familly familly;
    char *(*function)(struct s_chessman);
};

typedef struct s_pawn t_pawn;

int pawn_move();

#endif 