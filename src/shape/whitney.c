/*
** whitney.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 22:32:12 2016 Antoine Baché
** Last update Mon May 16 15:33:57 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_whitney(t_ray *ray, t_intersect *inter,
				 t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 4)))
  s[0] = ray->dir.x * ray->dir.x * ray->dir.z;
  s[1] = tmp.z * ray->dir.x * ray->dir.x - ray->dir.y * ray->dir.y +
    2.0 * tmp.x * ray->dir.x * ray->dir.z;
  s[2] = 2.0 * tmp.x * tmp.z * ray->dir.x - 2.0 * tmp.y * ray->dir.y + tmp.x *
    tmp.x * ray->dir.z;
  s[3] = -tmp.y * tmp.y + tmp.x * tmp.x * tmp.z;
  if ((inter->dist = solver_n_degree(s, 3)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_whitney(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_whitney(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
