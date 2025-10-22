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
./compile.sh
```

- Tests

```bash
./test.sh
```

## Documentation

Générer la documentation

```bash
doxygen && python3 -m http.server -d html
```

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

- **Afficher les ID caissières travaillant dans une tranche horaire**

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

- **Afficher l'identité d'une caissiere**

```bash
./bin/s101 -ci {id} < data/G1C-caissieres.csv
```

-ci, --caissiere-identite: Afficher l'identité d'une caissiere

---

- **Afficher les caissières travaillant dans une tranche horaire**

```bash
> outputs/caissiere_horaire.txt

echo "Horaire des caissieres de 9 à 17h\n----------------------------------------\n" >> outputs/caissiere_horaire.txt

IFS=',' read -ra arr <<< "$(./bin/s101 -cath 9 17 < data/G1C-log-YYYY-MM-DD.csv)"
unique_ids=($(printf "%s\n" "${arr[@]}" | sort -u))

for id in "${unique_ids[@]}"; do
  ./bin/s101 -ci "$id" < data/G1C-caissieres.csv >> outputs/caissiere_horaire.txt
done
```

---

### Remarques

- YYYY : année (ex: 2025)
- MM : mois (ex: 09)
- DD : jour (ex: 22)
- Les options `-p` ou `--print` permettent un affichage plus lisible directement dans le terminal.
