/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
	this->_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML Arcade", sf::Style::Close);
	this->_event = new sf::Event {};
}

Sfml::~Sfml()
{
	this->_window->close();
	delete(this->_window);
	delete(this->_event);
}

void Sfml::drawASquare(float x, float y, float width, float height, unsigned int color)
{
	sf::RectangleShape square(sf::Vector2f(x, y));

	square.setSize(sf::Vector2f(x, y));
	square.setPosition(width, height);
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
	sf::Text text;
	sf::Font font;

	font.loadFromFile("arial.ttf");

	text.setFont(font);
	text.setPosition(x, y);
	text.setString(str);

	this->_window->draw(text);
}

void Sfml::clearThisSquare(float x, float y, char c)
{
}

void Sfml::clearAll()
{
}
int Sfml::getKeyPress()
{
	if (this->_event->KeyPressed)
		std::cout << this->_event->key.code << std::endl;
	return 0;
}

void Sfml::display()
{
	this->_window->display();
}

void Sfml::clear()
{
	this->_window->clear();
}

void Sfml::initSprite(std::string path, int x, int y, int elem)
{
	sf::Texture texture;
	texture.loadFromFile(path);

	this->_sprite = new sf::Sprite();
	//sf::Sprite sprite(texture,sf::IntRect(10, 10, 30, 30));
	this->_sprite->setTexture(texture);
	this->_sprite->setPosition(x, y);
	this->_window->draw(*this->_sprite);
}

void Sfml::execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Sfml::drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
	this->_window->draw(*this->_sprite);
}

extern "C" {
    void *LoadMap() {
        Sfml *a = new Sfml();
        return(a);
    }
}

sf::RenderWindow *Sfml::getWindow()
{
	return this->_window;
}

sf::Event *Sfml::getEvent()
{
	return this->_event;
}
