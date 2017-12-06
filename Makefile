##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile
##

NAME	=	my_sokoban

SRC	=	src/printf/flag_check.c		\
		src/printf/print_func.c		\
		src/printf/print_func2.c	\
		src/printf/print_func3.c	\
		src/printf/printf.c		\
		src/printf/sys_func.c		\
		src/my_sokoban.c		\
		src/argv_check.c		\
		src/check_map.c			\
		src/game_main.c			\
		src/map_functions.c		\
		src/player_mouvement.c		\
		src/score_handling.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -lncurses $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
