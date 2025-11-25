#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../headers/grille.h"

void setGrilleVide(int grille[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            grille[i][j] = VIDE;
        }
    }
}

void afficheGrille(int grille[TAILLE][TAILLE])
{
    //ligne haut
    printf("      A     B     C     D\n");
    printf("   ┌─────┬─────┬─────┬─────┐\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %i │ ", i + 1);

        // affichage d'une ligne
        for (int j = 0; j < TAILLE; j++)
        {
            afficheCaseCouleur(grille[i][j]);
            if (j < TAILLE - 1){
                printf(" │ ");
            }
            else{
                printf(" │\n");
            }
        }

        //affichage séparateur
        if (i < TAILLE - 1){
            printf("   ├─────┼─────┼─────┼─────┤\n");
        }
        else{
            printf("   └─────┴─────┴─────┴─────┘\n");
        }

    }
}

void afficheCaseCouleur(int camp)
{
    switch (camp)
    {
    case VIDE:
        printf("   ");
        break;

    case CERCLE:
        printf(" \x1b[36mO\x1b[0m "); // Affiche un cercle bleue
        break;

    case CROIX:
        printf(" \x1b[31mX\x1b[0m "); // Affiche une croix rouge
        break;

    default:
        printf("%i", camp);
        break;
    }
}

bool estCaseVide(int grille[TAILLE][TAILLE], int ligne, int colone)
{
    return grille[ligne][colone] == VIDE;
}

void effaceConsole()
{
    if (system("clear") != 0) //verifie que la console est correctement effacer
    {
        printf("La console n'as pas pus etre effacer");
    }
}

bool estCoupValide(int grille[TAILLE][TAILLE],int ligne, int colone){
    if(ligne < 1 || ligne > TAILLE || colone < 1 || colone > 1 || !estCaseVide(grille,ligne,colone)){
        printf("Le coup n'est pas valide\n");
        return false;
    }
    else{
        return true;
    }
}