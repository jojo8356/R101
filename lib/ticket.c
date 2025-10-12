/**
 * @file tickets.c
 * @brief Gestion du comptage et de l’affichage du nombre total de tickets.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "utils.h"


char *get_nb_ticket() {
    char buffer[127];
    int col = 0;
    int nb_ticket = 0;
    static char result[16];
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,"
          "\n]\n");
    while (1) {
        int i = 0;
        int c = getchar();
        int is_quote = 0;

        if (c == EOF)
            break;

        get_element(buffer, &c, &i, &is_quote, 128, ',');

        if (c == ';' && !is_quote)
            col++;
        else if (c == '\n') {
            col = 0;
            nb_ticket++;
        }
    }
    snprintf(result, sizeof(result), "%d", nb_ticket);
    return result;
}


void print_nb_ticket() {
    printf("Nombre de tickets dans le CSV: ");
    printf("%s\n", get_nb_ticket());
}
