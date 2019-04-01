##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzo lenzi
##

SRC     =   Ncurse.cpp

CFLAGS	+=	-fPIC -Wextra -Wall -Werror

CFLAGS	+=	-I ../../include/

OBJ     =	$(SRC:.c=.o)

NAME	=   lib_arcade_ncurses.so

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -shared -fPIC -lncurses

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
