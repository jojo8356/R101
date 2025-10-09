#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
  int c;

  c = 0;
  while (s1[c] == s2[c] && s1[c] && s2[c])
    c++;
  return (s1[c] - s2[c]);
}

void ft_strcpy(char *dest, const char *src)
{
  int i = 0;
  while (src[i])
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}

int diff_seconds(const char *t1, const char *t2)
{
  int y1, m1, d1, h1, min1, s1;
  int y2, m2, d2, h2, min2, s2;
  // sscanf = variable -> scanf -> variable
  sscanf(t1, "%4d-%2d-%2d %2d:%2d:%2d", &y1, &m1, &d1, &h1, &min1, &s1);
  sscanf(t2, "%4d-%2d-%2d %2d:%2d:%2d", &y2, &m2, &d2, &h2, &min2, &s2);
  int total1 = h1 * 3600 + min1 * 60 + s1;
  int total2 = h2 * 3600 + min2 * 60 + s2;

  return total2 - total1;
}

void format_time(int total_sec, char *out)
{
  int minutes = total_sec / 60;
  int seconds = total_sec % 60;
  // sprintf = variable -> printf -> variable
  sprintf(out, "%d min %d sec", minutes, seconds);
}

int include_char(char **list, int taille, char *str)
{
  for (int i = 0; i < taille; i++)
  {
    if (ft_strcmp(list[i], str) == 0)
      return 1;
  }
  return 0;
}

int len_utf8_chars(unsigned char c)
{
  /*
  Octets UTF-8:
  1 = 0x80: ASCII pur (a, A, etc.)
  2 = 0xE0 → compare à 0xC0: é (caractères à accent) (0xC3 0xA9)
  3 = 0xF0 → compare à 0xE0: € (caractères spécieux) (0xE2 0x82 0xAC)
  4 = 0xF8 → compare à 0xF0: emoji (0xF0 0x9F 0x98 0x80)
  */
  if ((c & 0xE0) == 0xC0)
    return 2;
  else if ((c & 0xF0) == 0xE0)
    return 3;
  else if ((c & 0xF8) == 0xF0)
    return 4;
  return 1;
}