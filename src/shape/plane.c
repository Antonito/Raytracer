/*
** plane.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 07:53:57 2016 Antoine Baché
** Last update Mon May  9 06:43:15 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_plane_dist(t_ray *ray, t_intersect *inter)
{
  if (ray->dir.x)
    {
      inter->dist = (-1.0 * ray->pos.x) / ray->dir.x;
      inter->pos = add_vec3(mult_vec3(ray->dir, inter->dist), inter->pos);
    }
  else
    inter->dist = -1.0;
}

t_intersect	get_intersect_plane(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  get_plane_dist(ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  inter.norm = obj->plane.normale;
  return (inter);
}
