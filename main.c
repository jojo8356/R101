#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/affichage.h"
#include "lib/utils.h"

int main(int argc, char *argv[]) {
    if (argc <= 1)
        return 1;

    // 🧠 Récupère tous les arguments sans '-'
    char *args[argc];
    int args_count = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            args[args_count++] = argv[i];
        }
    }
    args[args_count] = NULL; // fin du tableau (sécurité)

    if (include_char(argv, argc, "-h") || include_char(argv, argc, "--help")) {
        print_help();
    }
    else if (include_char(argv, argc, "-caj") ||
            include_char(argv, argc, "--CA-jour")) {
        print_CA_day();
    } else if (include_char(argv, argc, "-iac") ||
               include_char(argv, argc, "--infos-caissiere")) {
        if (argc > 2) {
            if (argc > 3 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print"))) {
                print_infos_caissiere(atoi(args[0]));
            } else {
                printf("%s\n", get_infos_caissiere(atoi(args[0])));
            }
        } else {
			print_error_missing_args("--infos-caissiere");
        }
    } else if (include_char(argv, argc, "-idca") ||
               include_char(argv, argc, "--ID-Caissiere")) {
        if (argc > 3) {
            if (argc > 4 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print")))
                print_ID_caissiere(args[0], args[1]);
            else
                printf("%s\n", get_ID_caissiere(args[0], args[1]));
        } else
			print_error_missing_args("--ID-Caissiere");
    } else if (include_char(argv, argc, "-lt") ||
               include_char(argv, argc, "--len-ticket")) {
        if (argc > 2 && (include_char(argv, argc, "-p") ||
                         include_char(argv, argc, "--print"))) {
            print_nb_ticket();
        } else {
            printf("%s\n", get_nb_ticket());
        }
    } else if (include_char(argv, argc, "-mcl") ||
               include_char(argv, argc, "--moyenne-client")) {
        if (argc > 2) {
            if (argc > 3 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print")))
                print_moyenne_client(atoi(args[0]));
            else
                printf("%s\n", get_moyenne_client(atoi(args[0])));
        } else {
			print_error_missing_args("--moyenne-client");
        }
    } else if (include_char(argv, argc, "-ltc") ||
               include_char(argv, argc, "--len-ticket-client")) {
        if (argc > 2) {
            if (argc > 3 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print")))
                print_nb_ticket_client(atoi(args[0]));
            else
                printf("%s\n", get_nb_ticket_client(atoi(args[0])));
        } else
			print_error_missing_args("--len-ticket-client");
    } else if (include_char(argv, argc, "-idcl") ||
               include_char(argv, argc, "--ID-client")) {
        if (argc > 3) { 
            if (argc > 4 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print"))) {
                
                print_ID_client(args[0], args[1]);
            } else {
                
                printf("%s\n", get_ID_client(args[0], args[1]));
            }
        } else {
            print_error_missing_args("--ID-client");
        }
    } else if (include_char(argv, argc, "-cath") ||
               include_char(argv, argc, "--CA-tranche")) {
        if (argc > 3) { 
			if (argc > 4 && (include_char(argv, argc, "-p") ||
                             include_char(argv, argc, "--print"))) {
				printf("%s\n", get_caissieres_by_time(atoi(args[0]), atoi(args[1])));
			} else
				print_caissieres_by_time(atoi(args[0]), atoi(args[1]));
        } else {
			print_error_missing_args("--CA-tranche (ex: 9 17)");
        }
    } else if (include_char(argv, argc, "-pcl") ||
               include_char(argv, argc, "--print-clients")) {
        print_clients_csv();
    } else if (include_char(argv, argc, "-pca") ||
               include_char(argv, argc, "--print-caissieres")) {
        print_caissieres_csv();
    } else if (include_char(argv, argc, "-pj") ||
               include_char(argv, argc, "--print-jour")) {
        print_day_csv();
    } else {
        fprintf(stderr, "Option inconnue: %s\n", argv[1]);
    }
    return 0;
}
