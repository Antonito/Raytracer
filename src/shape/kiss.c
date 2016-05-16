/*
** kiss.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 04:02:43 2016 Antoine Baché
** Last update Sun May 15 04:09:34 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_kiss(t_obj *obj, t_ray *ray, t_intersect *inter,
			      t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 6)))
    return ;
  s[0] = ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = -ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z +
    5.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[2] = 10.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z - 4.0 *
    tmp.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[3] = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y - 6.0 * tmp.z *
    tmp.z * ray->dir.z * ray->dir.z + 10.0 * tmp.z * tmp.z * tmp.z * ray->dir.z
    * ray->dir.z;
  s[4] = 2.0 * tmp.x * ray->dir.x + 2.0 * tmp.y * ray->dir.y - 4.0 * tmp.z *
    tmp.z * tmp.z * ray->dir.z + 5.0 * tmp.z * tmp.z * tmp.z * tmp.z *
    ray->dir.z;
  s[5] = tmp.x * tmp.x + tmp.y * tmp.y - tmp.z * tmp.z * tmp.z * tmp.z + tmp.z
    * tmp.z * tmp.z * tmp.z * tmp.z;
  if ((inter->dist = solver_n_degree(s, 5)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_kiss(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_kiss(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
