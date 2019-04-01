/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
	_window->create(sf::VideoMode(800, 600), "Arcade 2019");
}

Sfml::~Sfml()
{

}

void Sfml::drawASquare(float x, float y, float pos_x, float pos_y, unsigned int color)
{
	sf::RectangleShape square(sf::Vector2f(x, y));
	square.setPosition(pos_x, pos_y);
	square.setFillColor(sf::Color(static_cast<sf::Uint8>(color), 0, 0));

	_window->draw(square);
}

void Sfml::drawASquare(float x, float y, float pos_x, float pos_y, std::string map)
{
	sf::RectangleShape square(sf::Vector2f(x, y));
	sf::Texture *texture = nullptr;
	map += ".png";

	if (!texture->loadFromFile(map))
		square.setFillColor(sf::Color(255, 0, 0));

	square.setPosition(x, y);
	square.setTexture(texture);

	_window->draw(square);
}

void Sfml::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool = true, bool = false)
{
	sf::RectangleShape square(sf::Vector2f(x, y));
	sf::Texture *texture = nullptr;
	map += ".png";

	if (!texture->loadFromFile(map))
		square.setFillColor(sf::Color(255, 0, 0));

	square.setPosition(x, y);
	square.setTexture(texture);

	_window->draw(square);
}

void Sfml::setATextField(float x, float y, std::string fontPath)
{
}

void Sfml::drawATextField(std::string &textToDraw)
{
}

void Sfml::drawAText(float x, float y, std::string str)
{
}

void Sfml::clearThisSquare(float x, float y, char c)
{
}

void Sfml::clearAll()
{
}

int Sfml::getKeyPress()
{
}

void Sfml::display()
{
}

void Sfml::clear()
{
}

void Sfml::initSprite(std::string, int, int, int)
{
}

void Sfml::execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Sfml::drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Sfml::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool, bool)
{
}

extern "C" {
    void *LoadMap() {
        Sfml *a = new Sfml();
        return(a);
    }
}