/*
** resize.c for Raytracer2 in /gfx_raytracer2/src/ply
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May 16 21:20:42 2016 Antoine Baché
** Last update Mon May 16 21:25:28 2016 Antoine Baché
*/

#include "ply.h"

void	resize_ply(t_ply *ply, double ratio)
{
  int	i;

  i = 0;
  while (i < ply->nb_vertex)
    {
      ply->list_vertex[i].vec.x = ply->list_vertex[i].vec.x * ratio;
      ply->list_vertex[i].vec.y = ply->list_vertex[i].vec.y * ratio;
      ply->list_vertex[i].vec.z = ply->list_vertex[i].vec.z * ratio;
      ++i;
    }
}
