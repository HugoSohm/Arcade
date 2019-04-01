/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncurse.cpp
*/

#include "Ncurse.hpp"

Ncurse::Ncurse()
{
	_window = initscr();
	noecho();
	curs_set(FALSE);
	//nodelay(_window, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

Ncurse::~Ncurse()
{
	endwin();
}

void Ncurse::drawASquare(float x, float y, float width, float height, unsigned int color)
{
	attron(COLOR_PAIR(color));

	WINDOW *tmp = subwin(_window, y, x, height, width);
	box(tmp, ACS_VLINE, ACS_HLINE);
	wbkgd(tmp, COLOR_PAIR(color));
    touchwin(tmp);
	wrefresh(tmp);

	attroff(COLOR_PAIR(color));
    wrefresh(_window);
}

void Ncurse::drawASquare(float x, float y, float width, float height, std::string map)
{
    WINDOW *tmp = subwin(_window, y, x, height, width);

    box(tmp, ACS_VLINE, ACS_HLINE);
    touchwin(tmp);
    wrefresh(tmp);

    wrefresh(_window);
}

void Ncurse::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool = true, bool = false)
{
    attron(COLOR_PAIR(color));
    WINDOW *tmp = subwin(_window, y, x, height, width);

    box(tmp, ACS_VLINE, ACS_HLINE);
    wbkgd(tmp, COLOR_PAIR(color));
    touchwin(tmp);
    wrefresh(tmp);

    attroff(COLOR_PAIR(color));
    wrefresh(_window);
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
    mvprintw(x, y, "%c", c);
}

void Ncurse::clearAll()
{
    wclear(_window);
}

int Ncurse::getKeyPress()
{
    char c = getch();
    return(c);
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


extern "C" {
    void *LoadLib() {
        Ncurse *a = new Ncurse();
        return(a);
    }
}