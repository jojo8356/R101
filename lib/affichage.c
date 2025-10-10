/**
 * @file affichage.c
 * @brief Module de fonctions d'affichages.
 */
#include "affichage.h"

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * @brief Affiche une ligne de séparation.
 *
 * Cette fonction affiche une ligne de séparation de 80 -
 */
void afficheSep()
{
    printf("\n");
    for (int i = 0; i < 80; i++)
    {
        printf("-");
    }
    printf("\n");
}

void print_test_csv()
{
    char buffer[128];
    int col = 0;

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        printf("%s |", buffer);

        int c = getchar();
        if (c == ',')
        {
            col++;
        }
        else if (c == '\n')
        {
            printf("%c", c);
            col = 0;
        }
        else if (c == EOF)
        {
            break;
        }
    }
}

void afficherLigneSeparation(int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("-");
    }
    printf("\n");
}

void print_person_csv(char person_type[])
{
    printf("Liste des %s\n\n", person_type);

    char buffer[128];
    int taille = 128;
    int col = 0;
    char enTete[8][20];
    char str[512];

    scanf("%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%19[^;];%15[^\n]\n",
          enTete[0], enTete[1], enTete[2], enTete[3],
          enTete[4], enTete[5], enTete[6], enTete[7]);

    int spaces = sprintf(str, "| %-2s | %-20s | %-20s | %-4s | %-6s | %-50s | %-11s | %-20s |",
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
            else if (c == ';' && !is_quote)
                break;
            else if (c == '\n' && !is_quote)
                break;
            else
                buffer[i++] = c;

            c = getchar();
        }
        buffer[i] = '\0';

        switch (col)
        {
        case 0:
            printf("| %-2s |", buffer);
            break;
        case 1:
            printf(" %-20s |", buffer);
            break;
        case 2:
            printf(" %-20s |", buffer);
            break;
        case 3:
            printf(" %-4s |", buffer);
            break;
        case 4:
            printf(" %-6s |", buffer);
            break;
        case 5:
            printf(" %-50s |", buffer);
            break;
        case 6:
            printf(" %-11s |", buffer);
            break;
        case 7:
            printf(" %-50s |\n", buffer);
            break;
        }
        if (c == ';' && !is_quote)
            col++;
        if (c == '\n' || c == EOF)
            col = 0;
    }

    afficherLigneSeparation(spaces);
}