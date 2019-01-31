#ifndef CHESSMASTER_H_
#define CHESSMASTER_H_

#include <stdbool.h>
#include <stddef.h>

enum e_type {KING, QUEEN, ROOK, BIGSHOP, KNIGHT, PAWN};
enum e_color {WHITE, BLACK};
enum e_target {NONE, RED, GREEN};

struct s_map
{
    bool is_empty;
    struct s_chessman *chessman;
    enum e_color color;
    enum e_target target;
};

typedef struct s_map t_map;

struct s_chessman
{
    enum e_type type;
    enum e_color color;
    void (*move)(struct s_map **map, int x, int y);
};

typedef struct s_chessman t_chessman;

int lunch_chessgame();

#endif /* !CHEESMASTER_H_*/
