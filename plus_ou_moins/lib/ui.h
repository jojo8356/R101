/**
 * @file ui.h
 * @brief Interface utilisateur - Affichages et saisies
 */

#ifndef UI_H
#define UI_H

#include "dict.h"
#include "config.h"

/**
 * @brief Efface l'écran de la console (compatible Windows/Linux)
 */
void effacer_ecran(void);

/**
 * @brief Vide le buffer d'entrée standard
 */
void vider_buffer(void);

/**
 * @brief Affiche le titre du jeu depuis le fichier titre.txt
 */
void afficher_titre(void);

/**
 * @brief Affiche un message de victoire
 */
void afficher_victoire(void);

/**
 * @brief Affiche un message de défaite
 */
void afficher_defaite(void);

/**
 * @brief Affiche l'indice de proximité selon la différence
 * @param difference Valeur absolue de la différence entre le nombre saisi et le secret
 */
void afficher_proximite(int difference);

/**
 * @brief Affiche le menu de sélection de difficulté
 * @param max_nombre Pointeur vers le nombre maximum (sera modifié)
 * @param max_essais Pointeur vers le nombre d'essais (sera modifié)
 */
void afficher_menu_difficulte(int *max_nombre, int *max_essais);

/**
 * @brief Affiche le menu principal
 * @return Le choix de l'utilisateur
 */
int afficher_menu_principal(void);

/**
 * @brief Affiche le classement des joueurs
 * @param dict Pointeur vers le dictionnaire
 */
void afficher_classement(const DictScores *dict);

/**
 * @brief Affiche les règles de la partie
 * @param min_nombre Nombre minimum
 * @param max_nombre Nombre maximum
 * @param max_essais Nombre d'essais
 */
void afficher_regles(int min_nombre, int max_nombre, int max_essais);

/**
 * @brief Affiche le prompt d'essai
 * @param essai Numéro de l'essai actuel
 * @param max_essais Nombre total d'essais
 */
void afficher_prompt_essai(int essai, int max_essais);

/**
 * @brief Affiche une erreur de saisie
 */
void afficher_erreur_saisie(void);

/**
 * @brief Affiche une erreur de bornes
 * @param min_nombre Nombre minimum
 * @param max_nombre Nombre maximum
 */
void afficher_erreur_bornes(int min_nombre, int max_nombre);

/**
 * @brief Affiche le message de victoire avec le score
 * @param nombre_secret Le nombre qui a été trouvé
 * @param essais Nombre d'essais utilisés
 */
void afficher_message_victoire(int nombre_secret, int essais);

/**
 * @brief Affiche le message de défaite avec le nombre secret
 * @param nombre_secret Le nombre à trouver
 */
void afficher_message_defaite(int nombre_secret);

/**
 * @brief Affiche l'indice "trop petit" ou "trop grand"
 * @param tentative La tentative du joueur
 * @param nombre_secret Le nombre à trouver
 */
void afficher_indice_direction(int tentative, int nombre_secret);

/**
 * @brief Demande le nom du joueur
 * @param nom Buffer pour stocker le nom
 * @param taille Taille du buffer
 */
void demander_nom_joueur(char *nom, int taille);

/**
 * @brief Affiche le message de bienvenue pour un nouveau joueur
 * @param nom Nom du joueur
 */
void afficher_bienvenue(const char *nom);

/**
 * @brief Affiche le message de retour pour un joueur existant
 * @param joueur Pointeur vers le joueur
 */
void afficher_bon_retour(const Joueur *joueur);

/**
 * @brief Affiche le record personnel du joueur
 * @param meilleur_score Le meilleur score du joueur
 */
void afficher_record_personnel(int meilleur_score);

/**
 * @brief Affiche le message de fin de jeu
 * @param nom_joueur Nom du joueur
 * @param joueur Pointeur vers le joueur (peut être NULL)
 */
void afficher_message_fin(const char *nom_joueur, const Joueur *joueur);

#endif /* UI_H */
