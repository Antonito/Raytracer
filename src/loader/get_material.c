/*
** get_material.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 18:26:16 2016 Ludovic Petrenko
** Last update Tue Apr 19 22:05:19 2016 Ludovic Petrenko
*/

#include <stdlib.h>
#include "tools/str.h"
#include "engine/material.h"

t_material	*get_material(t_material *mat, int nb, const char *name)
{
  int		i;

  i = -1;
  while (++i < nb)
    if (!my_strcmp(mat[i].name, name))
      return (mat + i);
  return (NULL);
}
