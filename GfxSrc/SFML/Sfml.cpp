/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
	_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade 2019", sf::Style::Close | sf::Style::Resize);
	_window->setActive(false);
	_window->clear();
	_font.loadFromFile("arial.ttf");
	_text.setCharacterSize(20);
	_text.setFont(_font);
}

Sfml::~Sfml()
{
    _window->close();
}

void Sfml::drawASquare(float x, float y, float pos_x, float pos_y, unsigned int color)
{
    sf::RectangleShape rectangle(sf::Vector2f(x * 10, y * 20));
    rectangle.setPosition(pos_x * 10, pos_y * 23);
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2.0);
    _window->draw(rectangle);
}

void Sfml::drawASquare(float x, float y, float pos_x, float pos_y, std::string map)
{
	sf::Sprite sprite;
	sf::RectangleShape square(sf::Vector2f(x, y));
	sf::Texture texture;

	if (!texture.loadFromFile(map)) {
		square.setPosition(pos_x, pos_y);
		square.setFillColor(sf::Color(255, 0, 0));
		this->_window->draw(square);
	} else {
		sprite.setTexture(texture);
		sprite.setPosition(pos_x, pos_y);
		this->_window->draw(sprite);
	}
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
    _text.setPosition(sf::Vector2f{y * 10, x * 22});
    _text.setString(str);
    _window->draw(_text);
}

void Sfml::clearThisSquare(float x, float y, char c)
{
    std::string str = "";
    str += c;

    _text.setPosition(sf::Vector2f{y * 10, x * 22});
    _text.setString(str);
    _window->draw(_text);
}

void Sfml::clearAll()
{
    _window->clear(sf::Color::Black);
}

int Sfml::getKeyPress()
{
    _window->waitEvent(_event);
    if (_event.type == sf::Event::KeyPressed) {
        if (_event.key.code == sf::Keyboard::N)
            return ((int)'n');
        else if (_event.key.code == sf::Keyboard::M)
            return ((int)'m');
        else if (_event.key.code == sf::Keyboard::L)
            return ((int)'l');
        else if (_event.key.code == sf::Keyboard::P)
            return ((int)'p');
        else if (_event.key.code == sf::Keyboard::X)
            return ((int)'x');
        else if (_event.key.code == sf::Keyboard::Z)
            return ((int)'z');
        else if (_event.key.code == sf::Keyboard::Q)
            return ((int)'q');
        else if (_event.key.code == sf::Keyboard::S)
            return ((int)'s');
        else if (_event.key.code == sf::Keyboard::D)
            return ((int)'d');
        else if (_event.key.code == sf::Keyboard::C)
            return ((int)'c');
        else if (_event.key.code == sf::Keyboard::V)
            return ((int)'v');
    }
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
	this->sprites[path] = std::make_pair(sf::Sprite(), sf::Texture());
	this->sprites[path].second.loadFromFile(path);
	this->sprites[path].first.setTexture(this->sprites[path].second);
	this->sprites[path].first.setPosition(x, y);
}

void Sfml::execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Sfml::drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
	this->_window->draw(this->sprites[name].first);
}

sf::RenderWindow *Sfml::getWindow()
{
	return this->_window;
}

sf::Event *Sfml::getEvent()
{
	return &this->_event;
}

extern "C" {
    void *LoadLib() {
        Sfml *a = new Sfml();
        return(a);
    }
}