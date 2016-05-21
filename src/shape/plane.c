/*
** plane.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 07:53:57 2016 Antoine Baché
** Last update Sat May 21 12:56:21 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

t_intersect	get_intersect_plane(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.mat = obj->mat;
  inter.dist = -ray->pos.z / ray->dir.z;
  if (inter.dist < 0.00001)
    inter.dist = -1.0;
  if (inter.dist == -1.0)
    return (inter);
  inter.pos.y = ray->pos.y + inter.dist * ray->dir.y;
  inter.pos.x = ray->pos.x + inter.dist * ray->dir.x;
  if ((((int)inter.pos.x + (inter.pos.x < 0.0)) & 1) ^
      ((((int)inter.pos.y + (inter.pos.y < 0.0)) & 1)))
    inter.mat = NULL;
  inter.norm = vec3(0, 0, 1.0);
  return (inter);
}
