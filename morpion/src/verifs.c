/**
 * @file verifs.c
 * @brief Implémentation des fonctions de vérification
 */

#include "verifs.h"

bool verifEmplacementValide(int emplacement) {
    return (emplacement >= 1 && emplacement <= NB_CASES);
}

bool verifEmplacementLibre(char table[], int emplacement) {
    if (!verifEmplacementValide(emplacement)) {
        return false;
    }
    return (table[emplacement - 1] == CASE_VIDE);
}

bool verifLigne(char table[], int ligne) {
    int j;
    char premier = table[ligne * TAILLE];

    if (premier == CASE_VIDE) {
        return false;
    }

    for (j = 1; j < TAILLE; j++) {
        if (table[ligne * TAILLE + j] != premier) {
            return false;
        }
    }
    return true;
}

bool verifColonne(char table[], int colonne) {
    int i;
    char premier = table[colonne];

    if (premier == CASE_VIDE) {
        return false;
    }

    for (i = 1; i < TAILLE; i++) {
        if (table[i * TAILLE + colonne] != premier) {
            return false;
        }
    }
    return true;
}

bool verifDiagonalePrincipale(char table[]) {
    int i;
    char premier = table[0];

    if (premier == CASE_VIDE) {
        return false;
    }

    for (i = 1; i < TAILLE; i++) {
        if (table[i * TAILLE + i] != premier) {
            return false;
        }
    }
    return true;
}

bool verifDiagonaleSecondaire(char table[]) {
    int i;
    char premier = table[TAILLE - 1];

    if (premier == CASE_VIDE) {
        return false;
    }

    for (i = 1; i < TAILLE; i++) {
        if (table[i * TAILLE + (TAILLE - 1 - i)] != premier) {
            return false;
        }
    }
    return true;
}

bool verifVictoire(char table[]) {
    int i;

    /* Vérification des lignes */
    for (i = 0; i < TAILLE; i++) {
        if (verifLigne(table, i)) {
            return true;
        }
    }

    /* Vérification des colonnes */
    for (i = 0; i < TAILLE; i++) {
        if (verifColonne(table, i)) {
            return true;
        }
    }

    /* Vérification des diagonales */
    if (verifDiagonalePrincipale(table)) {
        return true;
    }

    if (verifDiagonaleSecondaire(table)) {
        return true;
    }

    return false;
}

bool verifNul(char table[]) {
    int i;
    for (i = 0; i < NB_CASES; i++) {
        if (table[i] == CASE_VIDE) {
            return false;
        }
    }
    return true;
}
