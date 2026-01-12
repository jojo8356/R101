/**
 * @file ui.h
 * @brief Interface utilisateur du jeu du Morpion
 */

#ifndef UI_H
#define UI_H

#include "config.h"

/**
 * @brief Efface l'écran de la console
 */
void effacerEcran(void);

/**
 * @brief Vide le buffer d'entrée standard
 */
void viderBuffer(void);

/**
 * @brief Affiche les caractères du tableau carré TAILLE x TAILLE
 * @param table Le tableau de caractères représentant le plateau de jeu
 */
void afficherTable(char table[]);

/**
 * @brief Affiche l'en-tête du jeu avec le numéro du tour
 * @param tour Numéro du tour actuel
 */
void afficherEntete(int tour);

/**
 * @brief Affiche le tour du joueur actuel
 * @param symbole Le symbole du joueur ('X' ou 'O')
 */
void afficherTourJoueur(char symbole);

/**
 * @brief Demande l'emplacement au joueur
 * @return L'emplacement saisi par le joueur (-1 si erreur de saisie)
 */
int demanderEmplacement(void);

/**
 * @brief Affiche un message d'erreur pour emplacement invalide
 */
void afficherErreurEmplacement(void);

/**
 * @brief Affiche le message de victoire
 * @param gagnant Le symbole du gagnant ('X' ou 'O')
 */
void afficherVictoire(char gagnant);

/**
 * @brief Affiche le message de match nul
 */
void afficherMatchNul(void);

/**
 * @brief Affiche la grille avec les numéros d'emplacement (aide)
 */
void afficherAide(void);

#endif /* UI_H */
