#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/affichage.h"
#include "lib/exemple.h"
#include "lib/utils.h"

/*
int main() {
    char buffer[128];
    int col = 0;

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        printf("%s |",buffer);

        int c = getchar();
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            printf("%c", c);
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }

    return 0;
}
*/

void print_moyenne_client(int target_client_id) {
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

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        switch(col){
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
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            if (client_id == target_client_id){
                somme += pu*qte;
                nb_ticket++;
            }
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
    printf("Moyenne: %.2lf euros\n", (double)somme/nb_ticket);
}

void print_CA_day() {
    float pu = 0;
    float qte = 0;
    char buffer[128];
    int col = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Bilan journalier - CA du jour\n");
    printf("--------------------------------\n");

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        switch(col){
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
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            somme += pu*qte;
            nb_ticket++;
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
}

void print_infos_caissiere(int target_caissiere_id) {
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

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        switch(col){
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
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            if (caissiere_id == target_caissiere_id){
                somme += pu*qte;
                nb_ticket++;
            }
            if (ft_strcmp(datetime, last_datetime) != 0){
                if (last_datetime[0] == '\0') {
                    ft_strcpy(last_datetime, datetime);
                }
                else{
                    int diff = diff_seconds(last_datetime, datetime);
                    ft_strcpy(last_datetime, datetime);
                    time += diff;
                }
            }
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
    format_time(time/nb_ticket, formatted);
    printf("Temps moyen : %s\n", formatted);
}

void print_ID_caissiere(char *target_nom, char *target_prenom){
    char nom[128];
    char prenom[128];
    char buffer[127];
    int col = 0;
    int caissiere_id = 0;
    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n]\n");

    while (1) {
        if (scanf("%127[^;\n]", buffer) != 1) buffer[0] = '\0';

        switch(col){
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
        if (c == ';') {
            col++;
        } else if (c == '\n') {
            if (ft_strcmp(nom, target_nom) == 0 && ft_strcmp(prenom, target_prenom) == 0){
                printf("ID de la caissiere %s %s\n------------------------\nID: ", target_prenom, target_nom);
                printf("%d\n", caissiere_id);
                return;
            }
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
    printf("Caissiere %s %s non trouvee\n", target_prenom, target_nom);
}

void print_nb_ticket(){
    char buffer[127];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");
    while (1) {
        if (scanf("%127[^;\n]", buffer) != 1) buffer[0] = '\0';
        int c = getchar();
        if (c == ';')
            col++;
        else if (c == '\n'){
            col = 0;
            nb_ticket++;
        }
        else if (c == EOF)
            break;
    }
    printf("Nombre de tickets: ");
    printf("%d\n", nb_ticket);
}

void print_nb_ticket_client(int target_client_id){
    float client_id = 0;
    char buffer[128];
    int col = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    while (1) {
        if (scanf("%127[^,\n]", buffer) != 1) buffer[0] = '\0';

        switch(col){
            case 2:
                client_id = atof(buffer);
                break;
            default:
                break;
        }

        int c = getchar();
        if (c == ',') {
            col++;
        } else if (c == '\n') {
            if (client_id == target_client_id){
                nb_ticket++;
            }
            col = 0;
        } else if (c == EOF) {
            break;
        }
    }
    printf("Nombre de tickets du client n°%d: ", target_client_id);
    printf("%d\n", nb_ticket);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) return 1;
  if (ft_strcmp(argv[1], "-caj") == 0 || ft_strcmp(argv[1], "--CA-jour") == 0) {
      print_CA_day();
  }
  else if (ft_strcmp(argv[1], "-cac") == 0 || ft_strcmp(argv[1], "--CA-caissiere") == 0) {
      if (argc > 2) {
          print_infos_caissiere(atoi(argv[2]));
      } else {
          fprintf(stderr, "Erreur: argument manquant pour --CA-caissiere\n");
      }
  }
  else if (ft_strcmp(argv[1], "-idc") == 0 || ft_strcmp(argv[1], "--ID-Caissiere") == 0) {
      if (argc > 3) {
          print_ID_caissiere(argv[2], argv[3]);
      } else {
          fprintf(stderr, "Erreur: arguments manquants pour --ID-Caissiere\n");
      }
  }
  else if (ft_strcmp(argv[1], "-lt") == 0 || ft_strcmp(argv[1], "--len-ticket") == 0) {
    print_nb_ticket();
  }
  else if (ft_strcmp(argv[1], "-mc") == 0 || ft_strcmp(argv[1], "--moyenne-client") == 0) {
      if (argc > 2) {
          print_moyenne_client(atoi(argv[2]));
      } else {
          fprintf(stderr, "Erreur: arguments manquants pour --moyenne-client\n");
      }
  }
  else if (ft_strcmp(argv[1], "-ltc") == 0 || ft_strcmp(argv[1], "--len-ticket-client") == 0) {
      if (argc > 2) {
          print_nb_ticket_client(atoi(argv[2]));
      } else {
          fprintf(stderr, "Erreur: arguments manquants pour --moyenne-client\n");
      }
  }
  else {
      fprintf(stderr, "Option inconnue: %s\n", argv[1]);
  }
  return 0;
}

/*
int main(){
    print_csv();
    return 0;
}
*/