##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make
##

CC	=	gcc

SRC	=		printf/tools/my_put_float.c	\
			printf/tools/my_put_nbr.c	\
			printf/tools/my_putchar.c	\
			printf/tools/my_putstr.c	\
			printf/tools/my_strlen.c	\
			printf/tools/my_put_dtab.c	\
			printf/tools/my_print_e.c	\
			printf/my_printf.c	\
			printf/manage_basics_flags.c	\
			printf/flags_string.c	\
			printf/flags_digits.c	\
			printf/flags_digits_2.c	\
			main.c	\
			error.c	\
			print_usage.c	\
			src/prepare_sokoban.c	\
			src/my_sokoban.c	\
			src/file_manager.c	\
			src/buffer_to_map.c	\
			src/my_get_nbr.c	\
			src/find_elements.c	\
			src/player_management.c	\
			src/boxes_management.c	\
			src/free_elements.c	\
			src/check_game_finished.c	\
			src/move.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I lib/ -w -Wextra -Wall
NCURSES	=	-pedantic -lncurses -g3

NAME	=	my_sokoban

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) $(NCURSES)
		make clean

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	:	fclean all
