#ifndef GRILLE_H
#define GRILLE_H

#include <stdbool.h>

// Les define pour definir les constante en lien avec la grille
#define TAILLE 4
#define VIDE 0
#define CROIX 1
#define CERCLE 2

void effaceConsole();
void afficheCaseCouleur(int camp);
void setGrilleVide(int grille[TAILLE][TAILLE]);
void afficheGrille(int grille[TAILLE][TAILLE]);
bool estCaseVide(int grille[TAILLE][TAILLE], int ligne, int colone);
bool estCoupValide(int grille[TAILLE][TAILLE], int ligne, int colone);
void convertitCoordonnees(char coordLetttre[2], int coordConvertie[2]);

#endif