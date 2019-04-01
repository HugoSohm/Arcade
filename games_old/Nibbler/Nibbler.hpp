/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** Nibbler.hpp
*/

#ifndef OOP_ARCADE_2018_NIBBLER_HPP
#define OOP_ARCADE_2018_NIBBLER_HPP

#include "../../include/IGames.hpp"

class Nibbler : IGames
{
	public :
		Nibbler();
		~Nibbler() = default;

		void loadMap() override;

		std::map<int, std::string> &getMap() override;
		int getPos();
		int getSize();
		Direction getDirection();

		void setPos(int pos);
		void setSize(int size);
		void setDirection(Direction direction);

		std::vector<char> snake{'O', 'o', 'o', 'o'};
	private:
		std::map<int, std::string> map;
			int pos;
			int size;
			Direction direction;
};

#endif
