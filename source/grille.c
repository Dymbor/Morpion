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

bool estDansGrille(int grille[TAILLE][TAILLE],int ligne, int colone){
    if(ligne < 0 || ligne >= TAILLE || colone < 0 || colone >= TAILLE){
        return false;
    }
    return true;
}

bool estCoupValide(int grille[TAILLE][TAILLE],int ligne, int colone){
    if(!estDansGrille(grille,ligne,colone) || !estCaseVide(grille,ligne,colone)){

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

int estPartieFinis(int grille[TAILLE][TAILLE])
{
    // on choisi les retour en fonction du resultat: 0: partie non finis, 1(croix): croix a gagner, 2(cercle): cercle a gagner, 3: match nul

    // premiere etape on verifie les lignes
    for (int i = 0; i < TAILLE; i++)
    {
        if (grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2] && grille[i][2] == grille[i][3] && grille[i][0] != VIDE)
        { // on vérifie que toute les case d'une ligne sont égale et différente de vide
            return grille[i][0];
        }
    }

    // seconde etape on verifie les colones
    for (int i = 0; i < TAILLE; i++)
    {
        if (grille[0][i] == grille[1][i] && grille[1][i] == grille[2][i] && grille[2][i] == grille[3][i] && grille[0][i] != VIDE)
        {
            return grille[0][i];
        }
    }

    // troisieme etape on verifie les deux diagonale
    // premiere diagonale:
    if (grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2] && grille[2][2] == grille[3][3] && grille[0][0] != VIDE)
    {
        return grille[0][0];
    }
    // seconde diagonale:
    if (grille[0][3] == grille[1][2] && grille[1][2] == grille[2][1] && grille[2][1] == grille[3][0] && grille[0][3] != VIDE)
    {
        return grille[0][3];
    }

    // etape quatre on verifie s'il y as match nul
    if (estGrilleRemplis(grille))
    {
        return 3;
    }

    // la partie n'est pas finis
    return 0;
}

bool estGrilleRemplis(int grille[TAILLE][TAILLE])
{
    for(int i = 0; i < TAILLE; i ++)
    {
        for(int j = 0; j < TAILLE; j++)
        {
            if(grille[i][j] == VIDE)
            {
                return false;
            }
        }
    }
    return true;
}