/**
 * @file clients.c
 * @brief Gestion et affichage des informations liées aux clients.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"
#include <string.h>

// char *
// https://but.lyceum.fr/r101-init-dev/c07/#recherche-avec-strstr
// structure fonction
// https://but.lyceum.fr/r101-init-dev/c01/#d%C3%A9finition-dune-fonction
// fonction char *
char *get_moyenne_client(int target_client_id)
{
    static char result[32];
    float client_id = 0;
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;

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
        case 2:
            client_id = atof(buffer);
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

        if (c == ',' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            if ((int)client_id == target_client_id)
            {
                somme += pu * qte;
                nb_ticket++;
            }
            col = 0;
        }
    }

    if (nb_ticket > 0)
        snprintf(result, sizeof(result), "%.2lf", somme / nb_ticket);
    else
        snprintf(result, sizeof(result), "0.00");

    return result;
}

// char *
// https://but.lyceum.fr/r101-init-dev/c07/#recherche-avec-strstr
// structure fonction
// https://but.lyceum.fr/r101-init-dev/c01/#d%C3%A9finition-dune-fonction
// fonction char *
char *get_nb_ticket_client(int target_client_id)
{
    static char result[16];
    float client_id = 0;
    char buffer[128];
    int col = 0;
    int nb_ticket = 0;

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

        if (col == 2)
            client_id = atof(buffer);

        if (c == ',' && !is_quote)
            col++;
        else if (c == '\n' && !is_quote)
        {
            if ((int)client_id == target_client_id)
                nb_ticket++;
            col = 0;
        }
    }

    snprintf(result, sizeof(result), "%d", nb_ticket);
    return result;
}

// char *
// https://but.lyceum.fr/r101-init-dev/c07/#recherche-avec-strstr
// structure fonction
// https://but.lyceum.fr/r101-init-dev/c01/#d%C3%A9finition-dune-fonction
// fonction char *
char *get_ID_client(char *target_nom, char *target_prenom)
{
    static char result[16];
    char nom[128];
    char prenom[128];
    char buffer[128];
    int col = 0;
    int client_id = 0;

    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;"
          "\n]\n");

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
            client_id = atoi(buffer);
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
                snprintf(result, sizeof(result), "%d", client_id);
                return result;
            }
            col = 0;
        }
    }

    snprintf(result, sizeof(result), "0");
    return result;
}

void print_moyenne_client(int target_client_id)
{
    printf("📊 Moyenne du client n°%d\n", target_client_id);
    printf("--------------------------------\n");
    printf("Moyenne: %s euros\n", get_moyenne_client(target_client_id));
}

void print_nb_ticket_client(int target_client_id)
{
    printf("Nombre de tickets du client n°%d: ", target_client_id);
    printf("%s\n", get_nb_ticket_client(target_client_id));
}

void print_clients_csv()
{
    print_person_csv("clients");
}

void print_ID_client(char *target_nom, char *target_prenom)
{
    char *result = get_ID_client(target_nom, target_prenom);
    int client_id;
    sscanf(result, "%d", &client_id);

    if (client_id > 0)
    {
        printf("ID du client %s %s\n", target_prenom, target_nom);
        printf("------------------------\n");
        printf("ID : %d\n", client_id);
    }
    else
    {
        printf("Client %s %s non trouvée\n", target_prenom, target_nom);
    }
}
