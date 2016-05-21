/*
** cassini.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 18:31:54 2016 Antoine Baché
** Last update Sat May 21 19:23:22 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cassini(t_ray *ray, t_intersect *inter, t_vec3 tmp)
{
  double	t[5];

  t[0] = 2.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + ray->dir.x *
    ray->dir.x * ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.y - ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  t[1] = 4.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 4.0 * tmp.x *
    ray->dir.x * ray->dir.x * ray->dir.x + 4.0 * tmp.y * ray->dir.y *
    ray->dir.y * ray->dir.y - 4.0 * tmp.z * ray->dir.z * ray->dir.z *
    ray->dir.z + 4.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y;
  t[2] = 6.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x + 2.0 * tmp.y * tmp.y
    * ray->dir.x * ray->dir.x - 0.5 * ray->dir.x * ray->dir.x + 2.0 * tmp.x *
    tmp.x * ray->dir.y * ray->dir.y + 6.0 * tmp.y * tmp.y * ray->dir.y *
    ray->dir.y + 0.5 * ray->dir.y * ray->dir.y - 6.0 * tmp.z * tmp.z *
    ray->dir.z * ray->dir.z + 8.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y;
  t[3] = 4.0 * tmp.x * tmp.y * tmp.y * ray->dir.x + 4.0 * tmp.x * tmp.x *
    tmp.x * ray->dir.x - tmp.x * ray->dir.x + 4.0 * tmp.y * tmp.y * tmp.y *
    ray->dir.y + tmp.y * ray->dir.y + 4.0 * tmp.x * tmp.x * tmp.y * ray->dir.y
    - 4.0 * tmp.z * tmp.z * tmp.z * ray->dir.z;
  t[4] = -0.5 * tmp.x * tmp.x + 2.0 * tmp.x * tmp.x * tmp.y * tmp.y + 0.5 *
    tmp.y * tmp.y + tmp.x * tmp.x * tmp.x * tmp.x + tmp.y * tmp.y * tmp.y *
    tmp.y - tmp.z * tmp.z * tmp.z * tmp.z + 0.0625;
  if ((inter->dist = solver_n_degree(t, 4)) ==
      NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_cassini(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_cassini(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  return (inter);
}
