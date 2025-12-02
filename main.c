#include <stdio.h>
#include <stdlib.h>
#include "headers/grille.h"
#include "headers/joueur.h"
#include "headers/bot.h"

int main()
{
    int grille[TAILLE][TAILLE];
    char coordLettre[3];       // pour stocker "A1" (+ '\0')
    int coordConvertie[2];     // stock les coordonees converti en chiffre pour le tableau
    int resultat = 0;          

    setGrilleVide(grille);

    while ((resultat = estPartieFinie(grille)) == 0)
    {
        afficheGrille(grille);

        // --- Tour du joueur ---
        printf("Joueur, entrez des coordonnee (ex: A1, B3) : ");
        scanf("%2s", coordLettre);
        convertitCoordonnees(coordLettre, coordConvertie);

        // Vérification du coup
        while (!estCoupValide(grille, coordConvertie[1], coordConvertie[0]))
        {
            printf("Coup invalide, reessayez : ");
            scanf("%2s", coordLettre);
            convertitCoordonnees(coordLettre, coordConvertie);
        }

        jouerCoup(grille, coordConvertie[1], coordConvertie[0], CERCLE);

        // Vérification si le joueur gagne
        resultat = estPartieFinie(grille);
        if (resultat != 0) break;

        effaceConsole();

        // --- Tour du bot ---
        jouerBot(grille);
        printf("Tour du bot...\n");

        resultat = estPartieFinie(grille);
    }

    effaceConsole();
    afficheGrille(grille);

    // --- Résultat final ---
    switch (resultat)
    {
    case CROIX:
        printf("Le bot (\x1b[31mX\x1b[0m) a gagne !\n");
        break;
    case CERCLE:
        printf("Bravo ! Vous (\x1b[36mO\x1b[0m) avez gagne !\n");
        break;
    case 3:
        printf("Match nul !\n");
        break;
    default:
        printf("Erreur dans le resultat.\n");
        break;
    }

    return 0;
}
