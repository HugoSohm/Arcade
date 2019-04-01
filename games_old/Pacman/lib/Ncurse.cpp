/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncurse.cpp
*/

#include "Ncurse.hpp"

Ncurse::Ncurse()
{
	initscr();
	//noecho();
	//cbreak();
	//getch();
}

Ncurse::~Ncurse()
= default;

void Ncurse::drawASquare(float x, float y, float width, float height, unsigned int color)
{
/*	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(84);
	}
*/
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLUE);

	attron(COLOR_PAIR(color));
	mvprintw(x, y, "*");
	attroff(COLOR_PAIR(color));
}

void Ncurse::drawASquare(float x, float y, float width, float height, std::string map)
{
	map += ".txt";

	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(84);
	}
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLUE);

	attron(COLOR_PAIR(1));
	mvprintw(x, y, "*");
	attroff(COLOR_PAIR(1));
}

void Ncurse::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool = true, bool = false)
{
	map += ".txt";

	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(84);
	}
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLUE);

	attron(COLOR_PAIR(1));
	mvprintw(x, y, "*");
	attroff(COLOR_PAIR(1));
}

void Ncurse::setATextField(float x, float y, std::string fontPath)
{
    _inputwin = newwin(3, static_cast<int>(x), static_cast<int>(y), 5);
    box(_inputwin, 0, 0);
}

void Ncurse::drawATextField(std::string &textToDraw)
{
    wrefresh(_inputwin);
}

void Ncurse::drawAText(float x, float y, std::string str)
{
    mvprintw(x, y, str.c_str());
}

void Ncurse::clearThisSquare(float x, float y, char c)
{
    mvwprintw(_window, x, y, &c);
}

void Ncurse::clearAll()
{
    clear();
}

int Ncurse::getKeyPress()
{
    return(wgetch(_window));
}

void Ncurse::display()
{
    wrefresh(_window);
}

void Ncurse::clear()
{
}

void Ncurse::initSprite(std::string, int, int, int)
{
}

void Ncurse::execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Ncurse::drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{

}

void Ncurse::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool, bool)
{
}

extern "C" {
    void *LoadMap() {
        Ncurse *a = new Ncurse();
        return(a);
    }
}