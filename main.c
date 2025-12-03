#include <stdio.h>
#include <stdlib.h>
#include "headers/grille.h"
#include "headers/joueur.h"
#include "headers/bot.h"

int main()
{
    int grille[TAILLE][TAILLE];
    char coordLettre[3];
    int coordConvertie[2];
    int resultat = 0;

    int scoreNul = 0, scoreJoueur = 0, scoreOrdi = 0;

    int choix = 1;

    while (choix != 2)
    {
        printf("\x1b[1;4mJeu du morpion\x1b[0m\n");
        printf("Score : \nOrdinateur : %d  Joueur : %d\n\n", scoreOrdi, scoreJoueur);
        printf("Jouer : 1\n");
        printf("Arreter : 2\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 2) 
            break;

        if (choix != 1)
        {
            printf("Choix invalide.\n\n");
            continue;
        }

        setGrilleVide(grille);
        resultat = 0;

        while ((resultat = estPartieFinie(grille)) == 0)
        {
            printf("\x1b[1;4mScore actuel :\x1b[0m\n");
            printf("Joueur : %i\n", scoreJoueur);
            printf("Ordinateur : %i\n", scoreOrdi);
            printf("Match nul : %i\n", scoreNul);
            afficheGrille(grille);

            printf("Joueur, entrez des coordonnee (ex: A1, B3) : ");
            scanf("%2s", coordLettre);
            convertitCoordonnees(coordLettre, coordConvertie);

            while (!estCoupValide(grille, coordConvertie[1], coordConvertie[0]))
            {
                printf("Coup invalide, reessayez : ");
                scanf("%2s", coordLettre);
                convertitCoordonnees(coordLettre, coordConvertie);
            }

            jouerCoup(grille, coordConvertie[1], coordConvertie[0], CERCLE);

            resultat = estPartieFinie(grille);
            if (resultat != 0)
                break;

            effaceConsole();

            jouerBot(grille);
            printf("Tour du bot...\n");

            resultat = estPartieFinie(grille);
        }

        effaceConsole();
        afficheGrille(grille);

        switch (resultat)
        {
        case CROIX:
            printf("Le bot (\x1b[31mX\x1b[0m) a gagne !\n");
            scoreOrdi++;
            break;
        case CERCLE:
            printf("Bravo ! Vous (\x1b[36mO\x1b[0m) avez gagne !\n");
            scoreJoueur++;
            break;
        case 3:
            printf("Match nul !\n");
            scoreNul++;
            break;
        }
    }
    effaceConsole();
    printf("\x1b[31;5mGAME OVER\x1b[0m\n");
    printf("\x1b[1;4;33mScore final :\x1b[0m\n");
    printf("Joueur : %i\n", scoreJoueur);
    printf("Ordinateur : %i\n", scoreOrdi);
    printf("Match nul : %i\n\n", scoreNul);

    return 0;
}
