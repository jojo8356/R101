/**
 * @file pendu.h
 * @brief Fonctions du jeu du Pendu
 */

#ifndef PENDU_H
#define PENDU_H

#include "dictionnaire.h"

#define MAX_COUPS 10

/**
 * @brief Initialise le mot affiché avec des étoiles
 * @param mot_affiche Buffer à initialiser
 */
void initialiserMotAffiche(char *mot_affiche);

/**
 * @brief Vérifie si la lettre est dans le mot et met à jour l'affichage
 * @param mot_secret Le mot à deviner
 * @param mot_affiche Le mot affiché (avec * pour les lettres non trouvées)
 * @param lettre La lettre proposée
 * @return 1 si la lettre est trouvée, 0 sinon
 */
int verifierLettre(const char *mot_secret, char *mot_affiche, char lettre);

/**
 * @brief Vérifie si le mot a été entièrement découvert
 * @param mot_affiche Le mot affiché
 * @return 1 si le mot est complet, 0 sinon
 */
int motComplet(const char *mot_affiche);

/**
 * @brief Demande une lettre au joueur
 * @return La lettre en majuscule
 */
char demanderLettre(void);

/**
 * @brief Affiche l'état du jeu
 * @param coups_restants Nombre de coups restants
 * @param mot_affiche Le mot affiché
 */
void afficherEtat(int coups_restants, const char *mot_affiche);

/**
 * @brief Affiche le message de bienvenue
 */
void afficherBienvenue(void);

/**
 * @brief Affiche le message de victoire
 * @param mot_secret Le mot qui a été trouvé
 */
void afficherVictoire(const char *mot_secret);

/**
 * @brief Affiche le message de défaite
 * @param mot_secret Le mot qui n'a pas été trouvé
 */
void afficherDefaite(const char *mot_secret);

/**
 * @brief Vide le buffer d'entrée
 */
void viderBuffer(void);

#endif /* PENDU_H */
