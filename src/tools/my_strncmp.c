/*
** my_strncmp.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 17:40:01 2016 Ludovic Petrenko
** Last update Tue Apr 19 18:50:12 2016 Ludovic Petrenko
*/

#include "tools/str.h"

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;

  i = -1;
  if (!s1 || !s2)
    return (-1000);
  while (++i < n && s1[i] == s2[i] && s1[0]);
  return ((s1[i] - s2[i]) * (i != n));
}
