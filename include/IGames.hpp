/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGames
*/

#ifndef OOP_ARCADE_2018_IGAMES_HPP
#define OOP_ARCADE_2018_IGAMES_HPP

#include "IGraphicLoader.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class IGames
{
    public:
        virtual ~IGames() = 0;

    virtual int run(IGraphicLoader *, bool) = 0;
        virtual void DrawMap(IGraphicLoader*, bool) = 0;
        virtual int checkChar(IGraphicLoader *) = 0;
        virtual void setCh(int) = 0;
        virtual void initGame(IGraphicLoader *) = 0;
};
#endif
