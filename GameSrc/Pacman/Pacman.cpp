/*
** EPITECH PROJECT, 2018
** pacman
** File description:
** parser.cpp
*/

#include "Pacman.hpp"
#include <curses.h>

// IGames::~IGames() = default;

int Pacman::run(IGraphicLoader *lib, bool)
{
    int key = lib->getKeyPress();
    static float x = 2;
    static float y = 2;

    switch (key) {
        case 122:
            y = y - 1;
            break;
        case 113:
            x = x - 1;
            break;
        case 100:
            x = x + 1;
            break;
        case 115:
            y = y + 1;
            break;
    }
    lib->clearThisSquare(y, x, '>');
    return (key);
}

void Pacman::DrawMap(IGraphicLoader *lib, bool boulasses)
{
    std::ifstream file;
    file.open("map.txt");
    int x = 0;
    int y = 0;

    if (!file) {
        std::cerr << "Unable to open map file";
        exit(84);
    }

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    _content = content;

    for (char &c : _content) {
        if (c == ' ')
            x += 1;
        if (c == '\n') {
            y += 1;
            x = 0;
        }
        if (c == '*') {
            //   lib->clear();
            lib->drawASquare(1, 1, x, y, 1);
            //   lib->display();
            x += 1;
        }
    }
}

int Pacman::checkChar(IGraphicLoader *lib)
{
    return (lib->getKeyPress());
}

void Pacman::setCh(int i)
{
}

void Pacman::initGame(IGraphicLoader *lib)
{
	initscr();
	noecho();
    DrawMap(lib, 0);

    while (1) {
        run(lib, 0);
    }
	//cbreak();
	//getch();
}

extern "C" {
	void *LoadIGame() {
		Pacman *pac = new Pacman();
		return (pac);
	}
}