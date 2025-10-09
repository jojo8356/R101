#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/affichage.h"
#include "lib/utils.h"

int main(int argc, char *argv[]) {
  if (argc <= 1) return 1;
  if (include_char(argv, argc, "-caj") || include_char(argv, argc, "--CA-jour")) {
      print_CA_day();
  }
    else if (include_char(argv, argc, "-cac") || include_char(argv, argc, "--CA-caissiere")) {
        if (argc > 2) {
            if (argc > 3 && (include_char(argv, argc, "-p") || include_char(argv, argc, "--print"))) {
                print_infos_caissiere(atoi(argv[3]));
            } else {
                get_infos_caissiere(atoi(argv[2]));
            }
        } else {
            fprintf(stderr, "Erreur: argument manquant pour --CA-caissiere\n");
        }
    }
  else if (include_char(argv, argc, "-idc") || include_char(argv, argc, "--ID-Caissiere")) {
      if (argc > 3) {
        if (argc > 4 && (include_char(argv, argc, "-p") || include_char(argv, argc, "--print")))
            print_ID_caissiere(argv[3], argv[4]);
        else   
            get_ID_caissiere(argv[3], argv[4]);
      } else
          fprintf(stderr, "Erreur: arguments manquants pour --ID-Caissiere\n");
  }
  else if (include_char(argv, argc, "-lt") || include_char(argv, argc, "--len-ticket") ) {
    if (argc > 2 && (include_char(argv, argc, "-p") || include_char(argv, argc, "--print"))){
        print_nb_ticket();
  }else{
        get_nb_ticket();
    }
  }
  else if (include_char(argv, argc, "-mc")  || include_char(argv, argc, "--moyenne-client")) {
      if (argc > 2) {
          if (argc > 3 && (include_char(argv, argc, "-p") || include_char(argv, argc, "--print")))
            print_moyenne_client(atoi(argv[3]));
        else
            get_moyenne_client(atoi(argv[2]));
      } else {
          fprintf(stderr, "Erreur: arguments manquants pour --moyenne-client\n");
      }
  }
  else if (include_char(argv, argc, "-ltc") || include_char(argv, argc, "--len-ticket-client")) {
      if (argc > 2){
        if (argc > 3 && (include_char(argv, argc, "-p") || include_char(argv, argc, "--print")))
            print_nb_ticket_client(atoi(argv[3]));
        else
            get_nb_ticket_client(atoi(argv[2]));
      }
      else
          fprintf(stderr, "Erreur: arguments manquants pour --moyenne-client\n");
  }
  else if (include_char(argv, argc, "-pcl") || include_char(argv, argc, "--print-clients")) {
      print_clients_csv();
  }
  else if (include_char(argv, argc, "-pca") || include_char(argv, argc, "--print-caissieres")) {
      print_caissieres_csv();
  }
  else if (include_char(argv, argc, "-pj") || include_char(argv, argc, "--print-jour")) {
      print_day_csv();
  }
  else {
      fprintf(stderr, "Option inconnue: %s\n", argv[1]);
  }
  return 0;
}