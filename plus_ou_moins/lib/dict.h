/**
 * @file dict.h
 * @brief Gestion du dictionnaire des scores des joueurs
 */

#ifndef DICT_H
#define DICT_H

#include "config.h"

/* Taille max pour le tableau (fixe car besoin à la compilation) */
#define DICT_MAX_JOUEURS 100
#define DICT_MAX_NOM 50

/**
 * @brief Structure représentant un joueur et ses statistiques
 */
typedef struct {
    char nom[DICT_MAX_NOM];
    int meilleur_score;   /* Meilleur nombre d'essais (plus petit = mieux) */
    int parties_jouees;
    int parties_gagnees;
} Joueur;

/**
 * @brief Structure contenant tous les joueurs (dictionnaire)
 */
typedef struct {
    Joueur joueurs[DICT_MAX_JOUEURS];
    int nb_joueurs;
} DictScores;

/**
 * @brief Initialise un dictionnaire de scores vide
 * @param dict Pointeur vers le dictionnaire à initialiser
 */
void init_dict_scores(DictScores *dict);

/**
 * @brief Parse une ligne du fichier scores et remplit un joueur
 * @param ligne La ligne à parser (format: nom:meilleur_score:parties_jouees:parties_gagnees)
 * @param joueur Pointeur vers le joueur à remplir
 * @return 1 si parsing réussi, 0 sinon
 */
int parser_ligne_score(const char *ligne, Joueur *joueur);

/**
 * @brief Charge les scores depuis le fichier
 * @param dict Pointeur vers le dictionnaire à remplir
 * @return 1 si chargement réussi, 0 sinon
 */
int charger_scores(DictScores *dict);

/**
 * @brief Sauvegarde les scores dans le fichier
 * @param dict Pointeur vers le dictionnaire à sauvegarder
 * @return 1 si sauvegarde réussie, 0 sinon
 */
int sauvegarder_scores(const DictScores *dict);

/**
 * @brief Recherche un joueur par son nom dans le dictionnaire
 * @param dict Pointeur vers le dictionnaire
 * @param nom Nom du joueur à rechercher
 * @return Index du joueur si trouvé, -1 sinon
 */
int trouver_joueur(const DictScores *dict, const char *nom);

/**
 * @brief Ajoute ou met à jour un joueur dans le dictionnaire
 * @param dict Pointeur vers le dictionnaire
 * @param nom Nom du joueur
 * @param score Score de la partie (0 si défaite)
 */
void maj_joueur(DictScores *dict, const char *nom, int score);

/**
 * @brief Récupère les stats d'un joueur
 * @param dict Pointeur vers le dictionnaire
 * @param nom Nom du joueur
 * @return Pointeur vers le joueur ou NULL si non trouvé
 */
Joueur *get_joueur(DictScores *dict, const char *nom);

#endif /* DICT_H */
