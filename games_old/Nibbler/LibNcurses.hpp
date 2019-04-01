/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** Display.hpp
*/

#ifndef OOP_ARCADE_2018_DISPLAY_HPP
#define OOP_ARCADE_2018_DISPLAY_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <ncurses.h>
#include "../../include/IGraphicLoader.hpp"
#include <map>

class LibNcurses : IGraphicLoader
{
	public:
		LibNcurses() = default;
		~LibNcurses() override = default;

		void drawMap(std::map<int, std::string> &map) override;

};

#endif