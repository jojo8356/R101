#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"

// GET
void get_moyenne_client(int target_client_id)
{
    float client_id = 0;
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

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            if (client_id == target_client_id)
            {
                somme += pu * qte;
                nb_ticket++;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("%.2lf", (double)somme / nb_ticket);
}

void get_nb_ticket_client(int target_client_id)
{
    float client_id = 0;
    char buffer[128];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 2:
            client_id = atof(buffer);
            break;
        default:
            break;
        }

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            if (client_id == target_client_id)
            {
                nb_ticket++;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("%d", nb_ticket);
}

// PRINT
void print_moyenne_client(int target_client_id)
{
    float client_id = 0;
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Moyenne du client n°%d\n", target_client_id);
    printf("--------------------------------\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

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

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            if (client_id == target_client_id)
            {
                somme += pu * qte;
                nb_ticket++;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("Moyenne: %.2lf euros\n", (double)somme / nb_ticket);
}

void print_nb_ticket_client(int target_client_id)
{
    float client_id = 0;
    char buffer[128];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    while (1)
    {
        if (scanf("%127[^,\n]", buffer) != 1)
            buffer[0] = '\0';

        switch (col)
        {
        case 2:
            client_id = atof(buffer);
            break;
        default:
            break;
        }

        int c = getchar();
        if (c == ',')
            col++;
        else if (c == '\n')
        {
            if (client_id == target_client_id)
            {
                nb_ticket++;
            }
            col = 0;
        }
        else if (c == EOF)
            break;
    }
    printf("Nombre de tickets du client n°%d: ", target_client_id);
    printf("%d\n", nb_ticket);
}

void print_clients_csv()
{
    print_person_csv("clients");
}