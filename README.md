# Morpion
Jeux de morpion réaliser en langage C

## Comment compiler le projet

- Utiliser la commande `make`
- Executer le fichier avec la commande `./morpion`

> [!NOTE]
> Sous windows il possible que la commande `make` ne fonctionne pas, dans ce cas il faut se servir de `mingw32-make`

> [!NOTE]
> Il est possible de supprimer les fichier construit avec la commande `make clean`

## Module

### grille.c

Ce fichier contient toute les fonction qui sont lié à la gestion de la grille:

- `void setGrilleVide(int grille[TAILLE][TAILLE]);` :
Cette fonction permet de réintialiser la grille en vidant toute les cases

- `void afficheGrille(int grille[TAILLE][TAILLE]);`:
Cette fonction affiche les contour de la grille en utilisant des caractère unicode (┌,┐,└,┘,┬,┴,┼,├,┤,─)

- `void afficheCaseCouleur(int camp);`:
Cette fonction affiche le caractère en fonction de son "camp". Elle affiche, une croix rouge, un cercle bleue, ou un espace vide

- `bool estCaseVide(int grille[TAILLE][TAILLE],int ligne, int colone);`:
Cette fonction renvoie `True` si la case spécifier du tableau est vide

- `void effaceConsole();`:
Cette fonction efface l'affichage de la console

- `bool estCoupValide(int grille[TAILLE][TAILLE],int ligne, int colone);` :
Vérifie qu'un coup est jouable (contenue dans la grille et vise une case vide)
