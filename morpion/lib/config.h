/**
 * @file config.h
 * @brief Configuration du jeu du Morpion
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Taille de la grille (modifiable pour 4x4, 5x5, etc.) */
#define TAILLE 3

/* Nombre total de cases */
#define NB_CASES (TAILLE * TAILLE)

/* Symboles des joueurs */
#define SYMBOLE_X 'X'
#define SYMBOLE_O 'O'
#define CASE_VIDE '-'

/* États de la machine à états */
typedef enum {
    Start,        /* État initial : initialisation du jeu */
    JeuMAJTable,  /* Mise à jour de la table : demande et insertion du symbole */
    JeuTestTable, /* Test de la table : vérification victoire/nul */
    FinVictoire,  /* État final : un joueur a gagné */
    FinNul        /* État final : match nul */
} Etat;

#endif /* CONFIG_H */
