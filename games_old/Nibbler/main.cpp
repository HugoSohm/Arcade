/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** main.cpp
*/

#include "Nibbler.hpp"
#include "LibNcurses.hpp"
#include "LibSfml.hpp"

int main(int ac, char **av)
{
	Nibbler a;
	a.loadMap();
	LibNcurses b;
	b.drawMap(a.getMap());
}