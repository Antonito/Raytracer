/*
** chubs.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May 16 02:50:36 2016 Antoine Baché
** Last update Sun May 22 20:08:12 2016 Arthur ARNAUD
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void		get_dist_chubs(t_ray *ray, t_intersect *inter,
				       t_vec3 tmp)
{
  double		s[5];

  s[0] = ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z * ray->dir.z
    * ray->dir.z;
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
    * tmp.x + tmp.y * tmp.y * tmp.y * tmp.y + tmp.z * tmp.z * tmp.z * tmp.z +
    0.5;
  if ((inter->dist = solver_n_degree(s, 4))
      == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect		get_intersect_chubs(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_chubs(ray, &inter, ray->pos);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  calc_normale_chubs(&inter);
  return (inter);
}
