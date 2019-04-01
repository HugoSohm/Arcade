/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#ifndef OOP_ARCADE_2018_CORE_HPP
#define OOP_ARCADE_2018_CORE_HPP

#include "IGames.hpp"
#include "IGraphicLoader.hpp"
#include "LibLoader.hpp"
#include <vector>
#include <dlfcn.h>
#include <map>
#include <ncurses.h>
#include <dirent.h>
#include <fstream>
#include <unistd.h>


class Core
{
    public :
        explicit Core(std::string);
        ~Core();

        void LoadLib();
        void LoadGame();
        void DrawGame();
        void Menu();
        void nextGfxLib();
        void prevGfxLib();
        void nextGameLib();
        void prevGameLib();
        void execBinding(char);
        void displayFolder(std::string, int);

        enum keyBinding {
            QUIT = 'x',
            NEXT_GFXLIB = 'n',
            PREV_GFXLIB = 'p',
            NEXT_GAME = 'c',
            PREV_GAME = 'v',
            BACK = 'm',
            PACMAN = 'l',
            NIBBLER = 'm'
        };

        enum Scene {
            MENU = 1,
            GAME = 2
        };

private:
        std::map<std::string, std::string> _GfxPathMap;
        std::map<std::string, std::string> _GamesPathMap;
        std::vector<LibLoader *> _LibHandlers;
        std::vector<LibLoader *> _GameHandlers;
        IGraphicLoader * _CGfxLib;
        IGames * _CGame;
        std::map<std::string, LibLoader *> _GfxLibMap;
        std::map<std::string, LibLoader *> _GameLibMap;
        int _currentGfxLib;
        int _currentLoadedGame;
        bool _isKnownLib;
        Scene status;
};

#endif
