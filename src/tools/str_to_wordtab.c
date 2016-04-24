/*
** str_to_wordtab.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 18:10:40 2016 Ludovic Petrenko
** Last update Sun Apr 24 17:04:03 2016 Arthur ARNAUD
*/

#include "tools/str.h"
#include <stdlib.h>

char	**str_to_wordtab(char *s, char c)
{
  int	n;
  int	i;
  int	j;
  char	**tab;

  n = 1;
  i = -1;
  while (s[++i])
    if (i && s[i] == c && s[i - 1] != c && s[i - 1])
      {
	s[i] = 0;
	n++;
      }
  if (!(tab = malloc((n + 1) * sizeof(char *))))
    return (NULL);
  n = -1;
  j = 0;
  while (++n < i)
    if (!n || (s[n] && !s[n - 1]))
      tab[j++] = s + n;
  tab[j] = NULL;
  return (tab);
}
