##
## EPITECH PROJECT, 2019
## PSU_tetris_2018
## File description:
## Makefile
##

RM      =       rm -rf

SRC     = 		src/main.c			\
			src/game.c			\
			src/debug_mode.c 		\
			src/tools/my_strlen.c	 	\
			src/init_struct.c 		\
			src/tools/my_putstr.c		\
			src/param_good.c		\
			src/tools/my_strcmp.c		\
			src/tools/my_putnbr.c		\
			src/tools/tetris_ui.c

CFLAGS  =       -I./include

CC      =       gcc -lncurses

OBJ     =       $(SRC:.c=.o)

NAME    = tetris

all: $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC) -g

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:     fclean all

mr_clean :
		find -type f -name "*~" -delete -o -type f -name "#*#" -delete

.PHONY : all clean fclean mr_clean re
