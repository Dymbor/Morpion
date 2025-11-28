#include <stdio.h>
#include <stdlib.h>

#include "../headers/joueur.h"

void jouerCoup(int grille[TAILLE][TAILLE], int ligne, int colone, int camps){
    grille[ligne][colone] = camps;
}
