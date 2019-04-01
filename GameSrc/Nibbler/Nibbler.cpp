/*
** EPITECH PROJECT, 2018
** Nibbler
** File description:
** parser.cpp
*/

#include "Nibbler.hpp"
#include <curses.h>

// IGames::~IGames() = default;

int Nibbler::run(IGraphicLoader *lib, bool)
{
    int key = lib->getKeyPress();
    int x = 0;
    int y = 0;

    switch (key) {
        case 122:
            y = y + 1;
            break;
        case 113:
            y = y - 1;
            break;
        case 100:
            x = x - 1;
            break;
        case 115:
            x = x + 1;
            break;
    }
    // move(x, y); Ajouter fonction d'affichage
}

void Nibbler::DrawMap(IGraphicLoader *lib, bool boulasses)
{
    std::ifstream file;
    file.open("map1.txt");
    int x = 0;
    int y = 0;

    if (!file) {
        std::cerr << "Unable to open map file";
        exit(84);
    }

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    for (char &c : content) {
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

int Nibbler::checkChar(IGraphicLoader *lib)
{
    return (lib->getKeyPress());
}

void Nibbler::setCh(int i)
{
}

void Nibbler::initGame(IGraphicLoader *lib)
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
		Nibbler *pac = new Nibbler();
		return (pac);
	}
}