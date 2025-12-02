#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../headers/bot.h"
#include "../headers/joueur.h"

void jouerBot(int grille[TAILLE][TAILLE])
{
    int ligne;
    int col;
    // on cherche à jouer le meilleur coup dans cette ordre : Victoire -> BloqueVictoire -> Centre -> Coins -> Bordures
    //on tente de gagner
    if (trouverCoupGagnant(grille))
    {
        return;
    }

    //on empeche le joueur de gagner si possible
    if (trouverCoupBloquant(grille))
    {
        return;
    }

    // si des cases sont dispos on prend le centre
    if (prendreCentre(grille, &ligne, &col))
    {
        jouerCoup(grille, ligne, col, CROIX);
        return;
    }

    //sinon un coin
    if (prendreCoin(grille, &ligne, &col))
    {
        jouerCoup(grille, ligne, col, CROIX);
        return;
    }

    //s'il n'y a plus rien on prend le bord de la grille
    if (prendreBord(grille, &ligne, &col))
    {
        jouerCoup(grille, ligne, col, CROIX);
        return;
    }

    //piste d'amélioration: implémenter un algorithme min max si le temps le permet
}

bool trouverCoupGagnant(int grille[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == VIDE)
            {
                jouerCoup(grille,i,j,CROIX);
                if (estPartieFinie(grille) == CROIX)
                {
                    return true;
                }
                grille[i][j] = VIDE;
            }
        }
    }
    return false;
}

bool trouverCoupBloquant(int grille[TAILLE][TAILLE])
{
    for (int i = 0; i < TAILLE; i++)
    {
        for (int j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == VIDE)
            {
                jouerCoup(grille,i,j,CERCLE);
                if (estPartieFinie(grille) == CERCLE)
                {
                    grille[i][j] = VIDE;
                    jouerCoup(grille,i,j,CROIX);
                    return true;
                }
                grille[i][j] = VIDE;
            }
        }
    }
    return false;
}

bool prendreCentre(int grille[TAILLE][TAILLE], int *ligne, int *col)
{
    if (estCaseVide(grille, 1, 1))
    {
        *ligne = 1;
        *col = 1;
        return true;
    }
    if (estCaseVide(grille, 1, 2))
    {
        *ligne = 1;
        *col = 2;
        return true;
    }
    if (estCaseVide(grille, 2, 1))
    {
        *ligne = 2;
        *col = 1;
        return true;
    }
    if (estCaseVide(grille, 2, 2))
    {
        *ligne = 2;
        *col = 2;
        return true;
    }
    return false;
}

bool prendreCoin(int grille[TAILLE][TAILLE], int *ligne, int *col)
{

    if (estCaseVide(grille, 0, 0))
    {
        *ligne = 0;
        *col = 0;
        return true;
    }
    if (estCaseVide(grille, 3, 0))
    {
        *ligne = 3;
        *col = 0;
        return true;
    }
    if (estCaseVide(grille, 0, 3))
    {
        *ligne = 0;
        *col = 3;
        return true;
    }
    if (estCaseVide(grille, 3, 3))
    {
        *ligne = 3;
        *col = 3;
        return true;
    }
    return false;
}

bool prendreBord(int grille[TAILLE][TAILLE], int *ligne, int *col)
{
    if (estCaseVide(grille, 0, 1))
    {
        *ligne = 0;
        *col = 1;
        return true;
    }
    if (estCaseVide(grille, 0, 2))
    {
        *ligne = 0;
        *col = 2;
        return true;
    }

    if (estCaseVide(grille, 3, 1))
    {
        *ligne = 3;
        *col = 1;
        return true;
    }
    if (estCaseVide(grille, 3, 2))
    {
        *ligne = 3;
        *col = 2;
        return true;
    }

    if (estCaseVide(grille, 1, 0))
    {
        *ligne = 1;
        *col = 0;
        return true;
    }
    if (estCaseVide(grille, 2, 0))
    {
        *ligne = 2;
        *col = 0;
        return true;
    }
    if (estCaseVide(grille, 1, 3))
    {
        *ligne = 1;
        *col = 3;
        return true;
    }
    if (estCaseVide(grille, 2, 3))
    {
        *ligne = 2;
        *col = 3;
        return true;
    }

    return false;
}
