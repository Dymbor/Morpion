#include <stdio.h>
#include <stdlib.h>

#include "headers/grille.h"

int main()
{
    int grille[TAILLE][TAILLE];

    setGrilleVide(grille);
    afficheGrille(grille);

    return 0;
}