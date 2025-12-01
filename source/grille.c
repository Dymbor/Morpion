#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

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
    // ligne haut
    printf("      A     B     C     D\n");
    printf("   ┌─────┬─────┬─────┬─────┐\n");
    for (int i = 0; i < TAILLE; i++)
    {
        printf(" %i │ ", i + 1);

        // affichage d'une ligne
        for (int j = 0; j < TAILLE; j++)
        {
            afficheCaseCouleur(grille[i][j]);
            if (j < TAILLE - 1)
            {
                printf(" │ ");
            }
            else
            {
                printf(" │\n");
            }
        }

        // affichage séparateur
        if (i < TAILLE - 1)
        {
            printf("   ├─────┼─────┼─────┼─────┤\n");
        }
        else
        {
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
    if (system("clear") != 0) // verifie que la console est correctement effacer
    {
        printf("La console n'as pas pus etre effacer");
    }
}

bool estCoupValide(int grille[TAILLE][TAILLE], int ligne, int colone)
{
    if (ligne < 0 || ligne >= TAILLE || colone < 0 || colone >= TAILLE || !estCaseVide(grille, ligne, colone))
    {
        printf("Le coup n'est pas valide\n");
        return false;
    }
    else
    {
        return true;
    }
}

void convertitCoordonnees(char coordLetttre[2], int coordConvertie[2])
{
    coordConvertie[1] = coordLetttre[1] - '0' - 1; // on retire '0' pour avoir la bonne valeur numérique et 1 pour avoir la valeur logique du tableau
    char lettre = tolower(coordLetttre[0]);
    switch (lettre)
    {
    case 'a':
        coordConvertie[0] = 0;
        break;

    case 'b':
        coordConvertie[0] = 1;
        break;

    case 'c':
        coordConvertie[0] = 2;
        break;

    case 'd':
        coordConvertie[0] = 3;
        break;

    default:
        coordConvertie[0] = 99; // on donne une valeur trop grand pour que le résultat ne passe pas dans les fonction de vérification
        break;
    }
}