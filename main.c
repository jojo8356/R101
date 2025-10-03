#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/affichage.h"
#include "lib/exemple.h"
#include "lib/utils.h"

void print_csv() {
  char enTete[4][16];
  char date[11];
  char prod[16];
  int qte;
  float pu;
  puts("LECTURE DES DONNÉES\n");

  int cpt = 0;
  scanf("%15[^,],%15[^,],%15[^,],%15[^\n]", enTete[0], enTete[1], enTete[2],
        enTete[3]);
  afficherLigneSeparation();
  printf("| %-10s | %-16s | %-5s | %-5s |\n", enTete[0], enTete[1], enTete[2],
         enTete[3]);
  afficherLigneSeparation();

  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }

  while (scanf("%10[^,],%15[^,],%d,%f\n", date, prod, &qte, &pu) == 4) {
    printf("| %10s | %16s | %5d | %5.2f |\n", date, prod, qte, pu);
    cpt++;
  }
  afficherLigneSeparation();
}

void print_moyenne_client(float target_client_id) {
    char datetime[20] = "";
    int caissiere_id = 0;
    float client_id = 0;
    char type[16] = "";
    char ean[32] = "";
    char nom[128] = "";
    float pu = 0;
    float qte = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Moyenne du client n°%.1f\n", target_client_id);
    printf("--------------------------------\n");

    while (scanf("%[^,],%d,%f,%[^,],%[^,],%[^,\n],%f,%f\n",
                 datetime, &caissiere_id, &client_id,
                 type, ean, nom, &pu, &qte) == 8) {
        if (client_id == target_client_id){
            somme += pu*qte;
            nb_ticket++;
        }
    }
    printf("Moyenne: %.2lf euros\n", (double)somme/nb_ticket);
}

void print_CA_day() {
    char datetime[20] = "";
    int caissiere_id = 0;
    float client_id = 0;
    char type[16] = "";
    char ean[32] = "";
    char nom[128] = "";
    float pu = 0;
    float qte = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Bilan journalier - CA du jour\n");
    printf("--------------------------------\n");

    while (scanf("%[^,],%d,%f,%[^,],%[^,],%[^,\n],%f,%f\n",
                 datetime, &caissiere_id, &client_id,
                 type, ean, nom, &pu, &qte) == 8) {
        somme += pu * qte;
        nb_ticket++;
    }

    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
}

void print_CA_caissiere(int target_caissiere_id) {
    char datetime[20] = "";
    int caissiere_id = 0;
    float client_id = 0;
    char type[16] = "";
    char ean[32] = "";
    char nom[128] = "";
    float pu = 0;
    float qte = 0;

    double somme = 0;
    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("📊 Bilan journalier - CA de la caissiere n°%d\n", target_caissiere_id);
    printf("--------------------------------\n");

    while (scanf("%[^,],%d,%f,%[^,],%[^,],%[^,\n],%f,%f\n",
                 datetime, &caissiere_id, &client_id,
                 type, ean, nom, &pu, &qte) == 8) {
        //printf("%s , %d , %f , %s , %s , %s , %f , %f\n", datetime, caissiere_id, client_id, type, ean, nom, pu, qte);
        if (caissiere_id == target_caissiere_id){
          somme += pu * qte;
          nb_ticket++;
        }
    }

    printf("Total CA : %.2lf €\n", somme);
    printf("Nombre total de tickets : %d\n", nb_ticket);
}

void print_ID_caissiere(char *target_nom, char *target_prenom){
    int id = 0;
    char nom[128] = "";
    char prenom[128] = "";
    char sexe;
    int numero = 0;
    char voie[128] = "";
    char code_postal[6] = "";
    char commune[128] = "";
    scanf("%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n];%*[^;\n]\n");

    while (scanf("%d;%[^;];%[^;];%c;%d;%[^;];%[^;];%[^;]\n",
                 &id, nom, prenom,
                 &sexe, &numero, voie, code_postal, commune) == 8) {
      if (ft_strcmp(nom, target_nom) == 0 && ft_strcmp(prenom, target_prenom) == 0){
        printf("ID de la caissiere %s %s\n------------------------\nID: ", prenom, nom);
        printf("%d\n", id);
        return;
      }
    }
}

void print_nb_ticket(){
    char datetime[20] = "";
    int caissiere_id = 0;
    float client_id = 0;
    char type[16] = "";
    char ean[32] = "";
    char nom[128] = "";
    float pu = 0;
    float qte = 0;

    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("Nombre de tickets: ");

    while (scanf("%[^,],%d,%f,%[^,],%[^,],%[^,\n],%f,%f\n",
                 datetime, &caissiere_id, &client_id,
                 type, ean, nom, &pu, &qte) == 8) {
        nb_ticket++;
    }
    printf("%d\n", nb_ticket);
}

void print_nb_ticket_client(float target_client_id){
    char datetime[20] = "";
    int caissiere_id = 0;
    float client_id = 0;
    char type[16] = "";
    char ean[32] = "";
    char nom[128] = "";
    float pu = 0;
    float qte = 0;

    int nb_ticket = 0;
    scanf("%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n],%*[^,\n]\n");

    printf("Nombre de tickets du client n°%.1lf: ", target_client_id);

    while (scanf("%[^,],%d,%f,%[^,],%[^,],%[^,\n],%f,%f\n",
                 datetime, &caissiere_id, &client_id,
                 type, ean, nom, &pu, &qte) == 8) {
        if (client_id == target_client_id){
            nb_ticket++;
        }
    }
    printf("%d\n", nb_ticket);
}

/*
int main(int argc, char *argv[]) {
  if (argc <= 1) return 1;
  if (ft_strcmp(argv[1], "-caj") == 0 || ft_strcmp(argv[1], "--CA-jour") == 0) {
      print_CA_day();
  }
  else if (ft_strcmp(argv[1], "-cac") == 0 || ft_strcmp(argv[1], "--CA-caissiere") == 0) {
      if (argc > 2) {
          print_CA_caissiere(atoi(argv[2]));
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
*/

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

/*
int main(){
    print_csv();
    return 0;
}
*/