/**
 * @file ui.c
 * @brief Implémentation de l'interface utilisateur
 */

#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void effacer_ecran(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void vider_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void afficher_titre(void) {
    FILE *fichier;
    char ligne[256];

    fichier = fopen(g_config.fichier_titre, "r");
    if (fichier == NULL) {
        /* Fallback si le fichier n'existe pas */
        printf("\n");
        printf("╔═══════════════════════════════╗\n");
        printf("║        JUSTE PRIX             ║\n");
        printf("╚═══════════════════════════════╝\n");
        return;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
}

void afficher_victoire(void) {
    printf("\n");
    printf("   ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
    printf("   ★                           ★\n");
    printf("   ★   FÉLICITATIONS !         ★\n");
    printf("   ★                           ★\n");
    printf("   ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★\n");
}

void afficher_defaite(void) {
    printf("\n");
    printf("   ╭─────────────────────────╮\n");
    printf("   │    GAME OVER !          │\n");
    printf("   │    Dommage...           │\n");
    printf("   ╰─────────────────────────╯\n");
}

void afficher_proximite(int difference) {
    if (difference <= g_config.seuil_bouillant) {
        printf("Bouillant!\n");
    } else if (difference <= g_config.seuil_chaud) {
        printf("Chaud!\n");
    } else {
        printf("Froid!\n");
    }
}

void afficher_menu_difficulte(int *max_nombre, int *max_essais) {
    int choix;

    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║     CHOISISSEZ LA DIFFICULTÉ       ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1. Facile   (1-%-3d, %2d essais)    ║\n",
           g_config.facile.max_nombre, g_config.facile.essais);
    printf("║  2. Normal   (1-%-3d, %2d essais)    ║\n",
           g_config.normal.max_nombre, g_config.normal.essais);
    printf("║  3. Difficile(1-%-3d, %2d essais)    ║\n",
           g_config.difficile.max_nombre, g_config.difficile.essais);
    printf("║  4. Expert   (1-%-3d, %2d essais)    ║\n",
           g_config.expert.max_nombre, g_config.expert.essais);
    printf("╚════════════════════════════════════╝\n");
    printf("\nVotre choix : ");

    if (scanf("%d", &choix) != 1) {
        vider_buffer();
        choix = 2; /* Par défaut : Normal */
    } else {
        vider_buffer();
    }

    switch (choix) {
    case 1: /* Facile */
        *max_nombre = g_config.facile.max_nombre;
        *max_essais = g_config.facile.essais;
        break;
    case 3: /* Difficile */
        *max_nombre = g_config.difficile.max_nombre;
        *max_essais = g_config.difficile.essais;
        break;
    case 4: /* Expert */
        *max_nombre = g_config.expert.max_nombre;
        *max_essais = g_config.expert.essais;
        break;
    case 2: /* Normal */
    default:
        *max_nombre = g_config.normal.max_nombre;
        *max_essais = g_config.normal.essais;
        break;
    }
}

