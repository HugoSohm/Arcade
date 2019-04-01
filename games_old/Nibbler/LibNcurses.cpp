/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** Display.cpp
*/

#include "LibNcurses.hpp"

void LibNcurses::drawMap(std::map<int, std::string> &map)
{
	int key;
	std::map<int, std::string> disp = std::map<int, std::string>(map);

	initscr();
	for(int i = 0; i < map.size(); i++) {
		replace(disp[i].begin(), disp[i].end(), '0', ' ');
	}
	while (true) {
		for(int j = 0; j < map.size(); j++) {
			printw(disp[j].c_str(), 0, 0);
			refresh();
		}
		key = getch();
		if (key == 32)
			break;
		clear();
	}
	endwin();
}

extern "C" {
    void *LoadMap() {
        LibNcurses *a = new LibNcurses();
        return(a);
    }
}
