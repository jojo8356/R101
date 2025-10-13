/**
 * @file caissieres.c
 * @brief Gestion et affichage des informations relatives aux caissières.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"

char *get_ID_caissiere(char *target_nom, char *target_prenom)
{
    static char result[16];
    char nom[128];
    char prenom[128];
    char buffer[128];
    int col = 0;
    int caissiere_id = 0;

    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;"
          "\n]\n");

    verif_file();
    while (1)
    {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;

        get_element(buffer, &c, &i, &is_quote, 128, ';');

        switch (col)
        {
        case 0:
            caissiere_id = atoi(buffer);
            break;
        case 1:
            strcpy(nom, buffer);
            break;
        case 2:
            strcpy(prenom, buffer);
            break;
        }

        if (c == ';' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            if (strcmp(nom, target_nom) == 0 &&
                strcmp(prenom, target_prenom) == 0)
            {
                snprintf(result, sizeof(result), "%d", caissiere_id);
                return result;
            }
            col = 0;
        }
    }

    snprintf(result, sizeof(result), "0");
    return result;
}

char *get_infos_caissiere(int target_caissiere_id)
{
    static char result[64];
    char datetime[20] = "";
    char last_datetime[20] = "";
    int caissiere_id = 0;
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;
    int time = 0;
    char formatted[6] = "";

    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,"
          "\n]\n");

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
        case 0:
            strcpy(datetime, buffer);
            break;
        case 1:
            caissiere_id = atoi(buffer);
            break;
        case 6:
            pu = atof(buffer);
            break;
        case 7:
            qte = atof(buffer);
            break;
        }

        if (c == ',' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            if (caissiere_id == target_caissiere_id)
            {
                somme += pu * qte;
                nb_ticket++;

                if (strcmp(datetime, last_datetime) != 0)
                {
                    int diff = 0;
                    if (last_datetime[0] != '\0' && datetime[0] != '\0')
                        diff = diff_seconds(last_datetime, datetime);
                    strcpy(last_datetime, datetime);
                    time += diff;
                }
            }
            col = 0;
        }
    }

    if (nb_ticket > 0)
    {
        format_time(time / nb_ticket, formatted);
        snprintf(result, sizeof(result), "%.2lf %d %s", somme, nb_ticket,
                 formatted);
    }
    else
    {
        snprintf(result, sizeof(result), "0.00,0,00:00");
    }

    return result;
}

char *get_caissieres_by_time(int start_hour, int end_hour)
{
    static char result[512] = "";
    char buffer[128];
    int col = 0;
    int caissiere_id = 0;
    char datetime[20];

    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;"
          "\n]\n");

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
        case 0:
            strcpy(datetime, buffer);
            break;
        case 1:
            caissiere_id = atoi(buffer);
            break;
        }

        if (c == ',' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            int hour;
            sscanf(datetime, "%*d-%*d-%*d %2d", &hour);
            if (hour >= start_hour && hour < end_hour)
            {
                char tmp[16];
                snprintf(tmp, sizeof(tmp), "%d,", caissiere_id);
                strncat(result, tmp, sizeof(result) - strlen(result) - 1);
            }
            col = 0;
        }
    }

    int len = strlen(result);
    if (len > 0 && result[len - 1] == ',')
        result[len - 1] = '\0';

    return result;
}

void print_infos_caissiere(int target_caissiere_id)
{
    char *result = get_infos_caissiere(target_caissiere_id);

    double somme;
    int nb_ticket;
    char formatted[16];
    sscanf(result, "%lf %d %[^\n]", &somme, &nb_ticket, formatted);

    printf("📊 Bilan journalier - Informations caissière n°%d\n",
           target_caissiere_id);
    printf("--------------------------------\n");
    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
    printf("Temps moyen : %s\n", formatted);
}

void print_ID_caissiere(char *target_nom, char *target_prenom)
{
    char *result = get_ID_caissiere(target_nom, target_prenom);
    int caissiere_id;
    sscanf(result, "%d", &caissiere_id);

    if (caissiere_id > 0)
    {
        printf("ID de la caissière %s %s\n", target_prenom, target_nom);
        printf("------------------------\n");
        printf("ID : %d\n", caissiere_id);
    }
    else
    {
        printf("Caissière %s %s non trouvée\n", target_prenom, target_nom);
    }
}

void print_caissieres_csv()
{
    print_person_csv("caissieres");
}

void print_caissieres_by_time(int start_hour, int end_hour)
{
    char *ids = get_caissieres_by_time(start_hour, end_hour);
    printf("📋 Caissières entre %02d:00 et %02d:00\n", start_hour, end_hour);
    printf("---------------------------------\n");

    if (strlen(ids) == 0)
    {
        printf("Aucune caissière trouvée.\n");
    }
    else
    {
        char *ptr = ids;
        int id;
        while (*ptr != '\0')
        {
            if (sscanf(ptr, "%d", &id) == 1)
            {
                printf("ID : %d\n", id);

                while (*ptr != ',' && *ptr != '\0')
                    ptr++;
                if (*ptr == ',')
                    ptr++;
            }
            else
            {
                break;
            }
        }
    }
}
