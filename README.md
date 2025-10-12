# R101

Suite à une panne informatique du système de base de données de la grande surface «E.Carrechan», l’équipe informatique ne dispose plus que de fichiers journaliers de tickets de caisse.

Vous devez aider les équipes différentes équipes du magasin à gérer au mieux les comptes, stocks, clients etc. en attendant que la base de données soit rétablie.

## Structure du Projet

```bash
.
├── bin
│   └── test
├── data
│   ├── exemple.csv
│   ├── G1C-caissieres.csv
│   ├── G1C-clients.csv
│   ├── G1C-log-2025-09-22.csv
│   ├── G1C-log-2025-09-23.csv
│   ├── G1C-log-2025-09-24.csv
│   ├── G1C-log-2025-09-25.csv
│   ├── G1C-log-2025-09-26.csv
│   └── G1C-log-2025-09-27.csv
├── Doxyfile
├── lib
│   ├── affichage.c
│   ├── affichage.h
│   ├── caissiere.c
│   ├── client.c
│   ├── jour.c
│   ├── ticket.c
│   ├── utils.c
│   └── utils.h
├── LICENCE
├── LICENCE-CONTENT
├── main.c
├── Makefile
├── output
│   └── Caissières.txt
├── README.md
└── tests
    └── utils.c
```

## Compilation

- Compiler l'entiereté des fichiers

```bash
make all
```

- Tester les fonctions utilitaires
```bash
make test
```

## Documentation

### Options principales

* **Récupérer le nombre de tickets**

```bash
./bin/log2report -lt < data/G1C-log-YYYY-MM-DD.csv
./bin/log2report -lt -p < data/G1C-log-YYYY-MM-DD.csv
```

* **Récupérer les infos d’une caissière à partir de son ID**

```bash
./bin/log2report -cac {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/log2report -cac {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

* **Récupérer l’ID d’une caissière**

```bash
./bin/log2report -idca {nom} {prenom} < data/G1C-caissieres.csv
./bin/log2report -idca {nom} {prenom} -p < data/G1C-caissieres.csv
```

* **Récupérer l’ID d’un client**

```bash
./bin/log2report -idcl {nom} {prenom} < data/G1C-clients.csv
./bin/log2report -idcl {nom} {prenom} -p < data/G1C-clients.csv
```

* **Récupérer la moyenne d’un client à partir de son ID**

```bash
./bin/log2report -mcl {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/log2report -mcl {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

* **Récupérer le nombre de tickets d’un client**

```bash
./bin/log2report -ltc {id} < data/G1C-log-YYYY-MM-DD.csv
./bin/log2report -ltc {id} -p < data/G1C-log-YYYY-MM-DD.csv
```

* **Afficher les caissières travaillant dans une tranche horaire**

```bash
./bin/log2report -cath {start_hour} {end_hour} < data/G1C-log-YYYY-MM-DD.csv
./bin/log2report -cath {start_hour} {end_hour} -p < data/G1C-log-YYYY-MM-DD.csv
```

Exemple : de 9h à 17h

```bash
./bin/log2report -cath 9 17 < data/G1C-log-2025-09-22.csv
./bin/log2report -cath -p 9 17 < data/G1C-log-2025-09-22.csv
```

* **Afficher tous les clients ou caissières**

```bash
./bin/log2report -pcl < data/G1C-clients.csv
./bin/log2report -pca < data/G1C-caissieres.csv
```

* **Afficher les tickets d’un jour précis**

```bash
./bin/log2report -pj < data/G1C-log-YYYY-MM-DD.csv
```

* **Afficher l’aide**

```bash
./bin/log2report -h
./bin/log2report --help
```

---

### Remarques

* YYYY : année (ex: 2025)
* MM : mois (ex: 09)
* DD : jour (ex: 22)
* Les options `-p` ou `--print` permettent un affichage plus lisible directement dans le terminal.