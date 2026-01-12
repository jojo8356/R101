/**
 * @file jeu.c
 * @brief Implémentation de la logique du jeu
 */

#include "jeu.h"
#include "ui.h"
#include "verifs.h"

void initialiserTable(char table[]) {
    int i;
    for (i = 0; i < NB_CASES; i++) {
        table[i] = CASE_VIDE;
    }
}

void changerJoueur(char *symbole) {
    *symbole = (*symbole == SYMBOLE_X) ? SYMBOLE_O : SYMBOLE_X;
}

char getGagnant(char symbole) {
    return (symbole == SYMBOLE_X) ? SYMBOLE_O : SYMBOLE_X;
}

void insereSymbole(char table[], char *symbole) {
    int emplacement;
    int valide = 0;

    while (!valide) {
        afficherTourJoueur(*symbole);
        emplacement = demanderEmplacement();

        /* Vérifier que l'emplacement est valide */
        if (!verifEmplacementValide(emplacement)) {
            afficherErreurEmplacement();
            continue;
        }

        /* Vérifier que l'emplacement est libre */
        if (!verifEmplacementLibre(table, emplacement)) {
            afficherErreurEmplacement();
            continue;
        }

        /* Emplacement valide : insérer le symbole */
        table[emplacement - 1] = *symbole;
        valide = 1;
    }

    /* Changer de joueur */
    changerJoueur(symbole);
}
