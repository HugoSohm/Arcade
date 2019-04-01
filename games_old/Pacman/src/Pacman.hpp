/*
** EPITECH PROJECT, 2018
** pacman
** File description:
** pacman.hpp
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

// Namespace
using namespace std;

// Includes
#include "../../../include/IGames.hpp"
#include "../lib/Ncurse.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Class
class Pacman : IGames
{
    public:
        Pacman() = default;
        ~Pacman() = default;
        virtual void run(IGraphicLoader *lib, bool) override;
        virtual void DrawMap(IGraphicLoader *lib, bool) override;
    //    virtual void DrawMap(Ncurse *lib, bool);
        virtual int checkChar(IGraphicLoader *lib) override;
        virtual void setCh(int i) override;
        virtual void initGame(IGraphicLoader *lib) override;

    private:
        map<int, std::string> pacmap;
        map<int, std::string>::iterator it = pacmap.begin();
        string line;
};

// Prototypes
void loadMap();

#endif