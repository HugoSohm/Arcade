/*
** EPITECH PROJECT, 2018
** pacman
** File description:
** pacman.hpp
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP


#include "../../include/IGames.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Class
class Pacman : IGames
{
    public:
        Pacman() = default;
        ~Pacman() override = default;
        int run(IGraphicLoader *lib, bool) override;
        void DrawMap(IGraphicLoader *lib, bool) override;
        int checkChar(IGraphicLoader *lib) override;
        void setCh(int i) override;
        void initGame(IGraphicLoader *lib) override;
    private:
        std::map<int, std::string> pacmap;
        std::map<int, std::string>::iterator it = pacmap.begin();
        std::string line;
        std::string _content;
};
#endif