/*
** kusner.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 21:51:37 2016 Antoine Baché
** Last update Wed May 18 03:43:39 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_kusner(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 7)))
    return ;
  s[0] = ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z *
    ray->dir.z;
  s[1] = 2.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z *
	  ray->dir.z + 2.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y *
	  ray->dir.z * ray->dir.z + 2.0 * tmp.z * ray->dir.x * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.z;
  s[2] = tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y +
    3.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + tmp.y * tmp.y *
    ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 3.0 * ray->dir.x *
    ray->dir.x * ray->dir.z * ray->dir.z + tmp.x * tmp.x * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 3.0 * ray->dir.y * ray->dir.y *
    ray->dir.z * ray->dir.z + 4.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y *
    ray->dir.z * ray->dir.z + 4.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.y *
    ray->dir.y * ray->dir.z + 4.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.z;
  s[3] = 2.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y +
    6.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 2.0 * tmp.x * tmp.y *
    tmp.y * ray->dir.x * ray->dir.z * ray->dir.z + 6.0 * tmp.x * ray->dir.x *
    ray->dir.z * ray->dir.z + 2.0 * tmp.x * tmp.x * tmp.y * ray->dir.y *
    ray->dir.z * ray->dir.z + 6.0 * tmp.y * ray->dir.y * ray->dir.z *
    ray->dir.z + 2.0 * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x *
    ray->dir.y + 6.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y + 2.0 *
    tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 6.0 * tmp.z
    * ray->dir.x * ray->dir.x * ray->dir.z + 2.0 * tmp.x * tmp.x * tmp.z *
    ray->dir.y * ray->dir.y * ray->dir.z + 6.0 * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.z - 32.0 * ray->dir.x * ray->dir.y * ray->dir.z + 8.0
    * tmp.x * tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z;
  s[4] = 3.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x + tmp.y * tmp.y * tmp.z
    * tmp.z * ray->dir.x * ray->dir.x + 3.0 * tmp.z * tmp.z * ray->dir.x *
    ray->dir.x + 9.0 * ray->dir.x * ray->dir.x + 3.0 * tmp.x * tmp.x *
    ray->dir.y * ray->dir.y + tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.y *
    ray->dir.y + 3.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 9.0 *
    ray->dir.y * ray->dir.y + 3.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z +
    tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 3.0 * tmp.y *
    tmp.y * ray->dir.z * ray->dir.z + 9.0 * ray->dir.z * ray->dir.z + 4.0 *
    tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y + 12.0 * tmp.x *
    tmp.y * ray->dir.x * ray->dir.y - 32.0 * tmp.z * ray->dir.x * ray->dir.y -
    32.0 * tmp.y * ray->dir.x * ray->dir.z + 4.0 * tmp.x * tmp.y * tmp.y *
    tmp.z * ray->dir.x * ray->dir.z + 12.0 * tmp.x * tmp.z * ray->dir.x *
    ray->dir.z - 32.0 * tmp.x * ray->dir.y * ray->dir.z + 12.0 * tmp.y * tmp.z
    * ray->dir.y * ray->dir.z + 4.0 * tmp.x * tmp.x * tmp.y * tmp.z *
    ray->dir.y * ray->dir.z;
  s[5] = 6.0 * tmp.x * tmp.y * tmp.y * ray->dir.x + 2.0 * tmp.x * tmp.y *
    tmp.y * tmp.z * tmp.z * ray->dir.x + 6.0 * tmp.x * tmp.z * tmp.z *
    ray->dir.x + 18.0 * tmp.x * ray->dir.x - 32.0 * tmp.y * tmp.z * ray->dir.x
    + 2.0 * tmp.x * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.y + 6.0 * tmp.y *
    tmp.z * tmp.z * ray->dir.y + 6.0 * tmp.x * tmp.x * tmp.y * ray->dir.y +
    18.0 * tmp.y * ray->dir.y - 32.0 * tmp.x * tmp.z * ray->dir.y - 32.0 *
    tmp.x * tmp.y * ray->dir.z + 6.0 * tmp.x * tmp.x * tmp.z * ray->dir.z +
    2.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.z + 6.0 * tmp.y *
    tmp.y * tmp.z * ray->dir.z + 18.0 * tmp.z * ray->dir.z;
  s[6] = 9.0 * tmp.x * tmp.x + 3.0 * tmp.x * tmp.x * tmp.y * tmp.y + 9.0 *
    tmp.y * tmp.y + 3.0 * tmp.x * tmp.x * tmp.z * tmp.z + tmp.x * tmp.x * tmp.y
    * tmp.y * tmp.z * tmp.z + 3.0 * tmp.y * tmp.y * tmp.z * tmp.z + 9.0 * tmp.z
    * tmp.z - 5.0 - 32.0 * tmp.x * tmp.y * tmp.z;
  if ((inter->dist = solver_n_degree(s, 6)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_kusner(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_kusner(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
