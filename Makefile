##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Made by enzolenzi
##

all:
	make -C GfxSrc/ all
	cp GfxSrc/lib_arcade_sfml.so lib/
	cp GfxSrc/lib_arcade_ncurses.so lib/
	cp GfxSrc/lib_arcade_allegro.so lib/
	make -C GameSrc/ all
	cp GameSrc/lib_arcade_pacman.so games
	cp GameSrc/lib_arcade_nibbler.so games
	make -C core/ all
	cp core/arcade .

core:
	make -C core/ all
	cp core/arcade .

games:
	make -C GameSrc/ all
	cp GameSrc/*.so /games

graphicals:
	make -C GfxSrc/ all
	cp GfxSrc/lib_arcade_sfml.so lib/
	cp GfxSrc/lib_arcade_ncurses.so lib/
	cp GfxSrc/lib_arcade_allegro.so lib/

clean:
	make -C GfxSrc/ clean
	make -C GameSrc/ clean
	make -C core/ clean
	rm -f arcade

fclean:	clean
	make -C GfxSrc/ fclean
	make -C GameSrc/ fclean
	make -C core/ fclean

re:	fclean all

.PHONY: all clean fclean re
