/**
 * @file config.c
 * @brief Parser YAML simplifié pour la configuration
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Variable globale de configuration */
Config g_config;

/**
 * @brief Supprime les espaces en début et fin de chaîne
 */
static char *trim(char *str) {
    char *end;

    /* Espaces en début */
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return str;
    }

    /* Espaces en fin */
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    end[1] = '\0';
    return str;
}

/**
 * @brief Extrait une valeur string (enlève les guillemets)
 */
static void get_string_value(const char *value, char *dest, int max_len) {
    const char *start = value;
    const char *end;
    int len;

    /* Ignorer les guillemets */
    if (*start == '"') {
        start++;
    }

    end = start + strlen(start) - 1;
    if (*end == '"') {
        len = (int)(end - start);
    } else {
        len = (int)strlen(start);
    }

    if (len >= max_len) {
        len = max_len - 1;
    }

    strncpy(dest, start, (size_t)len);
    dest[len] = '\0';
}

void config_defaut(void) {
    /* Chemins par défaut */
    strcpy(g_config.fichier_titre, "assets/titre.txt");
    strcpy(g_config.fichier_scores, "assets/scores.txt");

    /* Limites par défaut */
    g_config.max_joueurs = 100;
    g_config.max_nom = 50;
    g_config.min_nombre = 1;

    /* Proximité par défaut */
    g_config.seuil_bouillant = 2;
    g_config.seuil_chaud = 5;

    /* Difficultés par défaut */
    g_config.facile.max_nombre = 50;
    g_config.facile.essais = 10;

    g_config.normal.max_nombre = 100;
    g_config.normal.essais = 7;

    g_config.difficile.max_nombre = 200;
    g_config.difficile.essais = 8;

    g_config.expert.max_nombre = 500;
    g_config.expert.essais = 9;
}

int charger_config(void) {
    FILE *fichier;
    char ligne[MAX_LINE];
    char *value;
    char section[64] = "";
    char sous_section[64] = "";

    /* Valeurs par défaut d'abord */
    config_defaut();

    fichier = fopen(CONFIG_FILE, "r");
    if (fichier == NULL) {
        printf("Note: config.yml non trouvé, utilisation des valeurs par défaut.\n");
        return 0;
    }

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char *trimmed = trim(ligne);

        /* Ignorer commentaires et lignes vides */
        if (trimmed[0] == '#' || trimmed[0] == '\0') {
            continue;
        }

        /* Détecter les sections (pas d'indentation) */
        if (trimmed[0] != ' ' && strchr(trimmed, ':') != NULL) {
            char *colon = strchr(trimmed, ':');
            *colon = '\0';
            strncpy(section, trimmed, sizeof(section) - 1);
            sous_section[0] = '\0';
            continue;
        }

        /* Détecter les sous-sections (2 espaces) */
        if (ligne[0] == ' ' && ligne[1] == ' ' && ligne[2] != ' ') {
            char *key = trim(ligne);
            char *colon = strchr(key, ':');
            if (colon != NULL) {
                value = trim(colon + 1);
                *colon = '\0';
                key = trim(key);

                /* Si pas de valeur après ':', c'est une sous-section */
                if (strlen(value) == 0) {
                    strncpy(sous_section, key, sizeof(sous_section) - 1);
                    continue;
                }

                /* Sinon c'est une clé-valeur dans la section courante */
                if (strcmp(section, "fichiers") == 0) {
                    if (strcmp(key, "titre") == 0) {
                        get_string_value(value, g_config.fichier_titre, MAX_PATH);
                    } else if (strcmp(key, "scores") == 0) {
                        get_string_value(value, g_config.fichier_scores, MAX_PATH);
                    }
                } else if (strcmp(section, "limites") == 0) {
                    if (strcmp(key, "max_joueurs") == 0) {
                        g_config.max_joueurs = atoi(value);
                    } else if (strcmp(key, "max_nom") == 0) {
                        g_config.max_nom = atoi(value);
                    } else if (strcmp(key, "min_nombre") == 0) {
                        g_config.min_nombre = atoi(value);
                    }
                } else if (strcmp(section, "proximite") == 0) {
                    if (strcmp(key, "seuil_bouillant") == 0) {
                        g_config.seuil_bouillant = atoi(value);
                    } else if (strcmp(key, "seuil_chaud") == 0) {
                        g_config.seuil_chaud = atoi(value);
                    }
                }
            }
            continue;
        }

        /* Valeurs dans les sous-sections (4 espaces) */
        if (ligne[0] == ' ' && ligne[1] == ' ' && ligne[2] == ' ' && ligne[3] == ' ') {
            char *key = trim(ligne);
            char *colon = strchr(key, ':');
            if (colon != NULL) {
                value = trim(colon + 1);
                *colon = '\0';
                key = trim(key);

                if (strcmp(section, "difficulte") == 0) {
                    NiveauDifficulte *niveau = NULL;

                    if (strcmp(sous_section, "facile") == 0) {
                        niveau = &g_config.facile;
                    } else if (strcmp(sous_section, "normal") == 0) {
                        niveau = &g_config.normal;
                    } else if (strcmp(sous_section, "difficile") == 0) {
                        niveau = &g_config.difficile;
                    } else if (strcmp(sous_section, "expert") == 0) {
                        niveau = &g_config.expert;
                    }

                    if (niveau != NULL) {
                        if (strcmp(key, "max_nombre") == 0) {
                            niveau->max_nombre = atoi(value);
                        } else if (strcmp(key, "essais") == 0) {
                            niveau->essais = atoi(value);
                        }
                    }
                }
            }
        }
    }

    fclose(fichier);
    return 1;
}
