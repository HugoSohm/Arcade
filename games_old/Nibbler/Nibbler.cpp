/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** Nibbler.cpp
*/

#include "Nibbler.hpp"

IGames::~IGames() = default;

Nibbler::Nibbler()
{
	this->loadMap();
	this->pos = 0;
	this->size = 4;
	this->direction = RIGHT;
}

void Nibbler::loadMap()
{
	std::string line;
	std::ifstream content("map.txt");
	int i = 0;

	if (content.is_open()) {
		while (std::getline(content, line)) {
			this->map[i] = line + '\n';
			i++;
		}
	}
}

std::map<int, std::string> &Nibbler::getMap()
{
	return this->map;
}

int Nibbler::getPos() {
	return this->pos;
}

int Nibbler::getSize() {
	return this->size;
}

Direction Nibbler::getDirection() {
	return this->direction;
}

void Nibbler::setPos(int pos)
{
	this->pos = pos;
}

void Nibbler::setSize(int size)
{
	this->size = size;
}

void Nibbler::setDirection(Direction direction)
{
	this->direction = direction;
}

extern "C" {
	void *LoadIGame() {
		Nibbler *a = new Nibbler();
		return (a);
	}
}
