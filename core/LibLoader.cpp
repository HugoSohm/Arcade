/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibLoader
*/

#include "LibLoader.hpp"
#include <dlfcn.h>

LibLoader::LibLoader(std::string path) {
    _path = path;
    char *error;
    _handler = dlopen(_path.c_str(), RTLD_LAZY);
    if ((error = dlerror()) != nullptr) {
        fputs(error, stderr);
        std::cout << std::endl;
        exit(84);
    }
    if (!_handler)
        std::cout << "failed to open : '" << path.c_str() << "'" << std::endl;
}

LibLoader::~LibLoader() {
    dlclose(_handler);
}

void *LibLoader::getHandler() {
    return this->_handler;
}