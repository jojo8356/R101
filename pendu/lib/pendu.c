/**
 * @file pendu.c
 * @brief Implémentation des fonctions du jeu du Pendu
 */

#include "pendu.h"
#include <stdio.h>
#include <ctype.h>

void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void initialiserMotAffiche(char *mot_affiche) {
    int i;

    for (i = 0; i < LENGTH; i++) {
        mot_affiche[i] = '*';
    }
    mot_affiche[LENGTH] = '\0';
}

int verifierLettre(const char *mot_secret, char *mot_affiche, char lettre) {
    int i;
    int trouve = 0;

    lettre = (char)toupper((unsigned char)lettre);

    for (i = 0; i < LENGTH; i++) {
        if (mot_secret[i] == lettre) {
            mot_affiche[i] = lettre;
            trouve = 1;
        }
    }

    return trouve;
}

int motComplet(const char *mot_affiche) {
    int i;

    for (i = 0; i < LENGTH; i++) {
        if (mot_affiche[i] == '*') {
            return 0;
        }
    }

    return 1;
}

char demanderLettre(void) {
    char lettre;
    int c;

    printf(" Proposez une lettre: ");

    c = getchar();
    if (c == '\n' || c == EOF) {
        return '\0';
    }

    lettre = (char)toupper((unsigned char)c);

    /* Vider le reste de la ligne */
    if (c != '\n') {
        viderBuffer();
    }

    return lettre;
}

void afficherEtat(int coups_restants, const char *mot_affiche) {
    printf("\n Il vous reste %d coup%s a jouer\n",
           coups_restants, (coups_restants > 1) ? "s" : "");
    printf(" Quel est le mot secret? %s\n", mot_affiche);
}

void afficherBienvenue(void) {
    printf("Bienvenue dans le jeu du pendu\n");
}

void afficherVictoire(const char *mot_secret) {
    printf("\n\n Gagne ! Le mot secret etait bien: %s\n", mot_secret);
}

void afficherDefaite(const char *mot_secret) {
    printf("\n\n Perdu ! Le mot secret etait: %s\n", mot_secret);
}
