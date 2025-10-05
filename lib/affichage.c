/**
 * @file affichage.c
 * @brief Module de fonctions d'affichages.
 */
#include "affichage.h"

#include <stdio.h>

/**
 * @brief Affiche une ligne de séparation.
 *
 * Cette fonction affiche une ligne de séparation de 80 -
 */
void afficheSep() {
  printf("\n");
  for (int i = 0; i < 80; i++) {
    printf("-");
  }
  printf("\n");
}

void print_csv() {
    char buffer[128];
    int col = 0;

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        printf("%s |",buffer);

        int c = getchar();
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            printf("%c", c);
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
}
