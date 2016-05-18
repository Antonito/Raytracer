/*
** tritrumpet.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 22:13:54 2016 Antoine Baché
** Last update Mon May 16 01:49:27 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_tritrumpet(t_ray *ray, t_intersect *inter, t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 4)))
    return ;
  s[0] = 6.0 * ray->dir.x * ray->dir.y * ray->dir.y - 2.0 * ray->dir.x *
    ray->dir.x * ray->dir.x;
  s[1] = 3.0 * ray->dir.x * ray->dir.x - 6.0 * tmp.x * ray->dir.x * ray->dir.x
    + 3.0 * ray->dir.y * ray->dir.y + 6.0 * tmp.x * ray->dir.y * ray->dir.y +
    8.0 * ray->dir.z * ray->dir.z + 12.0 * tmp.y * ray->dir.x * ray->dir.y;
  s[2] = 6.0 * tmp.x * tmp.x * ray->dir.x + 6.0 * tmp.y * tmp.y *
    ray->dir.x + 6.0 * tmp.x * ray->dir.x + 6.0 * tmp.y * ray->dir.y +
    12.0 * tmp.x * tmp.y * ray->dir.y + 16.0 * tmp.z * ray->dir.z;
  s[3] = -1.0 + 3.0 * tmp.x * tmp.x + 3.0 * tmp.y * tmp.y + 6.0 * tmp.x *
    tmp.y * tmp.y + 8.0 * tmp.z * tmp.z - 2.0 * tmp.x * tmp.x * tmp.x;
  if ((inter->dist = solver_n_degree(s, 3)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_tritrumpet(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_tritrumpet(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
