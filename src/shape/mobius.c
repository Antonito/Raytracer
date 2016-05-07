/*
** mobius.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 07:24:31 2016 Antoine Baché
** Last update Sat May  7 06:13:12 2016 Ludovic Petrenko
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_mobius(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  t_vec4	sol;

  sol.x = ray->dir.x * ray->dir.x * ray->dir.y - 4.0 * ray->dir.x *
    ray->dir.x * ray->dir.z + ray->dir.y * ray->dir.y * ray->dir.y +
    ray->dir.y * ray->dir.z * ray->dir.z;
  sol.y = 2.0 * ray->pos.x * ray->dir.x * ray->dir.y - 4.0 * ray->pos.x *
    ray->dir.x * ray->dir.z + ray->dir.x * ray->dir.x * ray->pos.y - 4.0 *
    ray->dir.x * ray->dir.x * ray->pos.z - 4.0 * ray->dir.x * ray->pos.y *
    ray->dir.z - 2.0 * ray->dir.x * ray->dir.z + 3.0 * ray->dir.y *
    ray->dir.y * ray->pos.y + 2.0 * ray->dir.y * ray->dir.z * ray->pos.z +
    ray->pos.y * ray->dir.z * ray->dir.z;
  sol.z = ray->pos.x * ray->pos.x * ray->dir.y - 2.0 * ray->pos.x *
    ray->pos.x * ray->dir.z + 2.0 * ray->pos.x * ray->dir.x * ray->pos.y -
    4.0 * ray->pos.x * ray->dir.x * ray->pos.z - ray->pos.x * ray->dir.z *
    ray->pos.z - 4.0 * ray->dir.x * ray->pos.y * ray->pos.z - 2.0 *
    ray->dir.x * ray->pos.z + 3.0 * ray->dir.y * ray->pos.y * ray->pos.y +
    ray->dir.y * ray->pos.z * ray->pos.z - 2.0 * ray->pos.y * ray->pos.y *
    ray->dir.z + 2.0 * ray->pos.y * ray->dir.z * ray->pos.z;
  sol.w = ray->pos.x * ray->pos.x * ray->pos.y - 2.0 * ray->pos.x *
    ray->pos.x * ray->pos.z - 2.0 * ray->pos.x * ray->pos.z + ray->pos.y *
    ray->pos.y * ray->pos.y - 2.0 * ray->pos.y * ray->pos.y * ray->pos.z +
    ray->pos.y * ray->pos.z * ray->pos.z - ray->pos.y;
  inter->dist = solver_third_degree(sol.x, sol.y, sol.z, sol.w);
}

t_intersect	get_intersect_mobius(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	v;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_mobius(obj, ray, &inter);
  if (inter.dist == -1.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  v = atan(inter.pos.y / inter.pos.x);
  inter.norm = vec3_normalize(vec3(-1.0 * cos(v) * cos(v / 2.0),
				   -1.0 * sin(v) * cos(v / 2.0),
				   -1.0 * sin(v / 2.0)));
  if (vec3_len(add_vec3(mult_vec3(ray->dir, inter.dist), inter.norm)) <
      inter.dist)
    inter.norm = mult_vec3(inter.norm, -1.00);
  return (inter);
}
