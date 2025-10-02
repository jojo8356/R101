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