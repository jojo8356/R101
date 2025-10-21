/**
 * @file utils.h
 * @brief Déclarations des fonctions utilitaires pour chaînes, temps et CSV.
 */

#pragma once
#include <stddef.h>

/**
 * @brief Calcule la différence en secondes entre deux timestamps.
 * @param t1 Premier timestamp (format "YYYY-MM-DD HH:MM:SS").
 * @param t2 Deuxième timestamp (format "YYYY-MM-DD HH:MM:SS").
 * @return Nombre de secondes entre t2 et t1.
 */
int diff_seconds(const char *t1, const char *t2);

/**
 * @brief Formate un temps en secondes dans une chaîne lisible (minutes et secondes).
 * @param total_sec Temps total en secondes.
 * @param out Chaîne de sortie (format : "X min Y sec").
 */
void format_time(int total_sec, char *out);

/**
 * @brief Vérifie si une chaîne est incluse dans une liste de chaînes.
 * @param list Liste de chaînes.
 * @param taille Taille de la liste.
 * @param str Chaîne à rechercher.
 * @return 1 si trouvée, 0 sinon.
 */
int include_char(char **list, int taille, char *str);

/**
 * @brief Récupère l’ID d’une caissière à partir de son nom et prénom.
 * @param target_nom Nom de la caissière.
 * @param target_prenom Prénom de la caissière.
 * @return ID de la caissière sous forme de chaîne.
 */
char *get_ID_caissiere(char *target_nom, char *target_prenom);

/**
 * @brief Récupère les informations d’une caissière à partir de son ID.
 * @param target_caissiere_id ID de la caissière.
 * @return Chaîne contenant le chiffre d’affaires, le nombre de tickets et le temps moyen.
 */
char *get_infos_caissiere(int target_caissiere_id);

/**
 * @brief Calcule la moyenne des achats d’un client.
 * @param target_client_id ID du client.
 * @return Moyenne sous forme de chaîne.
 */
char *get_moyenne_client(int target_client_id);

/**
 * @brief Récupère le nombre total de tickets dans le fichier CSV.
 * @return Nombre de tickets sous forme de chaîne.
 */
char *get_nb_ticket();

/**
 * @brief Récupère le nombre de tickets pour un client spécifique.
 * @param target_client_id ID du client.
 * @return Nombre de tickets sous forme de chaîne.
 */
char *get_nb_ticket_client(int target_client_id);

/**
 * @brief Calcule le chiffre d’affaires total de la journée.
 * @return Chaîne contenant le CA et le nombre de tickets.
 */
char *get_CA_day();

/**
 * @brief Détermine le nombre d’octets UTF-8 pour un caractère donné.
 * @param c Octet à analyser.
 * @return Nombre d’octets (1 à 4).
 */
int len_utf8_chars(unsigned char c);

/**
 * @brief Calcule la longueur d’une chaîne de caractères.
 * @param s Chaîne à mesurer.
 * @return Nombre de caractères.
 */
size_t strlen(const char *s);

/**
 * @brief Lit un élément d’un CSV en gérant les guillemets et délimiteurs.
 * @param buffer Chaîne où stocker l’élément lu.
 * @param c Pointeur sur le caractère courant.
 * @param i Pointeur sur l’indice d’insertion dans buffer.
 * @param is_quote Pointeur sur l’état de guillemet (0 ou 1).
 * @param taille Taille maximale de buffer.
 */
void get_element(char *buffer, int *c, int *i, int *is_quote, int taille, char separator);

/**
 * @brief Ignore les caractères jusqu’à la fin de la ligne ou EOF.
 */
void verif_file();

/**
 * @brief Récupère l’ID d’un client à partir de son nom et prénom.
 *
 * @param target_nom Nom du client recherché.
 * @param target_prenom Prénom du client recherché.
 * @return char* Chaîne contenant l’ID du client. La mémoire peut être statique.
 */
char *get_ID_client(char *target_nom, char *target_prenom);

/**
 * @brief Récupère les caissières travaillant dans une tranche horaire donnée.
 *
 * @param start_hour Heure de début (ex: 9 pour 9h00).
 * @param end_hour Heure de fin (ex: 17 pour 17h00).
 * @return char* Chaîne contenant les IDs des caissières séparés par des virgules.
 *              La mémoire est statique.
 */
char *get_caissieres_by_time(int start_hour, int end_hour);

/**
 * @brief Concatène au maximum n caractères de s2 à la fin de s1.
 *
 * Cette fonction ajoute les n premiers caractères de la chaîne s2 à la fin
 * de la chaîne s1. La chaîne résultante s1 doit être suffisamment grande
 * pour contenir le résultat. Le caractère nul final est ajouté à la fin.
 *
 * @param s1 Chaîne de destination, qui sera modifiée.
 * @param s2 Chaîne source à concaténer.
 * @param n Nombre maximum de caractères à prendre dans s2.
 * @return char* Pointeur vers la chaîne s1.
 */
char *strncat(char *s1, const char *s2, size_t n);

/**
 * @brief Récupérer le nom et prénom d'une personne à partir de l'id.
 * @param target_id id cible
 * @return Nom et prénom
 */
char *get_identite_caissiere(int target_id);