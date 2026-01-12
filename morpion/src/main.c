/**
 * @file main.c
 * @brief Point d'entrée du jeu du Morpion
 *
 * Machine à états :
 * - Start -> JeuMAJTable : Initialisation terminée
 * - JeuMAJTable -> JeuTestTable : Symbole inséré
 * - JeuTestTable -> FinVictoire : Un joueur a gagné
 * - JeuTestTable -> FinNul : Grille pleine sans gagnant
 * - JeuTestTable -> JeuMAJTable : Partie continue
 */

#include "config.h"
#include "jeu.h"
#include "ui.h"
#include "verifs.h"
#include <stdio.h>

/**
 * @brief Fonction principale du jeu de Morpion avec machine à états
 * @return 0 si le jeu se termine correctement
 */
int main(void) {
    char table[NB_CASES];
    char symbole = SYMBOLE_X; /* X commence toujours */
    char gagnant;
    int tour = 1;
    Etat etat = Start;

    /* Boucle principale : machine à états */
    while (etat != FinVictoire && etat != FinNul) {
        switch (etat) {
        case Start:
            /* Initialisation du jeu */
            initialiserTable(table);
            symbole = SYMBOLE_X;
            tour = 1;
            etat = JeuMAJTable;
            break;

        case JeuMAJTable:
            /* Affichage et demande de coup */
            afficherEntete(tour);
            afficherTable(table);
            printf("\n");
            insereSymbole(table, &symbole);
            etat = JeuTestTable;
            break;

        case JeuTestTable:
            /* Test de victoire ou match nul */
            if (verifVictoire(table)) {
                gagnant = getGagnant(symbole);
                etat = FinVictoire;
            } else if (verifNul(table)) {
                etat = FinNul;
            } else {
                tour++;
                etat = JeuMAJTable;
            }
            break;

        case FinVictoire:
        case FinNul:
            /* États finaux - ne devrait pas arriver ici */
            break;
        }
    }

    /* Affichage final */
    afficherTable(table);

    if (etat == FinVictoire) {
        afficherVictoire(gagnant);
    } else {
        afficherMatchNul();
    }

    return 0;
}
