/*
** EPITECH PROJECT, 2018
** pacman
** File description:
** pacman.cpp
*/

#include "src/Pacman.hpp"
#include "lib/Ncurse.hpp"

int main(int argc, char **argv)
{
        Pacman pac;
        Ncurse *lib = new Ncurse();


        //initscr();
        pac.DrawMap(lib, true);
        //mvprintw(1, 1, "hello");
        refresh();
        getch();
        endwin();
        return (0);
}