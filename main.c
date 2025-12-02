#include <stdio.h>
#include <stdlib.h>

#include "headers/grille.h"
#include "headers/joueur.h"

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

    jouerCoup(grille,0,0,CROIX);
    jouerCoup(grille,0,3,CROIX);    
    jouerCoup(grille,1,0,CROIX);
    jouerCoup(grille,1,1,CERCLE);
    jouerCoup(grille,2,0,CROIX);
    jouerCoup(grille,2,1,CERCLE);
    jouerCoup(grille,2,3,CERCLE);
    jouerCoup(grille,3,3,CROIX);

    afficheGrille(grille);

    return 0;
}