/*
** duplin.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 00:54:23 2016 Antoine Baché
** Last update Sun May 15 01:05:29 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_duplin(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	s[5];

  s[0] = -102.2238 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y - 102.2238 * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z - 102.2238 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 51.1119 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x - 51.1119 * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y - 51.1119 * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z;
  s[1] = 141.12 * ray->dir.x * ray->dir.y * ray->dir.y - 204.4476 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 141.12 * ray->dir.x * ray->dir.z * ray->dir.z - 204.4476 * tmp.x * ray->dir.x * ray->dir.z * ray->dir.z - 204.4476 * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 141.12 * ray->dir.x * ray->dir.x * ray->dir.x - 204.4476 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.x - 204.4476 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y - 204.4476 * tmp.z * ray->dir.z * ray->dir.z * ray->dir.z - 204.4476 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y - 204.4476 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z - 204.4476 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z;
  s[2] = -306.6714 * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 102.2238 * tmp.y * tmp.y * ray->dir.x * ray->dir.x - 102.2238 * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 114.88 * ray->dir.x * ray->dir.x + 423.36 * tmp.x * ray->dir.x * ray->dir.x + 141.12 * ray->dir.y * ray->dir.y - 102.2238 * tmp.x * tmp.x * ray->dir.y * ray->dir.y - 306.6714 * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 102.2238 * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 141.12 * tmp.x * ray->dir.y * ray->dir.y - 141.12 * ray->dir.z * ray->dir.z - 102.2238 * tmp.x * tmp.x * ray->dir.z * ray->dir.z - 102.2238 * tmp.y * tmp.y * ray->dir.z * ray->dir.z - 306.6714 * tmp.z * tmp.z * ray->dir.z * ray->dir.z + 141.12 * tmp.x * ray->dir.z * ray->dir.z + 282.24 * tmp.y * ray->dir.x * ray->dir.y - 408.8952 * tmp.x * tmp.y * ray->dir.x * ray->dir.y + 282.24 * tmp.z * ray->dir.x * ray->dir.z - 408.8952 * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 408.8952 * tmp.y * tmp.z * ray->dir.y * ray->dir.z;
  s[3] = 512.0 * ray->dir.x + 423.36 * tmp.x * tmp.x * ray->dir.x + 141.12 * tmp.y * tmp.y * ray->dir.x - 204.4476 * tmp.x * tmp.y * tmp.y * ray->dir.x + 141.12 * tmp.z * tmp.z * ray->dir.x - 204.4476 * tmp.x * tmp.z * tmp.z * ray->dir.x - 204.4476 * tmp.x * tmp.x * tmp.x * ray->dir.x + 229.76 * tmp.x * ray->dir.x - 204.4476 * tmp.y * tmp.z * tmp.z * ray->dir.y - 204.4476 * tmp.y * tmp.y * tmp.y * ray->dir.y - 204.4476 * tmp.x * tmp.x * tmp.y * ray->dir.y + 282.24 * tmp.y * ray->dir.y + 282.24 * tmp.x * tmp.y * ray->dir.y - 204.4476 * tmp.z * tmp.z * tmp.z * ray->dir.z - 204.4476 * tmp.x * tmp.x * tmp.z * ray->dir.z - 204.4476 * tmp.y * tmp.y * tmp.z * ray->dir.z - 282.24 * tmp.z * ray->dir.z + 282.24 * tmp.x * tmp.z * ray->dir.z;
  s[4] = 114.88 * tmp.x * tmp.x + 141.12 * tmp.y * tmp.y - 102.2238 * tmp.x * tmp.x * tmp.y * tmp.y + 141.12 * tmp.x * tmp.y * tmp.y - 141.12 * tmp.z * tmp.z - 102.2238 * tmp.x * tmp.x * tmp.z * tmp.z - 102.2238 * tmp.y * tmp.y * tmp.z * tmp.z + 141.12 * tmp.x * tmp.z * tmp.z + 141.12 * tmp.x * tmp.x * tmp.x - 51.1119 * tmp.x * tmp.x * tmp.x * tmp.x - 51.1119 * tmp.y * tmp.y * tmp.y * tmp.y - 51.1119 * tmp.z * tmp.z * tmp.z * tmp.z + 256.0 - 512.0 * tmp.x;
  if ((inter->dist = solver_fourth_degree(s[0], s[1], s[2], s[3], s[4])) ==
      NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_duplin(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_duplin(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
