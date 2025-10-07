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
    char date[19];
    int caissiere_id;
    int client_id;
    char type[7];
    int ean;
    char nom[30];
    float pu = 0;
    float qte = 0;

    char buffer[128];
    int col = 0;
    char enTete[8][20];

    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n", enTete[0], enTete[1], enTete[2], enTete[3], enTete[4],
          enTete[5], enTete[6], enTete[7]);

    afficherLigneSeparation(134);
    printf("| %-19s | %-12s | %-9s | %-7s | %-15s | %-30s | %-5s | %-5s |\n", enTete[0], enTete[1], enTete[2], enTete[3], enTete[4], enTete[5], enTete[6], enTete[7]);
    afficherLigneSeparation(134);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            ft_strcpy(date, buffer);
            break;
        case 1:
            caissiere_id = atoi(buffer);
            break;
        case 2:
            client_id = atoi(buffer);
            break;
        case 3:
            ft_strcpy(type, buffer);
            break;
        case 4:
            ean = atoi(buffer);
            break;
        case 5:
            ft_strcpy(nom, buffer);
            break;
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
            // printf("| %-19s | %-12d | %-9d | %-7s | %-15d | %-83s | %-5.2f | %-5.2f |\n", date, caissiere_id, client_id, type, ean, nom, pu, qte);
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    afficherLigneSeparation(134);
}
