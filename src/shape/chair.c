/*
** chair.c for Chair in /home/bache_a/work/Infographie/gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 14 20:53:15 2016 Antoine Baché
** Last update Sat May 14 21:19:31 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_chair(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	s[5];

  s[0] = -12.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 36.0 * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 36.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 10.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 2.0 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = -24.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 72.0 * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z + 72.0 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 40.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 4.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y + 8.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z - 24.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y + 16.0 * ray->dir.x * ray->dir.x * ray->dir.z + 72.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z - 16.0 * ray->dir.y * ray->dir.y * ray->dir.z + 72.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z;
  s[2] = 60.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 12.0 * tmp.y * tmp.y
    * ray->dir.x * ray->dir.x + 36.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x
    - 75.0 * ray->dir.x * ray->dir.x + 16.0 * tmp.z * ray->dir.x * ray->dir.x -
    12.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y + 6.0 * tmp.y * tmp.y *
    ray->dir.y * ray->dir.y + 36.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y -
    75.0 * ray->dir.y * ray->dir.y - 16.0 * tmp.z * ray->dir.y * ray->dir.y +
    36.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z + 36.0 * tmp.y * tmp.y *
    ray->dir.z * ray->dir.z + 12.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z -
    75.0 * ray->dir.z * ray->dir.z - 48.0 * tmp.x * tmp.y * ray->dir.x *
    ray->dir.y + 32.0 * tmp.x * ray->dir.x * ray->dir.z + 144.0 * tmp.x * tmp.z
    * ray->dir.x * ray->dir.z - 32.0 * tmp.y * ray->dir.y * ray->dir.z + 144.0
    * tmp.y * tmp.z * ray->dir.y * ray->dir.z;
  s[3] = -24.0 * tmp.x * tmp.y * tmp.y * ray->dir.x + 72.0 * tmp.x * tmp.z *
    tmp.z * ray->dir.x + 40.0 * tmp.x * tmp.x * tmp.x * ray->dir.x - 150.0 *
    tmp.x * ray->dir.x + 32.0 * tmp.x * tmp.z * ray->dir.x + 72.0 * tmp.y *
    tmp.z * tmp.z * ray->dir.y + 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y -
    150.0 * tmp.y * ray->dir.y - 24.0 * tmp.x * tmp.x * tmp.y * ray->dir.y -
    32.0 * tmp.y * tmp.z * ray->dir.y + 16.0 * tmp.x * tmp.x * ray->dir.z -
    16.0 * tmp.y * tmp.y * ray->dir.z + 8.0 * tmp.z * tmp.z * tmp.z *
    ray->dir.z - 150.0 * tmp.z * ray->dir.z + 72.0 * tmp.x * tmp.x * tmp.z *
    ray->dir.z + 72.0 * tmp.y * tmp.y * tmp.z * ray->dir.z;
  s[4] = -75.0 * tmp.x * tmp.x - 12.0 * tmp.x * tmp.x * tmp.y * tmp.y - 75.0 *
    tmp.y * tmp.y + 36.0 * tmp.x * tmp.x * tmp.z * tmp.z + 36.0 * tmp.y * tmp.y
    * tmp.z * tmp.z - 75.0 * tmp.z * tmp.z + 10.0 * tmp.x * tmp.x * tmp.x *
    tmp.x + tmp.y * tmp.y * tmp.y * tmp.y + 2.0 * tmp.z * tmp.z * tmp.z * tmp.z
    + 640.625 + 16.0 * tmp.x * tmp.x * tmp.z - 16.0 * tmp.y * tmp.y * tmp.z;
  if ((inter->dist = solver_fourth_degree(s[0], s[1], s[2], s[3], s[4]))
      == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_chair(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_chair(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
