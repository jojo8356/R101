/**
 * @file affichage.c
 * @brief Module de fonctions d'affichages.
 */
#include "affichage.h"

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void print_test_csv() {
    char buffer[128];
    int col = 0;

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        printf("%s |", buffer);

        int c = getchar();
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            printf("%c", c);
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
}

void afficherLigneSeparation(int len) {
    for (int i = 0; i < len; i++) {
        printf("-");
    }
    printf("\n");
}

void print_person_csv(char person_type[]) {
    printf("Liste des %s\n\n", person_type);

    char buffer[128];
    int taille = 128;
    int col = 0;
    char enTete[8][20];
    char str[512];

    scanf("%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%15[^\n]\n",
          enTete[0], enTete[1], enTete[2], enTete[3], enTete[4], enTete[5],
          enTete[6], enTete[7]);

    for (int j = 0; j < 8; j++) {
        int len = ft_strlen(enTete[j]);
        if (len > 0 && enTete[j][len - 1] == '\r')
            enTete[j][len - 1] = '\0';
    }

    int spaces = sprintf(
                     str, "| %-3s | %-15s | %-15s | %-4s | %-6s | %-40s | %-11s | %-30s |",
                     enTete[0], enTete[1], enTete[2], enTete[3], enTete[4], enTete[5],
                     enTete[6], enTete[7]);
    afficherLigneSeparation(spaces);
    printf("%s\n", str);
    afficherLigneSeparation(spaces);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }

    while (1) {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;

        get_element(buffer, &c, &i, &is_quote, taille);

        switch (col) {
        case 0:
            printf("| %-3s |", buffer);
            break;
        case 1:
            printf(" %-15s |", buffer);
            break;
        case 2:
            printf(" %-15s |", buffer);
            break;
        case 3:
            printf(" %-4s |", buffer);
            break;
        case 4:
            printf(" %-6s |", buffer);
            break;
        case 5:
            printf(" %-40s |", buffer);
            break;
        case 6:
            printf(" %-11s |", buffer);
            break;
        case 7:
            print_char_with_special_char(buffer, 30);
            printf("\n");
            break;
        }
        if (c == ';' && !is_quote)
            col++;
        if (c == '\n' || c == EOF)
            col = 0;
    }

    afficherLigneSeparation(spaces);
}

void print_char_with_special_char(char *buffer, int total) {
    printf(" ");
    int i = 0;
    int count = 0;
    while (buffer[i]) {
        unsigned char c = buffer[i];
        int len = len_utf8_chars(c);
        for (int k = 0; k < len; k++)
            printf("%c", buffer[i + k]);
        i += len;
        count++;
    }
    if (count < total)
        for (int j = 0; j < total - count; j++)
            printf(" ");
    printf(" |");
}

void print_error_missing_args(const char *option) {
    fprintf(stderr, "Erreur: arguments manquants pour %s\n", option);
}

void print_error_unknown_option(const char *option) {
    fprintf(stderr, "Erreur: option inconnue: %s\n", option);
}

void print_help() {
    printf("Usage : ./bin/log2report [OPTION] [ARGS]\n\n");
    printf("Options disponibles :\n");
    printf("  -caj, --CA-jour                 : Affiche le chiffre d'affaire du jour\n");
    printf("  -cac, --CA-caissiere [ID]       : Affiche CA d'une caissière\n");
    printf("      -p, --print                 : Affiche directement au lieu de renvoyer la chaîne\n");
    printf("  -idca, --ID-Caissiere NOM PRENOM: Récupère l'ID d'une caissière\n");
    printf("  -lt, --len-ticket                : Nombre total de tickets\n");
    printf("  -mcl, --moyenne-client [ID]     : Moyenne par client\n");
    printf("  -ltc, --len-ticket-client [ID]  : Nombre de tickets par client\n");
    printf("  -idcl, --ID-client NOM PRENOM    : Récupère l'ID d'un client\n");
    printf("  -cath, --CA-tranche START END    : Caissières travaillant entre heures données\n");
    printf("  -pcl, --print-clients            : Affiche tous les clients\n");
    printf("  -pca, --print-caissieres         : Affiche toutes les caissières\n");
    printf("  -pj, --print-jour                : Affiche tous les tickets du jour\n");
    printf("  -h, --help                       : Affiche ce message d'aide\n");
}
