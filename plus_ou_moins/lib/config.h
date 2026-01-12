/**
 * @file config.h
 * @brief Gestion de la configuration depuis config.yml
 */

#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_FILE "config.yml"
#define MAX_LINE 256
#define MAX_PATH 128

/**
 * @brief Structure pour un niveau de difficulté
 */
typedef struct {
    int max_nombre;
    int essais;
} NiveauDifficulte;

/**
 * @brief Structure contenant toute la configuration
 */
typedef struct {
    /* Chemins des fichiers */
    char fichier_titre[MAX_PATH];
    char fichier_scores[MAX_PATH];

    /* Limites */
    int max_joueurs;
    int max_nom;
    int min_nombre;

    /* Proximité */
    int seuil_bouillant;
    int seuil_chaud;

    /* Difficultés */
    NiveauDifficulte facile;
    NiveauDifficulte normal;
    NiveauDifficulte difficile;
    NiveauDifficulte expert;
} Config;

/* Variable globale de configuration */
extern Config g_config;

/**
 * @brief Charge la configuration depuis le fichier YAML
 * @return 1 si succès, 0 si erreur
 */
int charger_config(void);

/**
 * @brief Initialise la configuration avec les valeurs par défaut
 */
void config_defaut(void);

#endif /* CONFIG_H */
