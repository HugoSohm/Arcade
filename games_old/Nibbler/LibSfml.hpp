/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** LibSfml.hpp
*/

#ifndef OOP_ARCADE_2018_LIBSFML_HPP
#define OOP_ARCADE_2018_LIBSFML_HPP

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../../include/IGraphicLoader.hpp"

class LibSfml : IGraphicLoader
{
	public:
		LibSfml();
		~LibSfml() override = default;

		void drawASquare(float, float, float, float, unsigned int) override;
		void drawASquare(float, float, float, float, std::string) override;
/*
		sf::RenderWindow getWindow();
*/

		sf::RenderWindow window;
};

#endif
