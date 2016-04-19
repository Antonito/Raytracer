/*
** count.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 16:26:35 2016 Ludovic Petrenko
** Last update Mon Apr 18 19:34:13 2016 Ludovic Petrenko
*/

#include "raytracer.h"

int			ini_count_prefix(t_bunny_ini *ini, const char *prefix)
{
  t_bunny_ini_scope	*scope;
  int			nb;
  char			*scope_name;

  nb = 0;
  if (!(scope = bunny_ini_first(ini)))
    return (0);
  while (!(scope = bunny_ini_next(ini, scope)))
    {
      scope_name = (char *)bunny_ini_scope_name(ini, scope);
      if (!scope_name && !my_strncmp(scope_name, prefix, my_strlen(prefix)))
	nb++;
    }
  return (nb);
}
