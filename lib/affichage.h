/**
 * @file affichage.h
 * @brief Déclarations des fonctions d'affichage pour le programme de gestion.
 * @author ...
 * @date 2025
 */

#pragma once

/**
 * @brief Affiche une ligne de séparation standard dans la console.
 */
void afficheSep();

/**
 * @brief Affiche les informations d'une personne à partir d'un fichier CSV.
 * @param person_type Type de personne à afficher ("client" ou "caissière").
 */
void print_person_csv(char person_type[]);

/**
 * @brief Affiche la liste complète des clients à partir du fichier CSV.
 */
void print_clients_csv();

/**
 * @brief Affiche la liste complète des caissières à partir du fichier CSV.
 */
void print_caissieres_csv();

/**
 * @brief Affiche l'ID d'une caissière à partir de son nom et prénom.
 * @param target_nom Nom de la caissière.
 * @param target_prenom Prénom de la caissière.
 */
void print_ID_caissiere(char *target_nom, char *target_prenom);

/**
 * @brief Affiche toutes les informations d'une caissière à partir de son ID.
 * @param target_caissiere_id Identifiant de la caissière.
 */
void print_infos_caissiere(int target_caissiere_id);

/**
 * @brief Affiche le chiffre d'affaires total de la journée.
 */
void print_CA_day();

/**
 * @brief Calcule et affiche la moyenne des achats d'un client donné.
 * @param target_client_id Identifiant du client.
 */
void print_moyenne_client(int target_client_id);

/**
 * @brief Affiche le nombre total de tickets enregistrés.
 */
void print_nb_ticket();

/**
 * @brief Affiche le nombre de tickets associés à un client spécifique.
 * @param target_client_id Identifiant du client.
 */
void print_nb_ticket_client(int target_client_id);

/**
 * @brief Affiche les ventes de la journée à partir du fichier CSV.
 */
void print_day_csv();

/**
 * @brief Affiche une ligne de séparation personnalisée avec une longueur donnée.
 * @param longueur Nombre de caractères composant la ligne de séparation.
 */
void afficherLigneSeparation(int longueur);

/**
 * @brief Affiche un texte avec gestion des caractères spéciaux (ex: guillemets, virgules).
 * @param buffer Chaîne à afficher.
 * @param total Longueur totale du champ à afficher.
 */
void print_char_with_special_char(char *buffer, int total);

/**
 * @brief Affiche l’ID d’un client à partir de son nom et prénom.
 *
 * Cette fonction recherche le client correspondant aux informations fournies
 * et affiche directement son ID sur la sortie standard (stdout).
 *
 * @param target_nom Nom du client recherché.
 * @param target_prenom Prénom du client recherché.
 */
void print_ID_client(char *target_nom, char *target_prenom);

/**
 * @brief Affiche les caissières travaillant dans une tranche horaire donnée.
 *
 * @param start_hour Heure de début (ex: 9 pour 9h00).
 * @param end_hour Heure de fin (ex: 17 pour 17h00).
 */
void print_caissieres_by_time(int start_hour, int end_hour);

/**
 * @brief Affiche un message d'erreur indiquant qu'une option nécessite des arguments.
 *
 * Cette fonction écrit sur la sortie d'erreur standard (stderr) un message
 * précisant que l'option fournie nécessite des arguments supplémentaires.
 *
 * @param option Chaîne représentant l'option pour laquelle les arguments sont manquants.
 */
void print_error_missing_args(const char *option);

/**
 * @brief Affiche un message d'erreur indiquant qu'une option est inconnue.
 *
 * Cette fonction écrit sur la sortie d'erreur standard (stderr) un message
 * précisant que l'option fournie n'est pas reconnue par le programme.
 *
 * @param option Chaîne représentant l'option inconnue.
 */
void print_error_unknown_option(const char *option);

/**
 * @brief Affiche le message d'aide pour l'utilisation du programme.
 *
 * Cette fonction liste toutes les options disponibles du programme ainsi que
 * leurs arguments attendus et une courte description de leur utilité.
 */
void print_help();
