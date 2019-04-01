/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGraphicLoader
*/

#ifndef OOP_ARCADE_2018_IGRAPHICLOADER_HPP
#define OOP_ARCADE_2018_IGRAPHICLOADER_HPP

#include <iostream>
#include <map>

class IGraphicLoader
{
    public:
        virtual ~IGraphicLoader() = default;
        virtual void drawASquare(float, float, float, float, unsigned int) = 0; /* Print un square avec une taille x (première argument) y (deuxieme argument), une position x (troisième argument) y (quatrième argument) et enfin une couleur */
        virtual void drawASquare(float, float, float, float, std::string) = 0; /* Print un square avec une taille x (première argument) y (deuxieme argument), une position x (troisième argument) y (quatrième argument), une string remplie d'un nom de file sans extension la lib la remplie toute seul (".txt" => Lib text, ".png" => Lib 2d) si le ficher n'est pas trouver il draw un square avec une couleur */
        virtual void drawASquare(float, float, float, float, std::string, unsigned int, bool = true, bool = false) = 0; /* Print un square avec une taille x (première argument) y (deuxieme argument), une position x (troisième argument) y (quatrième argument), une string remplie d'un nom de file sans extension la lib la remplie toute seul (".txt" => Lib text, ".png" => Lib 2d) si le ficher n'est pas trouver il draw un square avec une couleur, un bool que je t'explique plus tard, un bool pour print les charactères du file en gras */
        virtual int getKeyPress() = 0; /* retourne la valeur ascii de la key pressed */
        virtual void clearThisSquare(float, float, char) = 0; /* mvprintw( (première argument),  (deuxieme argument) , "%c", (troisième argument) ) */
        virtual void clear() = 0; /* clear la window uniquement Lib 2d */
        virtual void display() = 0; /* cette fonction display ;) */
        virtual void clearAll() = 0; /* clear la window avec toute les lib */
        virtual void setATextField(float x, float y, std::string fontPath = "font/BebasNeue-Bold.ttf") = 0; /* set un endroie ou l'utilisateur pourra remplire du text */
        virtual void drawATextField(std::string &textToDraw) = 0; /* draw un endroie ou l'utilisateur pourra remplire du text */
        virtual void drawAText(float, float, std::string) = 0; /* draw un text */
        virtual void initSprite(std::string, int, int, int) = 0; /* init un sprite avec sont path la taille d'un élément du sprite et le nombre d'element dans le spriteSheete */
        virtual void execThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic,
            bool bold) = 0; /* draw un sprite et le deplace dans le spriteSheete */
        virtual void drawThisSprite(float sizeX, float sizeY, float x, float y, std::string name, unsigned int color, bool dinamic,
            bool bold) = 0; /* draw un sprite sans le deplace dans le spriteSheete */
};
#endif
