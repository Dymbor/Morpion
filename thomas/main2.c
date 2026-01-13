#include <stdio.h>
#include <stdlib.h>

#define TAILLE 4
#define VIDE ' '
#define CROIX 'O'
#define CERCLE 'X'

void afficheTableau(char tab[TAILLE][TAILLE]) {
  printf("   ");
  for (int i = 1; i <= TAILLE; i++)
    printf(" %d ", i);
  printf("\n");

  for (int i = 0; i < TAILLE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < TAILLE; j++)
      printf("[%c]", tab[i][j]);
    printf("\n");
  }
}

// renvoie 1 si un joueur a gagné
int partieEstFini(char tab[TAILLE][TAILLE], char *gagnant) {

  // check les lignes
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE - 2; j++) {
      char c = tab[i][j];
      if (c != VIDE && c == tab[i][j + 1] && c == tab[i][j + 2]) {
        *gagnant = c;
        return 1;
      }
    }

  // checks les colonnes
  for (int j = 0; j < TAILLE; j++)
    for (int i = 0; i < TAILLE - 2; i++) {
      char c = tab[i][j];
      if (c != VIDE && c == tab[i + 1][j] && c == tab[i + 2][j]) {
        *gagnant = c;
        return 1;
      }
    }

  // checks les diagonales droites
  for (int i = 0; i < TAILLE - 2; i++)
    for (int j = 0; j < TAILLE - 2; j++) {
      char c = tab[i][j];
      if (c != VIDE && c == tab[i + 1][j + 1] && c == tab[i + 2][j + 2]) {
        *gagnant = c;
        return 1;
      }
    }

  // checks les diagonales gauche
  for (int i = 0; i < TAILLE - 2; i++)
    for (int j = 2; j < TAILLE; j++) {
      char c = tab[i][j];
      if (c != VIDE && c == tab[i + 1][j - 1] && c == tab[i + 2][j - 2]) {
        *gagnant = c;
        return 1;
      }
    }

  return 0;
}

int main() {
  char tab[TAILLE][TAILLE];
  int boucle = 1;
  char joueur = CROIX;
  char gagnant = VIDE;

  // initialisation tableau
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      tab[i][j] = VIDE;

  while (boucle == 1) {
    afficheTableau(tab);

    printf("\n au tour du joueur %c\n", joueur);

    int x, y;
    printf("entrer x,y : ");
    scanf("%d,%d", &x, &y);

    if (x < 1 || x > TAILLE || y < 1 || y > TAILLE) {
      printf("cordonnees n'existe pas !\n");
      continue;
    }

    if (tab[x - 1][y - 1] != VIDE) {
      printf("case deja prise !\n");
      continue;
    }

    // place du joueur
    tab[x - 1][y - 1] = joueur;

    // verifie fin
    if (partieEstFini(tab, &gagnant)) {
      boucle = 0;
    } else {
      // change de joueur
      switch (joueur) {
      case CROIX:
        joueur = CERCLE;
        break;
      case CERCLE:
        joueur = CROIX;
        break;
      }
    }
  }

  printf("\n--- fin de partie ---\n");
  afficheTableau(tab);

  if (gagnant == CROIX)
    printf("le joueur 1 (O) gagne \n");
  else if (gagnant == CERCLE)
    printf("le joueur 2 (X) gagne \n");

  return 0;
}
