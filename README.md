# S101

Suite à une panne informatique du système de base de données de la grande surface «E.Carrechan», l’équipe informatique ne dispose plus que de fichiers journaliers de tickets de caisse.

Vous devez aider les équipes différentes équipes du magasin à gérer au mieux les comptes, stocks, clients etc. en attendant que la base de données soit rétablie.

## Structure du Projet

```bash
.
├── auteurs.txt
├── bin
│   ├── log2report
│   └── test
├── data
│   ├── G1C-caissieres.csv
│   ├── G1C-clients.csv
│   ├── G1C-log-2025-09-22.csv
│   ├── G1C-log-2025-09-23.csv
│   ├── G1C-log-2025-09-24.csv
│   ├── G1C-log-2025-09-25.csv
│   ├── G1C-log-2025-09-26.csv
│   ├── G1C-log-2025-09-27.csv
│   ├── G1C-log-2025-09-29.csv
│   ├── G1C-log-2025-09-30.csv
│   ├── G1C-log-2025-10-01.csv
│   ├── G1C-log-2025-10-02.csv
│   ├── G1C-log-2025-10-03.csv
│   └── G1C-log-2025-10-04.csv
├── Doxyfile
├── lib
│   ├── affichage.c
│   ├── affichage.h
│   ├── caissiere.c
│   ├── client.c
│   ├── jour.c
│   ├── ticket.c
│   ├── utils.c
│   └── utils.h
├── LICENCE
├── LICENCE-CONTENT
├── main.c
├── obj
│   ├── affichage.o
│   ├── caissiere.o
│   ├── client.o
│   ├── jour.o
│   ├── main.o
│   ├── ticket.o
│   └── utils.o
├── README.md
└── tests
    └── utils.c
```

## Compilation

- Compiler le projet

```bash
mkdir -p obj
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c main.c -o obj/main.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/affichage.c -o obj/affichage.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/caissiere.c -o obj/caissiere.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/client.c -o obj/client.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/jour.c -o obj/jour.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/ticket.c -o obj/ticket.o
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g -c lib/utils.c -o obj/utils.o
mkdir -p bin
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g obj/main.o obj/affichage.o obj/caissiere.o obj/client.o obj/jour.o obj/ticket.o obj/utils.o -o bin/s101
```

- Tests

Compiler

```bash
gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g tests/utils.c lib/affichage.c lib/caissiere.c lib/client.c lib/jour.c lib/ticket.c lib/utils.c -o bin/test
./bin/test
```

Tester

```bash
LOG_DATE="2025-09-22"
OUTPUT_DIR="output"
BIN="./bin/s101"

mkdir -p "$OUTPUT_DIR"

# Aide
$BIN -h > "$OUTPUT_DIR/help.txt"

# CA du jour
$BIN -caj < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/ca_jour.txt"

# Nombre total de tickets
$BIN -lt < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/nb_tickets.txt"
$BIN -lt -p < "data/G1C-log-$LOG_DATE.csv" >> "$OUTPUT_DIR/nb_tickets.txt"

# infos caissière
$BIN -ic 35 < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/ca_caissiere.txt"
$BIN -ic 35 -p < "data/G1C-log-$LOG_DATE.csv" >> "$OUTPUT_DIR/ca_caissiere.txt"

# ID caissière
$BIN -idca LAVENANT JASON < data/G1C-caissieres.csv > "$OUTPUT_DIR/id_caissiere.txt"
$BIN -idca LAVENANT JASON -p < data/G1C-caissieres.csv >> "$OUTPUT_DIR/id_caissiere.txt"

# ID client
$BIN -idcl 'PEREIRA DA SILVA' RAQUEL < data/G1C-clients.csv > "$OUTPUT_DIR/id_client.txt"
$BIN -idcl 'PEREIRA DA SILVA' RAQUEL -p < data/G1C-clients.csv >> "$OUTPUT_DIR/id_client.txt"

# Moyenne client
$BIN -mcl 12 < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/moyenne_client.txt"
$BIN -mcl 12 -p < "data/G1C-log-$LOG_DATE.csv" >> "$OUTPUT_DIR/moyenne_client.txt"

# Nombre tickets client
$BIN -ltc 12 < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/nb_tickets_client.txt"
$BIN -ltc 12 -p < "data/G1C-log-$LOG_DATE.csv" >> "$OUTPUT_DIR/nb_tickets_client.txt"

# Caissières par tranche horaire
$BIN -cath 9 17 < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/caissieres_tranche.txt"
$BIN -cath 9 17 -p < "data/G1C-log-$LOG_DATE.csv" >> "$OUTPUT_DIR/caissieres_tranche.txt"

# Liste des clients et caissières
$BIN -pcl < data/G1C-clients.csv > "$OUTPUT_DIR/clients.txt"
$BIN -pca < data/G1C-caissieres.csv > "$OUTPUT_DIR/caissieres.txt"

# Tickets du jour
$BIN -pj < "data/G1C-log-$LOG_DATE.csv" > "$OUTPUT_DIR/tickets_jour.txt"
```

