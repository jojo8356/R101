# Mon Projet en C

Ce projet démontre une structure multi-fichier en C avec un dossier de modules `lib` et une documentation générée avec [Doxygen](https://www.doxygen.nl/).

## Structure du Projet

Le dossier sae a la structure suivante:

```bash
├── data
│   └── exemple.csv
├── lib
│   └── exemple.h
│   └── exemple.h
├── lit_csv
├── lit_csv.c
├── README.md
```

## Lecture de fichiers csv

Les fichiers `csv` sont un format de fichier texte qui permet de stocker des données tabulaires.

`csv` signifie _comma separated values_, données séparées par des virgules.

Ils sont très utilisés pour échanger des données entre différents logiciels car le format est facile à lire et à écrire.

## Compilation

Pour compiler le projet, utilisez les commandes suivantes:

```bash
# Compiler le fichier main en incluant les fichiers sources dans lib
gcc lit_csv.c lib/exemple.c -o lit_csv

# Exécuter en utilisant le fichier exemple.csv comme entrée
./lit_csv < data/exemple.csv 

# Voux pouvez également écrire dans un fichier la sortie de votre programme
# pour la partager avec les autres membres du magasin
./lit_csv < data/exemple.csv > output/table.txt
```

## Documentation

La documentation est générée avec [Doxygen](https://www.doxygen.nl/). Pour générer la documentation, utilisez:

```bash
doxygen
```

La documentation sera générée dans le dossier `html`, lancez un serveur web pour la visualiser avec un navigateur web.

```bash
python3 -m http.server -d html
```

Vous pouvez éditer le fichier `Doxyfile` pour personnaliser la documentation.
