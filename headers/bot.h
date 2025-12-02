#ifndef BOT_H
#define BOT_H

#include <stdbool.h>
#include "grille.h"
#include "joueur.h"


void jouerBot(int grille[TAILLE][TAILLE]);
bool trouverCoupGagnant(int grille[TAILLE][TAILLE]);
bool trouverCoupBloquant(int grille[TAILLE][TAILLE]);
bool prendreCentre(int grille[TAILLE][TAILLE], int *ligne, int *col);
bool prendreCoin(int grille[TAILLE][TAILLE], int *ligne, int *col);
bool prendreBord(int grille[TAILLE][TAILLE], int *ligne, int *col);

#endif