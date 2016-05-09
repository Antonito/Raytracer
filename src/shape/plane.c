/*
** plane.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 07:53:57 2016 Antoine Baché
** Last update Mon May  9 07:19:56 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_plane_dist(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	tmp;

  tmp = ray->dir.x * obj->plane.normale.x +
    ray->dir.y * obj->plane.normale.y +
    ray->dir.z * obj->plane.normale.z;
  if (IS_ZERO(tmp))
    inter->dist = -1.0;
  else
    {
      inter->dist = -((ray->pos.x - obj->pos.x) * obj->plane.normale.x +
		     (ray->pos.y - obj->pos.y) * obj->plane.normale.y +
		     (ray->pos.z - obj->pos.z) * obj->plane.normale.z) / tmp;
    }
  if (inter->dist < 0.0 || IS_ZERO(inter->dist))
    inter->dist = -1.0;
}

t_intersect	get_intersect_plane(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  get_plane_dist(ray, &inter, obj);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  if ((((int)inter.pos.x + (inter.pos.x < 0.0)) & 1) ^
      ((((int)inter.pos.y + (inter.pos.y < 0.0)) & 1)))
    inter.mat = NULL;
  inter.norm = obj->plane.normale;
  return (inter);
}
