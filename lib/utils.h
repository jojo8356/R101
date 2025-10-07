#pragma once

int ft_strcmp(char *s1, char *s2);
void *ft_strcpy(char *dest, char *src);
int diff_seconds(const char *t1, const char *t2);
void format_time(int total_sec, char *out);
int include_char(char **list, int taille, char *str);
void get_ID_caissiere(char *target_nom, char *target_prenom);
void get_infos_caissiere(int target_caissiere_id);
void get_moyenne_client(int target_client_id);
void get_nb_ticket();
void get_nb_ticket_client(int target_client_id);
void get_CA_day();