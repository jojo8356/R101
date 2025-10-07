#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"

// GET
void get_nb_ticket()
{
    char buffer[127];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");
    while (1)
    {
        if (scanf("%127[^;\n]", buffer) != 1)
            buffer[0] = '\0';
        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n')
        {
            col = 0;
            nb_ticket++;
        }
        else if (c == EOF)
            break;
    }
    printf("%d", nb_ticket);
}

// PRINT
void print_nb_ticket()
{
    char buffer[127];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");
    while (1)
    {
        if (scanf("%127[^;\n]", buffer) != 1)
            buffer[0] = '\0';
        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n')
        {
            col = 0;
            nb_ticket++;
        }
        else if (c == EOF)
            break;
    }
    printf("Nombre de tickets: ");
    printf("%d\n", nb_ticket);
}