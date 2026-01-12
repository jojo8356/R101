/**
 * @file dict.c
 * @brief Implémentation du dictionnaire des scores des joueurs
 */

#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_dict_scores(DictScores *dict) {
    dict->nb_joueurs = 0;
}

int parser_ligne_score(const char *ligne, Joueur *joueur) {
    char copie[256];
    char *token;
    char *newline;
    int champ = 0;

    /* Ignorer les lignes vides ou commentaires */
    if (ligne[0] == '#' || ligne[0] == '\n' || ligne[0] == '\0') {
        return 0;
    }

    /* Copier la ligne pour ne pas modifier l'original */
    strncpy(copie, ligne, sizeof(copie) - 1);
    copie[sizeof(copie) - 1] = '\0';

    /* Supprimer le retour à la ligne */
    newline = strchr(copie, '\n');
    if (newline) {
        *newline = '\0';
    }

    /* Parser avec strtok (délimiteur ':') */
    token = strtok(copie, ":");
    while (token != NULL && champ < 4) {
        switch (champ) {
        case 0: /* Nom */
            strncpy(joueur->nom, token, DICT_MAX_NOM - 1);
            joueur->nom[DICT_MAX_NOM - 1] = '\0';
            break;
        case 1: /* Meilleur score */
            joueur->meilleur_score = atoi(token);
            break;
        case 2: /* Parties jouées */
            joueur->parties_jouees = atoi(token);
            break;
        case 3: /* Parties gagnées */
            joueur->parties_gagnees = atoi(token);
            break;
        }
        champ++;
        token = strtok(NULL, ":");
    }

    return (champ == 4); /* Succès si 4 champs parsés */
}

int charger_scores(DictScores *dict) {
    FILE *fichier;
    char ligne[256];
    Joueur joueur;

    init_dict_scores(dict);

    fichier = fopen(g_config.fichier_scores, "r");
    if (fichier == NULL) {
        return 0; /* Fichier non trouvé, pas grave */
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (parser_ligne_score(ligne, &joueur)) {
            if (dict->nb_joueurs < g_config.max_joueurs) {
                dict->joueurs[dict->nb_joueurs] = joueur;
                dict->nb_joueurs++;
            }
        }
    }

    fclose(fichier);
    return 1;
}

int sauvegarder_scores(const DictScores *dict) {
    FILE *fichier;
    int i;

    fichier = fopen(g_config.fichier_scores, "w");
    if (fichier == NULL) {
        return 0;
    }

    fprintf(fichier, "# Fichier des scores - Format: nom:meilleur_score:parties_jouees:parties_gagnees\n");

    for (i = 0; i < dict->nb_joueurs; i++) {
        fprintf(fichier, "%s:%d:%d:%d\n",
                dict->joueurs[i].nom,
                dict->joueurs[i].meilleur_score,
                dict->joueurs[i].parties_jouees,
                dict->joueurs[i].parties_gagnees);
    }

    fclose(fichier);
    return 1;
}

int trouver_joueur(const DictScores *dict, const char *nom) {
    int i;

    for (i = 0; i < dict->nb_joueurs; i++) {
        if (strcmp(dict->joueurs[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

void maj_joueur(DictScores *dict, const char *nom, int score) {
    int index = trouver_joueur(dict, nom);

    if (index == -1) {
        /* Nouveau joueur */
        if (dict->nb_joueurs >= g_config.max_joueurs) {
            printf("Erreur: Nombre maximum de joueurs atteint!\n");
            return;
        }
        index = dict->nb_joueurs;
        strncpy(dict->joueurs[index].nom, nom, DICT_MAX_NOM - 1);
        dict->joueurs[index].nom[DICT_MAX_NOM - 1] = '\0';
        dict->joueurs[index].meilleur_score = 0;
        dict->joueurs[index].parties_jouees = 0;
        dict->joueurs[index].parties_gagnees = 0;
        dict->nb_joueurs++;
    }

    /* Mise à jour des stats */
    dict->joueurs[index].parties_jouees++;

    if (score > 0) {
        dict->joueurs[index].parties_gagnees++;
        /* Mise à jour du meilleur score (plus petit = mieux) */
        if (dict->joueurs[index].meilleur_score == 0 ||
            score < dict->joueurs[index].meilleur_score) {
            dict->joueurs[index].meilleur_score = score;
        }
    }
}

Joueur *get_joueur(DictScores *dict, const char *nom) {
    int index = trouver_joueur(dict, nom);
    if (index == -1) {
        return NULL;
    }
    return &dict->joueurs[index];
}
