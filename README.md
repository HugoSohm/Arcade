<div align="center"><h1>Arcade - Epitech 2019</h1>

L'arcade est un projet est un projet graphique de 1 mois réalisé par 3 étudiants à [Epitech Nice](https://www.epitech.eu/fr/)

[Hugo Sohm](https://github.com/HugoSohm), [Enzo Lenzi](https://github.com/EnzoLenzi), [Ryan Chamayrac](https://github.com/RyanChamayrac)

<img src="http://www.usociable.com/images/members/arcade_banner.jpg" alt="Arcade" /></div>

## Projet arcade

### Librairies

L'arcade fonctionne avec 3 différentes libraires graphiques en C

- [Ncurse](https://fr.wikipedia.org/wiki/Ncurses)
- [Allegro](https://liballeg.org)
- [SFML](https://www.sfml-dev.org/index-fr.php)

## Installation et compilation

### Récupération du projet

Après avoir cloné le [répertoire](https://github.com/HugoSohm/Arcade):

```
git clone https://github.com/HugoSohm/Arcade
```

- Se rendre à la racine du projet :

```
$ cd Arcade
```

- Vérifier que tout est à jour :

```
$ git checkout master
```

### Compilation du programme

- Compilation

```
$ make
```

- Re-compilation

```
$ make re
```

- Nettoyage

```
$ make fclean
```

## Execution

### Lancement du programme

- Ncurses
```
$ ./arcade lib/lib_arcade_ncurses.so
```

- Allegro
```
$ ./arcade lib/lib_arcade_allegro.so
```

- SFML
```
$ ./arcade lib/lib_arcade_sfml.so
```

## Touches

| Action                | Touche |
| --------------------- |:------:|
| Précédente librairie  |   p    |
| Prochaine librairie   |   n    |
| Retour au menu        |   m    |
| Précédent jeu         |   v    |
| Prochain jeu          |   c    |
| Jeu PACMAN            |   l    |
| Jeu NIBBLER           |   2    |
| Quitter               |   x    |