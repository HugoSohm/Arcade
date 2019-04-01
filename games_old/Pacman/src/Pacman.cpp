/*
** EPITECH PROJECT, 2018
** pacman
** File description:
** parser.cpp
*/

#include "Pacman.hpp"

// IGames::~IGames() = default;

void Pacman::run(IGraphicLoader *lib, bool)
{

}

void Pacman::DrawMap(IGraphicLoader *lib, bool boulasses)
{
    ifstream file;
    file.open("map.txt");
    int x = 0;
    int y = 0;

    if (!file) {
        cerr << "Unable to open map file";
        exit(84);
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

    for (char &c : content) {
        if (c == ' ')
            x += 1;
        if (c == '\n') {
            y += 1;
            x = 0;
        }
        if (c == '*') {
            //   lib->clear();
            lib->drawASquare(y, x, 0, 0, 1);
            //   lib->display();
            x += 1;
        }
    }
}

int Pacman::checkChar(IGraphicLoader *lib)
{
    return (0);
}

void Pacman::setCh(int i)
{

}

void Pacman::initGame(IGraphicLoader *lib)
{

}
/*
void Pacman::DrawMap(Ncurse *lib, bool) {
    ifstream file;
    file.open("map.txt");
    int x = 0;
    int y = 0;

    if (!file) {
        cerr << "Unable to open map file";
        exit(84);
    }

    string content((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

    for (char &c : content) {
        if (c == ' ')
            x += 1;
        if (c == '\n') {
            y += 1;
            x = 0;
        }
        if (c == '*') {
         //   lib->clear();
            lib->drawASquare(y, x, 0, 0, 1);
         //   lib->display();
            x += 1;
        }
    }
}
*/
extern "C" {
	void *LoadIGame() {
		Pacman *pac = new Pacman();
		return (pac);
	}
}