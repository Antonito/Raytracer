/*
** my_strlen.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:21:50 2016 Antoine Baché
** Last update Mon Apr 18 10:22:15 2016 Antoine Baché
*/

#include <stdlib.h>

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str != NULL && *str != '\0' && (str++) && (++i));
  return (i);
}
