/*
** c8.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May 16 02:20:19 2016 Antoine Baché
** Last update Mon May 16 02:24:12 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void		get_dist_c8(t_ray *ray, t_intersect *inter,
				       t_vec3 tmp)
{
  double		*s;

  if (!(s = my_malloc(sizeof(double) * 9)))
    return ;
  s[0] = 64.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 64.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 64.0 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = 512.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 512.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 512.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[2] = 1792.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 128.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 1792.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 128.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 1792.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z - 128.0 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[3] = 3584.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 768.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 3584.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 768.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 3584.0 * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z - 768.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[4] = 80.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 1920.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 4480.0 * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 80.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 1920.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 4480.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 80.0 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z - 1920.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 4480.0 * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[5] = -2560.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 3584.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 320.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x - 2560.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y + 3584.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y + 320.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y - 2560.0 * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z + 3584.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z + 320.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[6] = 480.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 1920.0 * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 16.0 * ray->dir.x * ray->dir.x + 1792.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x + 480.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 1920.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 16.0 * ray->dir.y * ray->dir.y + 1792.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 480.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z - 1920.0 * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z - 16.0 * ray->dir.z * ray->dir.z + 1792.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z;
  s[7] = 320.0 * tmp.x * tmp.x * tmp.x * ray->dir.x - 768.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x + 512.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x - 32.0 * tmp.x * ray->dir.x + 320.0 * tmp.y * tmp.y * tmp.y * ray->dir.y - 768.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y + 512.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y - 32.0 * tmp.y * ray->dir.y + 320.0 * tmp.z * tmp.z * tmp.z * ray->dir.z - 768.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z + 512.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z - 32.0 * tmp.z * ray->dir.z;
  s[8] = 2.0 - 16.0 * tmp.x * tmp.x - 16.0 * tmp.y * tmp.y - 16.0 * tmp.z * tmp.z + 80.0 * tmp.x * tmp.x * tmp.x * tmp.x + 80.0 * tmp.y * tmp.y * tmp.y * tmp.y + 80.0 * tmp.z * tmp.z * tmp.z * tmp.z - 128.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x - 128.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y - 128.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z + 64.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x + 64.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y + 64.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z;
  if ((inter->dist = solver_n_degree(s, 8)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect		get_intersect_c8(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_c8(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
