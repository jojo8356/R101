Usage : ./bin/log2report [OPTION] [ARGS]

Options disponibles :
  -caj, --CA-jour                 : Affiche le chiffre d'affaire du jour
  -cac, --CA-caissiere [ID]       : Affiche CA d'une caissière
      -p, --print                 : Affiche directement au lieu de renvoyer la chaîne
  -idca, --ID-Caissiere NOM PRENOM: Récupère l'ID d'une caissière
  -lt, --len-ticket                : Nombre total de tickets
  -mcl, --moyenne-client [ID]     : Moyenne par client
  -ltc, --len-ticket-client [ID]  : Nombre de tickets par client
  -idcl, --ID-client NOM PRENOM    : Récupère l'ID d'un client
  -cath, --CA-tranche START END    : Caissières travaillant entre heures données
  -pcl, --print-clients            : Affiche tous les clients
  -pca, --print-caissieres         : Affiche toutes les caissières
  -pj, --print-jour                : Affiche tous les tickets du jour
  -h, --help                       : Affiche ce message d'aide

# Fonctions un peu nouvelles
assert: comme en python pour test des fonctions

# Définitions
**buffer**: Un buffer (tampon) est une zone mémoire temporaire utilisée pour stocker des données avant leur traitement ou leur transfert.
**EOF**: EOF (End Of File) = fin de fichier

**snprintf** = fonction C pour écrire une chaîne formatée dans un buffer de taille limitée.
```c
int snprintf(char *str, size_t size, const char *format, ...);
```
📥 str → le buffer où écrire
📏 size → taille maximale du buffer (pour éviter les débordements)
🧩 format → texte + variables à insérer (%d, %s, etc.)
🔢 Retourne le nombre de caractères qui auraient été écrits (même si ça dépasse size)

**static**: garde une variable en mémoire après la fin d’une fonction et cache une variable ou fonction au reste du programme.
🔹 Dans une fonction → la valeur reste d’un appel à l’autre.
🔹 En dehors → la variable ou la fonction est visible uniquement dans le fichier.
```c
void compteur() {
    static int n = 0;
    n++;
    printf("%d\n", n);
}
```
Chaque appel affiche :
```
1
2
3
```

**const**: empêcher la modification d’une variable après son initialisation.
**sscanf** = fonction C qui lit des valeurs depuis une chaîne de caractères, selon un format.
```c
int sscanf(const char *str, const char *format, ...);
```
str → la chaîne à lire
format → modèle (%d, %s, etc.) ... → adresses où stocker les valeurs lues
Retourne le nombre de valeurs lues avec succès

**CRUD** = acronyme pour les 4 opérations de base sur les données :
C → Create: Créer une nouvelle donnée
R → Read: Lire ou afficher des données existantes
U → Update: Modifier une donnée existante
D → Delete: Supprimer une donnée

# Questions
**Pourquoi 128 bytes pour ton buffer?**
128 est une taille standard, pratique et sûre pour des données textuelles courtes.
C’est une puissance de 2 → efficace pour l’allocation mémoire.
Suffisant pour stocker : des lignes de texte (ex. nom, chemin, message) sans gaspiller trop de mémoire
Taille courante utilisée par convention dans des programmes simples.

**Qu'as-tu utilisé comme technique pour réussir à parcourir le csv sans erreur ou problème de formatage?**
Lecture bas niveau (getchar()) pour etre le plus précis
Gestion manuelle du séparateur ;
Gestion des guillemets "..."
Suppression des \r

**Pourquoi avoir utilisé switch?**
Car c'est un programme à choix unique, on ne peut utiliser qu'une seule commande à la fois.
le mot-clé 'if' n'aurait pas été adapté selon votre leçon.

**Pourquoi ne pas avoir tout stocké dans un tableau global?**
Car je ne peux pas relire plusieurs fois le fichier donné en input.
Donc je ne peux pas triès ou manipuler les données à ma guise mais juste les afficher et faire certains calculs.

**Pourquoi ne pas avoir normaliser les données?**
Ce n'est pas possible sans connaitre les structures et malloc.
(Sinon j'aurais utilisé la liste chainé, pour pouvoir tout manipulé).

**Pourquoi avoir créer un Makefile** ou **Pourquoi avoir créer certains fichiers spécifiques en bash?**
Car dans l'énoncé c'est bien écrit que la compilation et l'exec doit etre simple d'utilisation
Ce n'est pas grave si ce n'est pas compté.

**Comment avez vous architecturer votre projet?**
📁 Racine du projet
Contient les fichiers principaux et scripts utiles :
🧠 main.c → point d’entrée du programme
⚙️ Makefile → compilation automatisée
🧾 README.md → explication du projet
📜 LICENCE / LICENCE-CONTENT → droits d’utilisation
🧰 doc.sh, clean.sh, test.sh → scripts utilitaires (doc, nettoyage, tests)
📘 Doxyfile, Doc.md → configuration et documentation Doxygen

📂 lib/

Regroupe tout le code source fonctionnel (modules indépendants).
Chaque .c a son .h associé :

Fichier	Rôle principal
affichage.c / .h	fonctions d’affichage formaté
caissiere.c	gestion des caissières
client.c	gestion des clients
jour.c	traitement des données journalières
ticket.c	analyse et formatage des tickets
utils.c / .h	fonctions génériques (ex : ft_strlen, parsing, etc.)

**Pourquoi avoir mis les commentaires liès à la doc Oxygene dans les .h?**
Car les .h sont fait pour centralisés des fonctions donc j'avais pas besoin de me perdre entre les fichiers.

**Pourquoi certaines fonctions sont presque les memes entre les caissieres et clients?**
Ils ont la meme structure dans leurs fichiers CSV.

**Pensez vous avoir fait assez pour une aussi grande entreprise que celle-ci?**
Je ne pense pas car une entreprise aussi grande a besoin de pouvoir modifier (CRUD*)

**Quel langage aurez-vous pris pour ce projet?**
J'aurais pris python car l'ouverture et fermeture des fichiers ainsi que l'analyse et la gestion des données sont plus précis et simple.

**Quel est votre avis sur le projet**
Johan: Il nous manquait beaucoup de leçons avant de pouvoir commencer ce projet. L'écart entre les élèves est trop grand. Très peu peuvent y arriver.

**Avez-vous appris des choses**
Oui, On a appris à get les données des CSVs dans le programme c sans fopen, sans pouvoir les modifier.
Une façon différente de lire des données.

**Combien ce projet (C) vaudrait dans le monde professionnel?**
On a mis à peu près 20h pour créer ce projet donc je dirais entre 300 et 400 euros. (Dev junior)

**Pourquoi avoir juste utilisé sizeof(result) au lieu de l'autre façon**
Car le type char a comme taille 1 octet.

