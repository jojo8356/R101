/**
 * @file verifs.h
 * @brief Fonctions de vérification du jeu du Morpion
 */

#ifndef VERIFS_H
#define VERIFS_H

#include "config.h"
#include <stdbool.h>

/**
 * @brief Vérifie si un emplacement est valide (dans les bornes)
 * @param emplacement L'emplacement à vérifier (1 à NB_CASES)
 * @return true si l'emplacement est dans les bornes, false sinon
 */
bool verifEmplacementValide(int emplacement);

/**
 * @brief Vérifie si un emplacement est libre
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @param emplacement L'emplacement à vérifier (1 à NB_CASES)
 * @return true si l'emplacement est libre, false sinon
 */
bool verifEmplacementLibre(char table[], int emplacement);

/**
 * @brief Vérifie si une ligne contient une victoire
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @param ligne L'indice de la ligne à vérifier (0 à TAILLE-1)
 * @return true si la ligne est gagnante, false sinon
 */
bool verifLigne(char table[], int ligne);

/**
 * @brief Vérifie si une colonne contient une victoire
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @param colonne L'indice de la colonne à vérifier (0 à TAILLE-1)
 * @return true si la colonne est gagnante, false sinon
 */
bool verifColonne(char table[], int colonne);

/**
 * @brief Vérifie si la diagonale principale contient une victoire
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @return true si la diagonale principale est gagnante, false sinon
 */
bool verifDiagonalePrincipale(char table[]);

/**
 * @brief Vérifie si la diagonale secondaire contient une victoire
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @return true si la diagonale secondaire est gagnante, false sinon
 */
bool verifDiagonaleSecondaire(char table[]);

/**
 * @brief Vérifie si un joueur a gagné (lignes, colonnes, diagonales)
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @return true si un joueur a gagné, false sinon
 */
bool verifVictoire(char table[]);

/**
 * @brief Vérifie si la grille est pleine (match nul)
 * @param table Le tableau de caractères représentant le plateau de jeu
 * @return true si la grille est pleine, false sinon
 */
bool verifNul(char table[]);

#endif /* VERIFS_H */
