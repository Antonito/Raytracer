/*
** plane.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 07:53:57 2016 Antoine Baché
** Last update Mon May  2 08:02:53 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"

static void	get_plane_dist(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	t;

  if (ray->dir.x)
    {
      t = (-1.0 * ray->pos.x)/ ray->dir.x;
      inter.dist = solver_second_degree(ray->dir.x * t + ray->pos.x,
					ray->dir.y * t + ray->pos.y,
					ray->dir.z * t + ray->pos.z);
    }
  else
    inter.dist = -1.0;
}

t_intersect	get_intersect_plane(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.material = obj->mat;
  get_plane_dist(obj, ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  // Calcul de la normale
  return (inter);
}
