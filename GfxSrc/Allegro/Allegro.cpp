/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncurse.cpp
*/

#include "Allegro.hpp"

Allegro::Allegro()
{
    char *error;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        exit(84);
    }
    _display = al_create_display(1920, 920);
    al_init_font_addon();
    al_init_ttf_addon();
    if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        exit(84);
    }
    if(!_display) {
        fprintf(stderr, "failed to initialize allegro!\n");
        exit(84);
    }
    _font = al_load_ttf_font("arial.ttf", 20, 0);
    if (!_font) {
        exit(84);
    }
    _timer = al_create_timer(1.0 / 10.0);
    _event_queue = al_create_event_queue();
    al_register_event_source(_event_queue, al_get_display_event_source(_display));
    al_register_event_source(_event_queue, al_get_timer_event_source(_timer));
    al_register_event_source(_event_queue, al_get_keyboard_event_source());
}

Allegro::~Allegro()
{
    al_destroy_display(_display);
}

void Allegro::drawASquare(float x, float y, float width, float height, unsigned int color)
{
    x *= 10;
    y *= 10;
    width *= 10;
    height *= 20;
    if (height != 540)
        al_draw_rectangle(width, height, x + width, (y + height) * 1.5, al_map_rgb(0, 0, 255), 2);
    else
        al_draw_rectangle(width, height, x + width, (y + height) * 1.2, al_map_rgb(0, 0, 255), 2);
}

void Allegro::drawASquare(float x, float y, float width, float height, std::string map)
{
}

void Allegro::drawASquare(float x, float y, float width, float height, std::string map, unsigned int color, bool = true, bool = false)
{
}

void Allegro::setATextField(float x, float y, std::string fontPath)
{
}

void Allegro::drawATextField(std::string &textToDraw)
{
}

void Allegro::drawAText(float x, float y, std::string str)
{
    x *= 20;
    y *= 9.9;
    al_draw_text(_font, al_map_rgb(0, 0, 255), y, x, 0, str.c_str());
}

void Allegro::clearThisSquare(float x, float y, char c)
{
    x *= 20;
    y *= 9.9;

    std::string str = "";
    str += c;
    al_draw_text(_font, al_map_rgb(255, 255, 255), y, x, 0, str.c_str());
}

void Allegro::clearAll()
{
    al_clear_to_color(al_map_rgb(0,0,0));
}

int Allegro::getKeyPress()
{
    ALLEGRO_EVENT ev;

    al_wait_for_event(_event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_X:
                return((int)'x');
            case ALLEGRO_KEY_N:
                return((int)'n');
            case ALLEGRO_KEY_P:
                return((int)'p');
            case ALLEGRO_KEY_C:
                return((int)'c');
            case ALLEGRO_KEY_V:
                return((int)'v');
            case ALLEGRO_KEY_L:
                return((int)'l');
            case ALLEGRO_KEY_M:
                return((int)'m');
            case ALLEGRO_KEY_Z:
                return((int)'z');
            case ALLEGRO_KEY_Q:
                return((int)'q');
            case ALLEGRO_KEY_S:
                return((int)'s');
            case ALLEGRO_KEY_D:
                return((int)'d');
        }
    }
}

void Allegro::display()
{
    al_flip_display();
}

void Allegro::clear()
{
}

void Allegro::initSprite(std::string, int, int, int)
{
}

void Allegro::execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{
}

void Allegro::drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic, bool bold)
{

}


extern "C" {
    void *LoadLib() {
        Allegro *a = new Allegro();
        return(a);
    }
}