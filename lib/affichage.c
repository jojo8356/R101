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

    int id = 0;
    char nom[128];
    char prenom[128];
    char sexe;
    int numero;
    char voie[128];
    int code_postal;
    char ville[128];

    char buffer[127];
    int col = 0;

    char enTete[8][16];
    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n]\n", enTete[0], enTete[1], enTete[2],
          enTete[3], enTete[4], enTete[5], enTete[6], enTete[7]);

    afficherLigneSeparation(120);
    printf("| %-2s | %-16s | %-16s | %-4s | %-6s | %-25s | %-11s | %-8s |\n", enTete[0], enTete[1], enTete[2], enTete[3], enTete[4], enTete[5], enTete[6], enTete[7]);
    afficherLigneSeparation(120);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }

    while (1)
    {
        if (scanf("%127[^;\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            id = atoi(buffer);
            break;
        case 1:
            ft_strcpy(nom, buffer);
            break;
        case 2:
            ft_strcpy(prenom, buffer);
            break;
        case 3:
            sexe = buffer[0];
            break;
        case 4:
            numero = atoi(buffer);
            break;
        case 5:
            ft_strcpy(voie, buffer);
            break;
        case 6:
            code_postal = atoi(buffer);
            break;
        case 7:
            ft_strcpy(ville, buffer);
            break;
        default:
            break;
        }

        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n')
        {
            printf("| %-2d | %-16s | %-16s | %-4c | %-6d | %-25s | %-11d | %-8s |\n", id, nom, prenom, sexe, numero, voie, code_postal, ville);
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    afficherLigneSeparation(120);
}