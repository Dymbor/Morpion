#include <stdio.h>
#include <stdlib.h>

#include "headers/grille.h"

int main()
{
    int grille[TAILLE][TAILLE];
    char coordLettre[2];
    int coordConvertie[2];

    coordLettre[0]='B';
    coordLettre[1]='2';


    convertitCoordonnees(coordLettre,coordConvertie);
    printf("Coordonée convertit: %i %i\n",coordConvertie[0],coordConvertie[1]);
    printf("Coordonée lettre: %c %c\n",coordLettre[0],coordLettre[1]);

    setGrilleVide(grille);
    afficheGrille(grille);

    return 0;
}