/**
 * @file dictionnaire.h
 * @brief Gestion du dictionnaire de mots
 */

#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#define LENGTH 7
#define MAX_MOTS 100
#define FICHIER_DICO "data/dico.txt"

/**
 * @brief Charge les mots depuis le fichier dictionnaire
 * @param mots Tableau de mots à remplir
 * @param fichier Chemin du fichier dictionnaire
 * @return Nombre de mots chargés, -1 si erreur
 */
int chargerDictionnaire(char mots[][LENGTH + 1], const char *fichier);

/**
 * @brief Choisit un mot aléatoire dans le dictionnaire
 * @param mots Tableau de mots
 * @param nb_mots Nombre de mots dans le tableau
 * @param mot_choisi Buffer pour stocker le mot choisi
 */
void choisirMotAleatoire(char mots[][LENGTH + 1], int nb_mots, char *mot_choisi);

#endif /* DICTIONNAIRE_H */
