##
## EPITA PROJECT, 2019
## Makefile
## File description:
## makefile
##

CFLAGS		= -W -Wall -Wextra -Werror -g3 -std=c99

CPPFLAGS	= -I./include

CC		= gcc `pkg-config --libs sdl` -lSDL_image -lm

RM		= rm -f

NAME		= chessmaster

SRCS		= src/main.c		\
			  src/game/chessboard.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
