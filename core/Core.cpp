/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Core
*/

#include "Core.hpp"
#include <ncurses.h>


typedef void *(*Loader)();

Core::Core(std::string pathToLib) {
    int i = 0;
    _isKnownLib = false;
    std::map<std::string, std::string>::iterator it;

    _GfxPathMap["ncurse"] = "lib/lib_arcade_ncurses.so";
    _GfxPathMap["sfml"] = "lib/lib_arcade_sfml.so";
    _GfxPathMap["test"] = "lib/lib_arcade_allegro.so";
    _GamesPathMap["pacman"] = "games/lib_arcade_pacman.so";
    _GamesPathMap["nibbler"] = "games/lib_arcade_nibbler.so";
    _LibHandlers.push_back(new LibLoader(_GfxPathMap["ncurse"]));
    _LibHandlers.push_back(new LibLoader(_GfxPathMap["sfml"]));
    _LibHandlers.push_back(new LibLoader(_GfxPathMap["test"]));
    _GameHandlers.push_back(new LibLoader(_GamesPathMap["pacman"]));
    _GameHandlers.push_back(new LibLoader(_GamesPathMap["nibbler"]));
    for (it = this->_GfxPathMap.begin(); it != this->_GfxPathMap.end(); it++) {
        if (it->second == pathToLib) {
            _currentGfxLib = i;
            _isKnownLib = true;
        }
        i++;
    }
    if (!_isKnownLib) {
        std::cout << "_isKnownLib was false\n";
        _LibHandlers.push_back(new LibLoader(pathToLib));
        _currentGfxLib = static_cast<int>(_LibHandlers.size()) - 1;
    }
    this->LoadLib();
    status = MENU;
}

void Core::LoadLib() {
    Loader func;
    char *error;

    func = (Loader) dlsym(_LibHandlers[_currentGfxLib]->getHandler(), "LoadLib");
    if ((error = dlerror()) != nullptr) {
        fputs(error, stderr);
        exit(84);
    }
    _CGfxLib = static_cast<IGraphicLoader *>(func());
}

void Core::LoadGame() {
    Loader func;
    char *error;

    func = (Loader) dlsym(_GameHandlers[_currentLoadedGame]->getHandler(), "LoadIGame");
    if ((error = dlerror()) != nullptr) {
        fputs(error, stderr);
        exit(84);
    }
    _CGame = static_cast<IGames *>(func());
}

void Core::DrawGame() {
    char c;
        while (1) {
            _CGfxLib->clearAll();
            _CGame->DrawMap(_CGfxLib, true);
            c = _CGame->run(_CGfxLib, true);
            if (c == QUIT) {
                delete (_CGfxLib);
                exit(0);
            }
            this->execBinding(c);
            _CGfxLib->display();
          //  usleep(30000);
        }
}

void Core::nextGfxLib() {
    delete(_CGfxLib);
    if (_currentGfxLib + 1 < static_cast<int>(_LibHandlers.size())) {
        _currentGfxLib++;
       this->LoadLib();
    }
    else {
        _currentGfxLib = 0;
        this->LoadLib();
    }
}

void Core::prevGfxLib() {
    delete(_CGfxLib);
    if (_currentGfxLib - 1 >= 0) {
        _currentGfxLib--;
        this->LoadLib();
    }
    else {
        _currentGfxLib = static_cast<int>(_LibHandlers.size()) - 1;
        this->LoadLib();
    }
}

void Core::nextGameLib() {
    if (_currentLoadedGame == 0)
        _currentLoadedGame = 1;
    else if (_currentLoadedGame == 1)
        _currentLoadedGame = 0;
}

void Core::prevGameLib() {
    if (_currentLoadedGame == 0)
        _currentLoadedGame = 1;
    else if (_currentLoadedGame == 1)
        _currentLoadedGame = 0;
}

void Core::Menu() {
    std::ifstream file;
    file.open("Arcade.txt");
    int x = 50;
    int y = 10;
    char c = '1';

    if (!file) {
        std::cerr << "Unable to open map file";
        exit(84);
    }
    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
    while(1) {
        _CGfxLib->clearAll();
        _CGfxLib->drawASquare(40, 25, 20, 13, 2);
        _CGfxLib->drawAText(23, 37, "PACMAN");
        _CGfxLib->drawAText(25, 32, "PRESS L TO START");
        _CGfxLib->drawASquare(40, 25, 90, 13, 2);
        _CGfxLib->drawAText(23, 108, "SNAKE");
        _CGfxLib->drawAText(25, 103, "PRESS M TO START");
        _CGfxLib->drawASquare(30, 15, 140, 4, 2);
        _CGfxLib->drawASquare(30, 15, 140, 27, 2);
        _CGfxLib->drawAText(5, 152, "Games");
        _CGfxLib->drawAText(28, 152, "Gfx Lib");
        _CGfxLib->drawAText(40, 61, "PRESS N TO SWITCH TO NEXT LIB");
        _CGfxLib->drawAText(42, 61, "PRESS P TO SWITCH TO PREV LIB");
        this->displayFolder("./games/", 8);
        this->displayFolder("./lib/", 31);
        x = 18;
        y = 0;
        for (char &d : content) {
            if (d == ' ')
                x += 1;
            if (d == '\n') {
                y += 1;
                x = 18;
            }
            if (d == '*') {
                _CGfxLib->clearThisSquare(y, x, '*');
                x += 1;
            }
        }
        c = _CGfxLib->getKeyPress();
        if (c == QUIT) {
            delete (_CGfxLib);
            return;
        }
        this->execBinding(c);
        _CGfxLib->display();
    }
}

void Core::execBinding(char key) {
    _CGfxLib->drawAText(1, 1, std::to_string(int(key)));
    if (status == MENU) {
        if (key == NEXT_GFXLIB)
            this->nextGfxLib();
        else if (key == PREV_GFXLIB)
            this->prevGfxLib();
        else if (key == PACMAN) {
            status = GAME;
            _currentLoadedGame = 0;
            this->LoadGame();
            this->DrawGame();
        } else if (key == NIBBLER) {
            status = GAME;
            _currentLoadedGame = 1;
            this->LoadGame();
            this->DrawGame();
        }
    }
    if (status == GAME) {
        if (key == NEXT_GFXLIB)
            this->nextGfxLib();
        else if (key == PREV_GFXLIB)
            this->prevGfxLib();
        else if (key == NEXT_GAME) {
            this->nextGameLib();
            this->LoadGame();
            this->DrawGame();
        }
        else if (key == PREV_GAME) {
            this->prevGameLib();
            this->LoadGame();
            this->DrawGame();
        }
        else if (key == BACK) {
            status = MENU;
            this->Menu();
        }
    }
}

void Core::displayFolder(std::string path, int height) {
    DIR *dir;
    struct dirent *ent;
    std::string file;

    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            file = ent->d_name;
            if (file.find(".so") != std::string::npos) {
                _CGfxLib->drawAText(height, 142, ent->d_name);
                height += 1;
            }
        }
        closedir (dir);
    } else {
        perror ("Couldn't open file.");
        exit(EXIT_FAILURE);
    }
}

Core::~Core() = default;
