##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzolenzi
##

all:
	make -C SFML/ all
	cp SFML/lib_arcade_sfml.so .
	make -C Ncurse/ all
	cp Ncurse/lib_arcade_ncurses.so .
	make -C Allegro/ all
	cp Allegro/lib_arcade_allegro.so .

clean:
	make -C SFML/ clean
	rm -f lib_arcade_sfml.so
	make -C Ncurse/ clean
	rm -f lib_arcade_ncurses.so
	make -C Allegro/ clean
	rm -f lib_arcade_allegro.so

fclean:	clean
	make -C SFML/ fclean
	make -C Ncurse/ fclean
	make -C Allegro/ fclean

re:	fclean all

.PHONY: all clean fclean re