int afficher_menu_principal(void) {
    int choix;

    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║           MENU PRINCIPAL           ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1. Jouer                          ║\n");
    printf("║  2. Voir le classement             ║\n");
    printf("║  3. Quitter                        ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("\nVotre choix : ");

    if (scanf("%d", &choix) != 1) {
        vider_buffer();
        return 1;
    }
    vider_buffer();

    return choix;
}

void afficher_classement(const DictScores *dict) {
    int i, j;
    int indices[DICT_MAX_JOUEURS];
    int temp;

    if (dict->nb_joueurs == 0) {
        printf("\nAucun score enregistré.\n");
        return;
    }

    /* Initialiser les indices */
    for (i = 0; i < dict->nb_joueurs; i++) {
        indices[i] = i;
    }

    /* Tri par meilleur score (tri à bulles) */
    for (i = 0; i < dict->nb_joueurs - 1; i++) {
        for (j = 0; j < dict->nb_joueurs - i - 1; j++) {
            int score_a = dict->joueurs[indices[j]].meilleur_score;
            int score_b = dict->joueurs[indices[j + 1]].meilleur_score;

            /* Les scores de 0 (jamais gagné) vont à la fin */
            if (score_a == 0 || (score_b != 0 && score_a > score_b)) {
                temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    /* Affichage */
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                    CLASSEMENT                              ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("║  #   Joueur          Record   Parties   Victoires   Ratio  ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");

    for (i = 0; i < dict->nb_joueurs && i < 10; i++) {
        const Joueur *j_ptr = &dict->joueurs[indices[i]];
        float ratio = 0;
        if (j_ptr->parties_jouees > 0) {
            ratio = (float)j_ptr->parties_gagnees / (float)j_ptr->parties_jouees * 100;
        }

        printf("║ %2d.  %-15s  ", i + 1, j_ptr->nom);
        if (j_ptr->meilleur_score > 0) {
            printf("%3d      ", j_ptr->meilleur_score);
        } else {
            printf(" -       ");
        }
        printf("%4d      %4d      %5.1f%%  ║\n",
               j_ptr->parties_jouees, j_ptr->parties_gagnees, ratio);
    }

    printf("╚════════════════════════════════════════════════════════════╝\n");
}

void afficher_regles(int min_nombre, int max_nombre, int max_essais) {
    printf("\n");
    printf("════════════════════════════════════════\n");
    printf("  Trouvez un nombre entre %d et %d !\n", min_nombre, max_nombre);
    printf("  Vous avez %d essais.\n", max_essais);
    printf("════════════════════════════════════════\n\n");
}

void afficher_prompt_essai(int essai, int max_essais) {
    printf("Essai %d/%d : ", essai, max_essais);
}

void afficher_erreur_saisie(void) {
    printf("Erreur : Veuillez entrer un nombre valide!\n\n");
}

void afficher_erreur_bornes(int min_nombre, int max_nombre) {
    printf("Erreur : Le nombre doit être entre %d et %d!\n\n", min_nombre, max_nombre);
}

void afficher_message_victoire(int nombre_secret, int essais) {
    afficher_victoire();
    printf("   Vous avez trouvé le nombre %d en %d essai%s!\n",
           nombre_secret, essais, (essais > 1) ? "s" : "");
}

void afficher_message_defaite(int nombre_secret) {
    afficher_defaite();
    printf("   Le nombre secret était : %d\n", nombre_secret);
}

void afficher_indice_direction(int tentative, int nombre_secret) {
    if (tentative < nombre_secret) {
        printf("Trop petit!\n");
    } else {
        printf("Trop grand!\n");
    }
}

void demander_nom_joueur(char *nom, int taille) {
    char *newline;

    printf("\nEntrez votre nom : ");

    if (fgets(nom, taille, stdin) != NULL) {
        /* Supprimer le retour à la ligne */
        newline = strchr(nom, '\n');
        if (newline) {
            *newline = '\0';
        }
    }

    /* Nom par défaut si vide */
    if (strlen(nom) == 0) {
        strcpy(nom, "Joueur");
    }
}

void afficher_bienvenue(const char *nom) {
    printf("\nBienvenue %s !\n", nom);
}

void afficher_bon_retour(const Joueur *joueur) {
    printf("\nBon retour %s !\n", joueur->nom);
    printf("Votre record : %d essai%s | Parties : %d | Victoires : %d\n",
           joueur->meilleur_score,
           (joueur->meilleur_score > 1) ? "s" : "",
           joueur->parties_jouees,
           joueur->parties_gagnees);
}

void afficher_record_personnel(int meilleur_score) {
    printf("\n   Votre record personnel : %d essai%s\n",
           meilleur_score, (meilleur_score > 1) ? "s" : "");
}

void afficher_message_fin(const char *nom_joueur, const Joueur *joueur) {
    printf("\n");
    printf("════════════════════════════════════════\n");
    printf("  Merci d'avoir joué %s !\n", nom_joueur);
    if (joueur != NULL) {
        printf("  Parties jouees: %d | Victoires: %d\n",
               joueur->parties_jouees,
               joueur->parties_gagnees);
        if (joueur->meilleur_score > 0) {
            printf("  Votre record : %d essai%s\n",
                   joueur->meilleur_score,
                   (joueur->meilleur_score > 1) ? "s" : "");
        }
    }
    printf("════════════════════════════════════════\n\n");
}
