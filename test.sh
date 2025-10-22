gcc -Wall -Wextra -pedantic -std=c11 -fno-common -fno-builtin -D_POSIX_C_SOURCE=200809L -Ilib -g tests/utils.c lib/affichage.c lib/caissiere.c lib/client.c lib/jour.c lib/ticket.c lib/utils.c -o bin/test
./bin/test

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

#Récupérer toutes les caissieres
: > output/caissiere_horaire.txt

echo "Horaire des caissieres de 9 à 17h
----------------------------------------" >> output/caissiere_horaire.txt

IFS=',' read -ra arr <<< "$(./bin/s101 -cath 9 17 < data/G1C-log-2025-09-22.csv)"
unique_ids=($(printf "%s\n" "${arr[@]}" | sort -u))

for id in "${unique_ids[@]}"; do
  ./bin/s101 -ci "$id" < data/G1C-caissieres.csv >> output/caissiere_horaire.txt
done