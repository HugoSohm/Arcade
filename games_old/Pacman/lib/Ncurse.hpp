/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncurse.hpp
*/

#ifndef NCURSE_HPP
#define NCURSE_HPP

#include "../../../include/IGraphicLoader.hpp"
#include <algorithm>
#include <ncurses.h>
#include <iostream>
#include <map>

// Class
class Ncurse : IGraphicLoader
{
	public:
		Ncurse();
		~Ncurse() override;

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

    private:
			WINDOW *_inputwin;
			WINDOW *_window;
};

#endif