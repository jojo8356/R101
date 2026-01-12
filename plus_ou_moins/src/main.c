/**
 * @file main.c
 * @brief Jeu du "Juste Prix" - Point d'entrée principal
 *
 * L'ordinateur choisit un nombre aléatoire,
 * et le joueur doit le deviner en un nombre limité d'essais.
 */

#include "config.h"
#include "dict.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Calcule la valeur absolue d'un entier
 * @param x L'entier dont on veut la valeur absolue
 * @return La valeur absolue de x
 */
static int valeur_absolue(int x) {
    return (x < 0) ? -x : x;
}

/**
 * @brief Joue une partie du jeu
 * @return Le score (nombre d'essais utilisés si victoire, 0 si défaite)
 */
static int jouer_partie(void) {
    int nombre_secret;
    int tentative;
    int essai;
    int difference;
    int resultat_scanf;
    int max_nombre;
    int max_essais;
    int min_nombre = g_config.min_nombre;

    /* Choix de la difficulté */
    afficher_menu_difficulte(&max_nombre, &max_essais);

    /* Génération du nombre aléatoire */
    nombre_secret = (rand() % max_nombre) + min_nombre;

    /* Affichage des règles */
    afficher_regles(min_nombre, max_nombre, max_essais);

    /* Boucle principale du jeu */
    for (essai = 1; essai <= max_essais; essai++) {
        afficher_prompt_essai(essai, max_essais);

        /* Lecture et validation de l'entrée utilisateur */
        resultat_scanf = scanf("%d", &tentative);

        if (resultat_scanf != 1) {
            afficher_erreur_saisie();
            vider_buffer();
            essai--; /* Ne pas compter cet essai */
            continue;
        }
        vider_buffer();

        /* Vérification des bornes */
        if (tentative < min_nombre || tentative > max_nombre) {
            afficher_erreur_bornes(min_nombre, max_nombre);
            essai--; /* Ne pas compter cet essai */
            continue;
        }

        /* Le joueur a trouvé le nombre */
        if (tentative == nombre_secret) {
            afficher_message_victoire(nombre_secret, essai);
            return essai; /* Retourne le score */
        }

        /* Indices */
        afficher_indice_direction(tentative, nombre_secret);
        difference = valeur_absolue(tentative - nombre_secret);
        afficher_proximite(difference);
        printf("\n");
    }

    /* Le joueur a épuisé tous ses essais */
    afficher_message_defaite(nombre_secret);
    return 0; /* Score de 0 pour une défaite */
}

/**
 * @brief Point d'entrée principal du programme
 * @return 0 si le programme s'est exécuté correctement
 */
int main(void) {
    DictScores scores;
    char nom_joueur[DICT_MAX_NOM];
    int score;
    int choix;
    int continuer = 1;
    Joueur *joueur_actuel;

    /* Chargement de la configuration */
    charger_config();

    /* Initialisation du générateur de nombres aléatoires */
    srand((unsigned int)time(NULL));

    /* Chargement des scores */
    charger_scores(&scores);

    /* Affichage du titre */
    afficher_titre();

    /* Demander le nom du joueur */
    demander_nom_joueur(nom_joueur, DICT_MAX_NOM);

    /* Afficher les stats du joueur s'il existe */
    joueur_actuel = get_joueur(&scores, nom_joueur);
    if (joueur_actuel != NULL) {
        afficher_bon_retour(joueur_actuel);
    } else {
        afficher_bienvenue(nom_joueur);
    }

    /* Boucle principale */
    while (continuer) {
        choix = afficher_menu_principal();

        switch (choix) {
        case 1: /* Jouer */
            score = jouer_partie();

            /* Mise à jour des scores */
            maj_joueur(&scores, nom_joueur, score);
            sauvegarder_scores(&scores);

            /* Afficher les stats mises à jour */
            joueur_actuel = get_joueur(&scores, nom_joueur);
            if (joueur_actuel != NULL && joueur_actuel->meilleur_score > 0) {
                afficher_record_personnel(joueur_actuel->meilleur_score);
            }
            break;

        case 2: /* Classement */
            afficher_classement(&scores);
            break;

        case 3: /* Quitter */
            continuer = 0;
            break;

        default:
            printf("Choix invalide.\n");
            break;
        }
    }

    /* Message de fin */
    joueur_actuel = get_joueur(&scores, nom_joueur);
    afficher_message_fin(nom_joueur, joueur_actuel);

    return 0;
}
