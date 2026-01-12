/**
 * @file jeu.h
 * @brief Logique du jeu du Morpion
 */

#ifndef JEU_H
#define JEU_H

#include "config.h"

/**
 * @brief Initialise la grille de jeu avec des cases vides
 * @param table Le tableau de caractères représentant le plateau de jeu
 */
void initialiserTable(char table[]);

/**
 * @brief Demande au joueur la position d'insertion et insère son symbole
 *
 * L'emplacement est rejeté s'il n'est pas dans le tableau ou s'il correspond
 * à un emplacement déjà occupé.
 *
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @param symbole Pointeur vers le symbole du joueur ('X' ou 'O'), sera modifié
 */
void insereSymbole(char table[], char *symbole);

/**
 * @brief Alterne le symbole du joueur
 * @param symbole Pointeur vers le symbole actuel
 */
void changerJoueur(char *symbole);

/**
 * @brief Récupère le symbole du gagnant (après changement de joueur)
 * @param symbole Le symbole actuel (après changement)
 * @return Le symbole du gagnant
 */
char getGagnant(char symbole);

#endif /* JEU_H */
