/*
** tooth.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 02:56:04 2016 Antoine Baché
** Last update Sun May 15 03:02:30 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_tooth(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	s[5];

  s[0] = ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z *
    ray->dir.z * ray->dir.z;
  s[1] = 4.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 4.0 * tmp.y *
    ray->dir.y * ray->dir.y * ray->dir.y + 4.0 * tmp.z * ray->dir.z *
    ray->dir.z * ray->dir.z;
  s[2] = -ray->dir.x * ray->dir.x + 6.0 * tmp.x * tmp.x * ray->dir.x *
    ray->dir.x - ray->dir.y * ray->dir.y + 6.0 * tmp.y * tmp.y * ray->dir.y *
    ray->dir.y - ray->dir.z * ray->dir.z + 6.0 * tmp.z * tmp.z * ray->dir.z *
    ray->dir.z;
  s[3] = 4.0 * tmp.x * tmp.x * tmp.x * ray->dir.x - 2.0 * tmp.x * ray->dir.x +
    4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y - 2.0 * tmp.y * ray->dir.y + 4.0 *
    tmp.z * tmp.z * tmp.z * ray->dir.z - 2.0 * tmp.z * ray->dir.z;
  s[4] = -tmp.x * tmp.x - tmp.y * tmp.y - tmp.z * tmp.z + tmp.x * tmp.x * tmp.x
    * tmp.x + tmp.y * tmp.y * tmp.y * tmp.y + tmp.z * tmp.z * tmp.z * tmp.z;
  if ((inter->dist = solver_fourth_degree(s[0], s[1], s[2], s[3], s[4]))
      == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_tooth(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_tooth(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
