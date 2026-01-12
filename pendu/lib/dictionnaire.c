/**
 * @file dictionnaire.c
 * @brief Implémentation de la gestion du dictionnaire
 */

#include "dictionnaire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int chargerDictionnaire(char mots[][LENGTH + 1], const char *fichier) {
    FILE *f;
    int nb_mots = 0;
    char ligne[LENGTH + 3]; /* +3 pour \r\n\0 */

    f = fopen(fichier, "r");
    if (f == NULL) {
        return -1;
    }

    while (fgets(ligne, sizeof(ligne), f) != NULL && nb_mots < MAX_MOTS) {
        /* Supprimer le retour à la ligne */
        ligne[strcspn(ligne, "\r\n")] = '\0';

        /* Vérifier que le mot a la bonne longueur */
        if (strlen(ligne) == LENGTH) {
            strcpy(mots[nb_mots], ligne);
            nb_mots++;
        }
    }

    fclose(f);
    return nb_mots;
}

void choisirMotAleatoire(char mots[][LENGTH + 1], int nb_mots, char *mot_choisi) {
    int index;

    srand((unsigned int)time(NULL));
    index = rand() % nb_mots;
    strcpy(mot_choisi, mots[index]);
}
