/**
 * @file ui.c
 * @brief Implémentation de l'interface utilisateur
 */

#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

void effacerEcran(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void viderBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void afficherTable(char table[]) {
    int i, j;

    for (i = 0; i < TAILLE; i++) {
        for (j = 0; j < TAILLE; j++) {
            printf("%c ", table[i * TAILLE + j]);
        }
        printf("\n");
    }
}

void afficherEntete(int tour) {
    effacerEcran();
    printf("**************** JEU DU MORPION****************\n");
    printf("------------------------------------ tour n°%d/%d\n\n", tour, NB_CASES);
}

void afficherTourJoueur(char symbole) {
    printf("Tour du joueur %c\n", symbole);
}

int demanderEmplacement(void) {
    int emplacement;

    printf("Emplacement ?");

    if (scanf("%d", &emplacement) != 1) {
        viderBuffer();
        return -1;
    }

    return emplacement;
}

void afficherErreurEmplacement(void) {
    printf("\nVeuillez saisir un emplacement valide!\n");
}

void afficherVictoire(char gagnant) {
    printf("Joueur %c gagne\n", gagnant);
}

void afficherMatchNul(void) {
    printf("Match nul\n");
}

void afficherAide(void) {
    int i, j;
    int num = 1;

    printf("\nGrille des emplacements :\n");
    printf("-------------\n");
    for (i = 0; i < TAILLE; i++) {
        printf("|");
        for (j = 0; j < TAILLE; j++) {
            printf(" %d |", num++);
        }
        printf("\n-------------\n");
    }
    printf("\n");
}
