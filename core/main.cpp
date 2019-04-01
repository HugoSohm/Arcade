/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** main
*/

#include "Core.hpp"
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    Core *core = new Core(av[1]);

    core->Menu();
    return (0);
}