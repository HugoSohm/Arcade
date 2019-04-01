##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzolenzi
##

all:
	make -C Pacman/ all
	cp Pacman/lib_arcade_pacman.so .
	make -C Nibbler/ all
	cp Nibbler/lib_arcade_nibbler.so .

clean:
	make -C Pacman/ clean
	rm -f lib_arcade_pacman.so
	make -C Nibbler/ clean
	rm -f lib_arcade_nibbler.so

fclean:	clean
	make -C Pacman/ fclean
	make -C Nibbler/ fclean

re:	fclean all

.PHONY: all clean fclean re
