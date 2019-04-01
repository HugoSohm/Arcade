/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Allegro.hpp
*/

#ifndef ALLEGRO_HPP
#define ALLEGRO_HPP

#include "../../include/IGraphicLoader.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>

class Allegro : IGraphicLoader
{
    enum MYKEYS {
        KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
    };
    public:
		Allegro();
		~Allegro() override;

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
        ALLEGRO_DISPLAY *_display;
        ALLEGRO_FONT *_font;
        ALLEGRO_EVENT_QUEUE *_event_queue;
        ALLEGRO_TIMER *_timer;
};

#endif