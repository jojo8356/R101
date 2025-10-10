#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"

// GET
void get_CA_day()
{
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

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

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            somme += pu * qte;
            nb_ticket++;
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("%.2lf %d", somme, nb_ticket);
}

// PRINT
void print_CA_day()
{
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Bilan journalier - CA du jour\n");
    printf("--------------------------------\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

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

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            somme += pu * qte;
            nb_ticket++;
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
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
                         enTete[4], enTete[5], enTete[6], enTete[7]); // sprintf: printf dans une string et return len string
    afficherLigneSeparation(spaces);
    printf("%s\n", str);
    afficherLigneSeparation(spaces);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    while (1)
    {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;

        while (c != EOF && i < taille - 1)
        {
            if (c == '"')
                is_quote = !is_quote;
            else if (c == ',' && !is_quote)
                break;
            else if (c == '\n' && !is_quote)
                break;
            else
                buffer[i++] = c;

            c = getchar();
        }
        buffer[i] = '\0';

        // Affichage selon la colonne
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
            print_char_with_special_char(buffer);
            break;
        case 6:
            printf(" %-5s |", buffer);
            break;
        case 7:
            printf(" %-5s |\n", buffer);
            break;
        }

        // Incrémenter col si ce n’est pas la fin de ligne
        if (c == ',' && !is_quote)
            col++;
        if (c == '\n' || c == EOF)
            col = 0;
    }
    afficherLigneSeparation(spaces);
}