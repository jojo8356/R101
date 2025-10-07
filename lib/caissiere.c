#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"

// GET
void get_ID_caissiere(char *target_nom, char *target_prenom)
{
    char nom[128];
    char prenom[128];
    char buffer[127];
    int col = 0;
    int caissiere_id = 0;
    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n]\n");

    while (1)
    {
        if (scanf("%127[^;\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            // atof = atoi for float
            caissiere_id = atof(buffer);
            break;
        case 1:
            ft_strcpy(nom, buffer);
            break;
        case 2:
            ft_strcpy(prenom, buffer);
            break;
        default:
            break;
        }

        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n')
        {
            if (ft_strcmp(nom, target_nom) == 0 && ft_strcmp(prenom, target_prenom) == 0)
            {
                printf("%d", caissiere_id);
                return;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
}

void get_infos_caissiere(int target_caissiere_id)
{
    char datetime[20] = "";
    int caissiere_id = 0;
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;
    char last_datetime[20] = "";

    double somme = 0;
    int nb_ticket = 0;
    int time = 0;
    char formatted[6];
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            ft_strcpy(datetime, buffer);
            break;
        case 1:
            caissiere_id = atof(buffer);
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
            if (caissiere_id == target_caissiere_id)
            {
                somme += pu * qte;
                nb_ticket++;

                if (ft_strcmp(datetime, last_datetime) != 0)
                {
                    int diff = 0;
                    if (last_datetime[0] != '\0')
                        diff = diff_seconds(last_datetime, datetime);
                    ft_strcpy(last_datetime, datetime);
                    time += diff;
                }
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }

    printf("%.2lf %d", somme, nb_ticket);
    if (nb_ticket > 0)
    {
        format_time(time / nb_ticket, formatted);
        printf(" %s", formatted);
    }
}

// PRINT
void print_infos_caissiere(int target_caissiere_id)
{
    char datetime[20] = "";
    int caissiere_id = 0;
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;
    char last_datetime[20] = "";

    double somme = 0;
    int nb_ticket = 0;
    int time = 0;
    char formatted[6];
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Bilan journalier - Informations caissiere n°%d\n", target_caissiere_id);
    printf("--------------------------------\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            ft_strcpy(datetime, buffer);
            break;
        case 1:
            caissiere_id = atof(buffer);
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
            if (caissiere_id == target_caissiere_id)
            {
                somme += pu * qte;
                nb_ticket++;

                if (ft_strcmp(datetime, last_datetime) != 0)
                {
                    int diff = 0;
                    if (last_datetime[0] != '\0')
                        diff = diff_seconds(last_datetime, datetime);
                    ft_strcpy(last_datetime, datetime);
                    time += diff;
                }
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }

    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
    if (nb_ticket > 0)
    {
        format_time(time / nb_ticket, formatted);
        printf("Temps moyen : %s\n", formatted);
    }
}

void print_ID_caissiere(char *target_nom, char *target_prenom)
{
    char nom[128];
    char prenom[128];
    char buffer[127];
    int col = 0;
    int caissiere_id = 0;
    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n]\n");

    while (1)
    {
        if (scanf("%127[^;\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 0:
            caissiere_id = atof(buffer);
            break;
        case 1:
            ft_strcpy(nom, buffer);
            break;
        case 2:
            ft_strcpy(prenom, buffer);
            break;
        default:
            break;
        }

        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n')
        {
            if (ft_strcmp(nom, target_nom) == 0 && ft_strcmp(prenom, target_prenom) == 0)
            {
                printf("ID de la caissiere %s %s\n------------------------\nID: ", target_prenom, target_nom);
                printf("%d\n", caissiere_id);
                return;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("Caissiere %s %s non trouvee\n", target_prenom, target_nom);
}

void print_caissieres_csv()
{
    print_person_csv("caissieres");
}