#include "chessmaster.h"

int main(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "2") == 0) {
		lunch_chessgame(true);
	}
	else
		lunch_chessgame(false);
	return 0;
}
