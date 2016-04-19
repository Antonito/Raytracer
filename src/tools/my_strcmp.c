/*
** my_strcmp.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 18:48:46 2016 Ludovic Petrenko
** Last update Tue Apr 19 22:38:17 2016 Ludovic Petrenko
*/

#include "tools/str.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1000);
  while (s1[i] == s2[i] && s1[i])
    ++i;
  return (s1[i] - s2[i]);
}
