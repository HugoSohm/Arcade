/*
** EPITECH PROJECT, 2018
** Nibbler
** File description:
** Nibbler.hpp
*/

#ifndef Nibbler_HPP
#define Nibbler_HPP


#include "../../include/IGames.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

// Class
class Nibbler : IGames
{
    public:
        Nibbler() = default;
        ~Nibbler() override = default;
        int run(IGraphicLoader *lib, bool) override;
        void DrawMap(IGraphicLoader *lib, bool) override;
        int checkChar(IGraphicLoader *lib) override;
        void setCh(int i) override;
        void initGame(IGraphicLoader *lib) override;
    private:
        std::map<int, std::string> pacmap;
        std::map<int, std::string>::iterator it = pacmap.begin();
        std::string line;
};
#endif