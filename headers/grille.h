#ifndef GRILLE_H
#define GRILLE_H

// Les define de certaine valeur qui ne sont pas déstinée à bouger
#define TAILLE 3
#define VIDE 0
#define CROIX 1
#define CERCLE 2

void setGrilleVide(int grille[TAILLE][TAILLE]);
void afficheGrille(int grille[TAILLE][TAILLE]);

#endif