/*
** get_node2.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat May  7 06:34:47 2016 Ludovic Petrenko
** Last update Sat May 21 04:07:16 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "engine/bsp.h"

bool		torus_node(t_node *node, t_obj *obj)
{
  double	radius;

  radius = obj->torus.radius_hole + obj->torus.radius_solid;
  if (obj->pos.x >= node->min.x - radius &&
      obj->pos.x <= node->max.x + radius &&
      obj->pos.y >= node->min.y - radius &&
      obj->pos.y <= node->max.y + radius &&
      obj->pos.z >= node->min.z - radius &&
      obj->pos.z <= node->max.z + radius)
    return (true);
  return (false);
}
