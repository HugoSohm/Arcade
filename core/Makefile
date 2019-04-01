##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzo lenzi
##

SRC     =   Core.cpp        \
            LibLoader.cpp   \
            main.cpp

CFLAGS	=	-Wall -Wextra -Werror -I ../include/ -ldl -std=c++17 -g3

OBJ     =	$(SRC:.cpp=.o)

NAME	=   arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(OBJ) -o $(NAME) -ldl -lncurses

%.o:	%.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
