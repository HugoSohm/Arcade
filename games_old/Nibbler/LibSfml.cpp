/*
** EPITECH PROJECT 2019
** OOP_arcade_2018 - Ryan Chamayrac
** File description:
** LibSfml.cpp
*/

#include "LibSfml.hpp"

/*void LibSfml::drawMap(std::map<int, std::string> &map)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	while (window.isOpen()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
		rectangle.setFillColor(sf::Color(100, 250, 50));

		window.draw(rectangle);
		window.display();
	}
}*/

LibSfml::LibSfml()
{
	this->window.create(sf::VideoMode(800, 600), "SFML window");
}

void LibSfml::drawASquare(float x, float y, float pos_x, float pos_y, unsigned int color)
{
	sf::RectangleShape square(sf::Vector2f(x, y));
	square.setPosition(pos_x, pos_y);
	square.setFillColor(sf::Color(static_cast<sf::Uint8>(color), 0, 0));
	this->window.draw(square);
}

void LibSfml::drawASquare(float x, float y, float pos_x, float pos_y, std::string file)
{
	sf::RectangleShape square(sf::Vector2f(x, y));
	sf::Texture *texture = nullptr;

	if (!texture->loadFromFile("image.png")) {
		square.setFillColor(sf::Color(255, 0, 0));
	square.setPosition(pos_x, pos_y);
	square.setTexture(texture);
	this->window.draw(square);
}

/*sf::RenderWindow LibSfml::getWindow()
{
	return this->window;
}*/

extern "C" {
	void *LoadMap() {
		LibSfml *a = new LibSfml();
		return(a);
	}
}
