/**
 * @file main.c
 * @brief Point d'entrée du jeu du Pendu
 */

#include "lib/dictionnaire.h"
#include "lib/pendu.h"
#include <stdio.h>

int main(void) {
    char mots[MAX_MOTS][LENGTH + 1];
    char mot_secret[LENGTH + 1];
    char mot_affiche[LENGTH + 1];
    char lettre;
    int nb_mots;
    int coups_restants;
    int trouve;

    /* Charger le dictionnaire */
    nb_mots = chargerDictionnaire(mots, FICHIER_DICO);
    if (nb_mots <= 0) {
        printf("Erreur: impossible de charger le dictionnaire\n");
        return 1;
    }

    /* Choisir un mot aléatoire */
    choisirMotAleatoire(mots, nb_mots, mot_secret);

    /* Initialiser le jeu */
    initialiserMotAffiche(mot_affiche);
    coups_restants = MAX_COUPS;

    /* Afficher le message de bienvenue */
    afficherBienvenue();

    /* Boucle principale du jeu */
    while (coups_restants > 0 && !motComplet(mot_affiche)) {
        afficherEtat(coups_restants, mot_affiche);
        lettre = demanderLettre();

        if (lettre == '\0') {
            continue;
        }

        trouve = verifierLettre(mot_secret, mot_affiche, lettre);

        if (!trouve) {
            coups_restants--;
        }
    }

    /* Afficher le résultat */
    if (motComplet(mot_affiche)) {
        afficherVictoire(mot_secret);
    } else {
        afficherDefaite(mot_secret);
    }

    return 0;
}
