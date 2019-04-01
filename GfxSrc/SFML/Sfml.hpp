/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfml.hpp
*/

#ifndef SFML_HPP
#define SFML_HPP

// Includes
#include "../../include/IGraphicLoader.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

// Class
class Sfml : IGraphicLoader
{
	public:
		Sfml();
		~Sfml() override;

		void drawASquare(float x, float y, float width, float height, unsigned int color) override;
		void drawASquare(float x, float y, float width, float height, std::string map) override;
		void drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool, bool) override;
		void setATextField(float x, float y, std::string fontPath) override;
		void drawATextField(std::string &textToDraw) override;
		void drawAText(float x, float y, std::string str) override;
		void clearThisSquare(float x, float y, char c) override;
		void clearAll() override;
		void clear() override;
		void initSprite(std::string, int, int, int) override;
		void execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic,
        bool bold) override;
        void drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic,
        bool bold) override;
		int getKeyPress() override;
		void display() override;
		sf::RenderWindow *getWindow();
		sf::Event *getEvent();
		std::map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;

	private:
		sf::RenderWindow    *_window;
		sf::Event           _event;
		sf::Font            _font;
		sf::Text            _text;
};

#endif