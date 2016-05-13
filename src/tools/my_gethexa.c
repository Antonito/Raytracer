/*
** my_gethexa.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 18:00:04 2016 Ludovic Petrenko
** Last update Fri May 13 15:58:07 2016 Luka Boulagnon
*/

#include <stdlib.h>
#include "tools/str.h"

unsigned int	my_gethexa(const char *s)
{
  unsigned int	res;

  res = 0;
  if (s == NULL || my_strlen(s) < 2)
    return (0);
  if (s[0] == '#')
    ++s;
  else if (s[0] == '0' && s[1] == 'x')
    s += 2;
  else
    return (0);
  while (*s)
    {
      if (*s >= '0' && *s <= '9')
	res = 16 * res + *s - '0';
      else if (*s >= 'A' && *s <= 'F')
	res = 16 * res + *s - 'A' + 10;
      else if (*s >= 'a' && *s <= 'f')
	res = 16 * res + *s - 'a' + 10;
      else
	return (0);
      ++s;
    }
  return (res);
}
