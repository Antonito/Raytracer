/*
** heart.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 03:09:14 2016 Antoine Baché
** Last update Sun May 15 03:15:27 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_heart(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 7)))
    return ;
  s[0] = 27.0 / 4.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 / 2.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 3.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 243.0 / 16.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 243.0 / 16.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 3.0 * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 / 4.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 729.0 / 64.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = 27.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 12.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 243.0 / 4.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 27.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z + 243.0 / 4.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y - ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z + 12.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z - 9.0 / 8.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z + 243.0 / 8.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 6.0 * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 / 2.0 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 6.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 2187.0 / 32.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 6.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 / 2.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y + 27.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z + 6.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z + 243.0 / 8.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z;
  s[2] = 27.0 / 2.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 81.0 / 2.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 729.0 / 8.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 / 2.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 18.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 27.0 / 2.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 18.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 6.0 * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 3.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 27.0 / 2.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 27.0 / 2.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 729.0 / 8.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 81.0 / 2.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 27.0 / 8.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 54.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z + 243.0 / 2.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y - 2.0 * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z + 24.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z - 9.0 / 4.0 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z + 54.0 * tmp.y * tmp.z * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z + 15.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 27.0 / 4.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 3.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 3.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x + 243.0 / 16.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 10935.0 / 64.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 243.0 / 16.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 243.0 / 16.0 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 3.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 / 4.0 * tmp.y * tmp.y * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 15.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z - 3.0 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 54.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y + 54.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z + 24.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.z + 243.0 / 2.0 * tmp.y * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 54.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.z;
  s[3] = 729.0 / 4.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y - 27.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 27.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.z * ray->dir.z + 36.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.z * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z - 12.0 * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z - 6.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.z * ray->dir.z + 81.0 * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.z * ray->dir.z + 243.0 / 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 27.0 * tmp.x * tmp.x * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z - 27.0 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z - 27.0 / 4.0 * tmp.y * tmp.z * ray->dir.y * ray->dir.z * ray->dir.z + 27.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x + 12.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.x + 20.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x - 12.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x + 243.0 / 4.0 * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y + 3645.0 / 16.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y + 243.0 / 4.0 * tmp.x * tmp.x * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y - 243.0 / 4.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y - tmp.x * tmp.x * ray->dir.z * ray->dir.z * ray->dir.z - 9.0 / 8.0 * tmp.y * tmp.y * ray->dir.z * ray->dir.z * ray->dir.z + 20.0 * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z - 12.0 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 * tmp.y * tmp.y * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z + 27.0 * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y + 243.0 / 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y + 81.0 * tmp.x * tmp.x * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y - 27.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y - 3.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 12.0 * tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z - 12.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 36.0 * tmp.x * tmp.x * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 27.0 * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z - 27.0 / 8.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z + 27.0 * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z + 27.0 * tmp.x * tmp.x * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z + 729.0 / 4.0 * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z - 27.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z + 108.0 * tmp.x * tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z;
  s[4] = 18.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 27.0 / 2.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 81.0 / 2.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 18.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 27.0 / 2.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x - 6.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 3.0 * ray->dir.x * ray->dir.x - tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 15.0 * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x + 243.0 / 16.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 3.0 * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.x - 27.0 / 2.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y + 729.0 / 8.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 729.0 / 8.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 27.0 / 2.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 27.0 / 2.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 729.0 / 8.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y - 9.0 / 8.0 * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 27.0 / 4.0 * ray->dir.y * ray->dir.y + 27.0 / 4.0 * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.y * ray->dir.y + 10935.0 / 64.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 27.0 / 4.0 * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y - 6.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z - 27.0 / 2.0 * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 27.0 / 2.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 18.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.z * ray->dir.z + 81.0 / 2.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.z * ray->dir.z - 18.0 * tmp.z * tmp.z * ray->dir.z * ray->dir.z + 3.0 * ray->dir.z * ray->dir.z + 3.0 * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.z * ray->dir.z + 243.0 / 16.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 15.0 * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z * ray->dir.z - 3.0 * tmp.x * tmp.x * tmp.z * ray->dir.z * ray->dir.z - 27.0 / 8.0 * tmp.y * tmp.y * tmp.z * ray->dir.z * ray->dir.z + 54.0 * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y + 243.0 / 2.0 * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y + 54.0 * tmp.x * tmp.x * tmp.x * tmp.y * ray->dir.x * ray->dir.y - 54.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y - 6.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.z + 24.0 * tmp.x * tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.z + 54.0 * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.z + 24.0 * tmp.x * tmp.x * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 24.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 27.0 / 4.0 * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.z + 54.0 * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.z + 243.0 / 2.0 * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z + 54.0 * tmp.x * tmp.x * tmp.y * tmp.z * ray->dir.y * ray->dir.z - 54.0 * tmp.y * tmp.z * ray->dir.y * ray->dir.z;
  s[5] = 27.0 * tmp.x * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.x - 27.0 * tmp.x * tmp.y * tmp.y * ray->dir.x + 27.0 * tmp.x * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x + 12.0 * tmp.x * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.x - 12.0 * tmp.x * tmp.z * tmp.z * ray->dir.x - 12.0 * tmp.x * tmp.x * tmp.x * ray->dir.x - 2.0 * tmp.x * tmp.z * tmp.z * tmp.z * ray->dir.x + 243.0 / 8.0 * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x + 6.0 * tmp.x * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.x + 6.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.x + 6.0 * tmp.x * ray->dir.x + 243.0 / 4.0 * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y + 27.0 * tmp.x * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.y - 27.0 * tmp.y * tmp.z * tmp.z * ray->dir.y + 243.0 / 4.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.y - 243.0 / 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y - 9.0 / 4.0 * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.y + 27.0 / 2.0 * tmp.y * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y + 2187.0 / 32.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y + 27.0 / 2.0 * tmp.y * ray->dir.y - 27.0 * tmp.x * tmp.x * tmp.y * ray->dir.y + 27.0 / 2.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.y * ray->dir.y - 3.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.z - 27.0 / 8.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.z - 12.0 * tmp.z * tmp.z * tmp.z * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.z * tmp.z * tmp.z * ray->dir.z + 27.0 * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.z + 6.0 * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.z - 12.0 * tmp.x * tmp.x * tmp.z * ray->dir.z + 27.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.z - 27.0 * tmp.y * tmp.y * tmp.z * ray->dir.z + 6.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.z * ray->dir.z + 243.0 / 8.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.z + 6.0 * tmp.z * ray->dir.z;
  s[6] = -1.0 + 3.0 * tmp.x * tmp.x - 27.0 / 2.0 * tmp.x * tmp.x * tmp.y * tmp.y + 27.0 / 4.0 * tmp.y * tmp.y + 27.0 / 4.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.y * tmp.y - 6.0 * tmp.x * tmp.x * tmp.z * tmp.z - 27.0 / 2.0 * tmp.y * tmp.y * tmp.z * tmp.z + 27.0 / 2.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.z * tmp.z + 3.0 * tmp.z * tmp.z + 3.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.z * tmp.z + 243.0 / 16.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z - tmp.x * tmp.x * tmp.z * tmp.z * tmp.z - 9.0 / 8.0 * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z - 3.0 * tmp.x * tmp.x * tmp.x * tmp.x + 243.0 / 16.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y - 243.0 / 16.0 * tmp.y * tmp.y * tmp.y * tmp.y + 3.0 * tmp.x * tmp.x * tmp.z * tmp.z * tmp.z * tmp.z + 27.0 / 4.0 * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * tmp.z - 3.0 * tmp.z * tmp.z * tmp.z * tmp.z + tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x + 729.0 / 64.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y + tmp.z * tmp.z * tmp.z * tmp.z * tmp.z * tmp.z;
  if ((inter->dist = solver_n_degree(s, 6)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_heart(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_heart(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}