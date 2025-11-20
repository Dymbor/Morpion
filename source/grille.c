#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < TAILLE; i++)
    {
        printf("-------------------\n");
        printf("| ");
        for (int j = 0; j < TAILLE; j++)
        {
            switch (grille[i][j])
            {
            case VIDE:
                printf("[ ] | ");
                break;

            case CERCLE:
                printf("[\x1b[36mO\x1b[0m] | "); // Cercle bleue
                break;

            case CROIX:
                printf("[\x1b[31mX\x1b[0m] | "); // Croix rouge
                break;

            default:
                printf("%i",grille[i][j]);
                break;
            }
        }
        printf("\n");
    }
    printf("-------------------\n");

}