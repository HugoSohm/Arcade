/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibLoader
*/

#ifndef OOP_ARCADE_2018_LIBLOADER_HPP
#define OOP_ARCADE_2018_LIBLOADER_HPP

#include <iostream>
#include <dlfcn.h>
#include <string>

class LibLoader
{
    public:
        explicit LibLoader(std::string);
        ~LibLoader();
        void *getHandler();

    private:
        std::string _path;
        void *_handler;
};

#endif
