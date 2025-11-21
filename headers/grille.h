#ifndef GRILLE_H
#define GRILLE_H

#include <stdbool.h>

// Les define pour definir les constante en lien avec la grille
#define TAILLE 3
#define VIDE 0
#define CROIX 1
#define CERCLE 2

void setGrilleVide(int grille[TAILLE][TAILLE]);
void afficheGrille(int grille[TAILLE][TAILLE]);
bool estCaseVide(int grille[TAILLE][TAILLE],int ligne, int colone);

#endif