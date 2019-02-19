##
## EPITA PROJECT, 2019
## Makefile
## File description:
## makefile
##

CFLAGS		= -W -Wall -Wextra

CPPFLAGS	= -I./include

SDL_CFLAGS	= `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image

CC		= gcc

RM		= rm -f

NAME		= chessmaster

SRCS		= src/main.c					\
		  	  src/game/chessboard.c			\
		  	  src/game/chessman/rook.c		\
			  src/game/chessman/bigshop.c	\
			  src/game/chessman/queen.c		\
			  src/game/chessman/king.c		\
			  src/game/chessman/pawn.c		\
			  src/game/chessman/knight.c	\
			  src/display/display.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) $(SDL_CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
