#include <stdio.h>
#include <stdlib.h>

#include "headers/grille.h"
#include "headers/joueur.h"

int main()
{
    int grille[TAILLE][TAILLE];

   
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