/**
 * @file journee.c
 * @brief Gestion et affichage du chiffre d’affaires journalier et des ventes du jour.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"
#include <string.h>

char *get_CA_day()
{
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;
    static char result[64];

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    verif_file();
    while (1)
    {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;
        get_element(buffer, &c, &i, &is_quote, 128, ',');

        switch (col)
        {
        case 6:
            pu = atof(buffer);
            break;
        case 7:
            qte = atof(buffer);
            break;
        default:
            break;
        }

        if (c == ',' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            somme += pu * qte;
            nb_ticket++;
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    snprintf(result, sizeof(result), "%.2lf %d", somme, nb_ticket);
    return result;
}

void print_CA_day()
{
    char somme[32];
    char nb_ticket[16];
    char *result = get_CA_day();
    printf("📊 Bilan journalier - CA du jour\n");
    printf("--------------------------------\n");
    sscanf(result, "%s %s", somme, nb_ticket);
    printf("Total CA : %s €\n", somme);
    printf("Nombre total de tickets : %s\n", nb_ticket);
}

void print_day_csv()
{
    printf("Liste des tickets du jour\n\n");
    char buffer[128];
    int taille = 128;
    int col = 0;
    char enTete[8][20];
    char str[512];

    scanf("%19[^,],%19[^,],%19[^,],%19[^,],%19[^,],%19[^,],%19[^,],%19[^\n]\n",
          enTete[0], enTete[1], enTete[2], enTete[3],
          enTete[4], enTete[5], enTete[6], enTete[7]);

    int spaces = sprintf(str, "| %-19s | %-12s | %-9s | %-7s | %-15s | %-127s | %-5s | %-5s |",
                         enTete[0], enTete[1], enTete[2], enTete[3],
                         enTete[4], enTete[5], enTete[6], enTete[7]);
    afficherLigneSeparation(spaces);
    printf("%s\n", str);
    afficherLigneSeparation(spaces);

    verif_file();
    while (1)
    {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;

        get_element(buffer, &c, &i, &is_quote, taille, ',');

        switch (col)
        {
        case 0:
            printf("| %-19s |", buffer);
            break;
        case 1:
            printf(" %-12s |", buffer);
            break;
        case 2:
            printf(" %-9s |", buffer);
            break;
        case 3:
            printf(" %-7s |", buffer);
            break;
        case 4:
            printf(" %-15s |", buffer);
            break;
        case 5:
            print_char_with_special_char(buffer, 127);
            break;
        case 6:
            printf(" %-5s |", buffer);
            break;
        case 7:
            printf(" %-5s |\n", buffer);
            break;
        }

        if (c == ',' && !is_quote)
            col++;
        if ((c == '\n' || c == EOF) && !is_quote)
            col = 0;
    }
    afficherLigneSeparation(spaces);
}