## Documentation

Générer la documentation

```bash
doxygen && python3 -m http.server -d html
```

Usage : ./bin/log2report [OPTION] [ARGS]

Options disponibles :
-caj, --CA-jour : Affiche le chiffre d'affaire du jour
-ic, --infos-caissiere [ID] : Affiche infos d'une caissière
-p, --print : Affiche directement au lieu de renvoyer la chaîne
-idca, --ID-Caissiere NOM PRENOM : Récupère l'ID d'une caissière
-lt, --len-ticket : Nombre total de tickets
-mcl, --moyenne-client [ID] : Moyenne par client
-ltc, --len-ticket-client [ID] : Nombre de tickets par client
-idcl, --ID-client NOM PRENOM : Récupère l'ID d'un client
-cath, --CA-tranche START END : Caissières travaillant entre heures données
-pcl, --print-clients : Affiche tous les clients
-pca, --print-caissieres : Affiche toutes les caissières
-pj, --print-jour : Affiche tous les tickets du jour
-h, --help : Affiche ce message d'aide

### Options principales

- **Récupérer le nombre de tickets**

```bash
./bin/s101 -caj < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -caj -p < data/G1C-log-YYYY-MM-DD.csv
```

-caj, --CA-jour : Affiche le chiffre d'affaire du jour

- **Récupérer le nombre de tickets**

```bash
./bin/s101 -lt < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -lt -p < data/G1C-log-YYYY-MM-DD.csv
```

-lt, --len-ticket : Nombre total de tickets

- **Récupérer les infos d’une caissière à partir de son ID**

```bash
./bin/s101 -ic {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -ic {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

-ic, --infos-caissiere [ID] : Affiche infos d'une caissière

- **Récupérer l’ID d’une caissière**

```bash
./bin/s101 -idca {nom} {prenom} < data/G1C-caissieres.csv
./bin/s101 -idca {nom} {prenom} -p < data/G1C-caissieres.csv
```

-idca, --ID-Caissiere NOM PRENOM : Récupère l'ID d'une caissière

- **Récupérer l’ID d’un client**

```bash
./bin/s101 -idcl {nom} {prenom} < data/G1C-clients.csv
./bin/s101 -idcl {nom} {prenom} -p < data/G1C-clients.csv
```

-idcl, --ID-client NOM PRENOM : Récupère l'ID d'un client

- **Récupérer la moyenne d’un client à partir de son ID**

```bash
./bin/s101 -mcl {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -mcl {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

-mcl, --moyenne-client [ID] : Moyenne par client

- **Récupérer le nombre de tickets d’un client**

```bash
./bin/s101 -ltc {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -ltc {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

-ltc, --len-ticket-client [ID] : Nombre de tickets par client

- **Afficher les caissières travaillant dans une tranche horaire**

```bash
./bin/s101 -cath {start_hour} {end_hour} < data/G1C-log-YYYY-MM-DD.csv
./bin/s101 -cath {start_hour} {end_hour} -p < data/G1C-log-YYYY-MM-DD.csv
```

Exemple : de 9h à 17h

```bash
./bin/s101 -cath 9 17 < data/G1C-log-2025-09-22.csv
./bin/s101 -cath -p 9 17 < data/G1C-log-2025-09-22.csv
```

-cath, --CA-tranche START END : Caissières travaillant entre heures données

- **Afficher tous les clients ou caissières**

```bash
./bin/s101 -pcl < data/G1C-clients.csv
./bin/s101 -pca < data/G1C-caissieres.csv
```

-pcl, --print-clients : Affiche tous les clients
-pca, --print-caissieres : Affiche toutes les caissières

- **Afficher les tickets d’un jour précis**

```bash
./bin/s101 -pj < data/G1C-log-YYYY-MM-DD.csv
```

-pj, --print-jour : Affiche tous les tickets du jour

- **Afficher l’aide**

```bash
./bin/s101 -h
./bin/s101 --help
```

-h, --help : Affiche ce message d'aide

---

### Remarques

- YYYY : année (ex: 2025)
- MM : mois (ex: 09)
- DD : jour (ex: 22)
- Les options `-p` ou `--print` permettent un affichage plus lisible directement dans le terminal.
