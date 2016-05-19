/*
** bohemian_star.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May 16 02:10:44 2016 Antoine Baché
** Last update Wed May 18 02:58:14 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void		get_dist_bohemian_star(t_ray *ray, t_intersect *inter,
				       t_vec3 tmp)
{
  double		*s;

  if (!(s = my_malloc(sizeof(double) * 9)))
    return ;
  s[0] = 2.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 2.0 * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z
    + ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 2.0 *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.y * ray->dir.y + ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y;
  s[1] = 8.0 * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 4.0 * tmp.x * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z
    + 12.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 4.0 * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y
    + 4.0 * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.z * ray->dir.z * ray->dir.z + 4.0 * tmp.x * ray->dir.x *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    + 4.0 * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z *
    ray->dir.z * ray->dir.z * ray->dir.z + 12.0 * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    + 4.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + 8.0 * tmp.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    + 4.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.z + 4.0 * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z;
  s[2] = 6.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x *
    ray->dir.x * ray->dir.y * ray->dir.y + 12.0 * tmp.y * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 16.0 *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z
    + 16.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.z * ray->dir.z + 2.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 30.0 * tmp.y * tmp.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z
    + 6.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.z * ray->dir.z - 4.0 * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 16.0 * tmp.x * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y + 16.0 *
    tmp.y * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z *
    ray->dir.z * ray->dir.z + 6.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 30.0 * tmp.y * tmp.y *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    + 2.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y - 4.0 * ray->dir.x * ray->dir.x * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + 6.0 * tmp.y * tmp.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 24.0 *
    tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y + 2.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 28.0 * tmp.y * tmp.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    + 2.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y + 16.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 8.0 * tmp.x * tmp.z *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z
    + 24.0 * tmp.y * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.y * ray->dir.z;
  s[3] = 24.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y + 24.0 * tmp.x * tmp.y * tmp.y * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 32.0 * tmp.x *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 24.0 *
    tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z *
    ray->dir.z + 40.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z * ray->dir.z + 8.0 * tmp.x * tmp.x * tmp.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z - 16.0 *
    tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z +
    8.0 * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y *
    ray->dir.z * ray->dir.z - 32.0 * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.z * ray->dir.z + 8.0 * tmp.y * tmp.z * tmp.z *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y + 40.0 *
    tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.y + 24.0 * tmp.x * tmp.x * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y - 16.0 * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y + 24.0 * tmp.y * tmp.y *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z * ray->dir.z +
    60.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y + 4.0 * tmp.x * tmp.z * tmp.z * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 4.0 * tmp.x * tmp.x *
    tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y -
    8.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y + 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z *
    ray->dir.z * ray->dir.z * ray->dir.z + 12.0 * tmp.y * tmp.z * tmp.z *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 56.0 *
    tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y
    * ray->dir.y + 12.0 * tmp.x * tmp.x * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + 4.0 * tmp.y * tmp.y * tmp.y *
    ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y - 32.0 *
    tmp.z * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.z +
    24.0 * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y *
    ray->dir.y * ray->dir.z + 32.0 * tmp.x * tmp.y * tmp.z * ray->dir.x *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 4.0 * tmp.z * tmp.z *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z +
    4.0 * tmp.x * tmp.x * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.z + 60.0 * tmp.y * tmp.y * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z - 8.0 * tmp.z *
    ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z;
  s[4] = 36.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y - 24.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.y + 12.0 * tmp.y * tmp.y * tmp.z * tmp.z *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y - 16.0 * tmp.z * tmp.z *
    ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y + 30.0 * tmp.y * tmp.y *
    tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y - 16.0 *
    tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z + 2.0 *
    tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.z *
    ray->dir.z + 16.0 * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z -
    16.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z +
    12.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.z * ray->dir.z - 24.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.z * ray->dir.z + 36.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y
    * ray->dir.y * ray->dir.z * ray->dir.z + 30.0 * tmp.y * tmp.y * tmp.y *
    tmp.y * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 16.0 * tmp.x *
    tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z
    - 64.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.z * ray->dir.z
    + 16.0 * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y *
    ray->dir.y * ray->dir.y + 80.0 * tmp.x * tmp.y * tmp.y * tmp.y *
    ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y + 16.0 * tmp.x * tmp.x *
    tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y - 32.0 *
    tmp.x * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y + 16.0 *
    tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z * ray->dir.z *
    ray->dir.z + tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.x * ray->dir.x - 4.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y *
    ray->dir.y * ray->dir.y + 30.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y
    * ray->dir.y * ray->dir.y * ray->dir.y + 2.0 * tmp.x * tmp.x * tmp.z *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 30.0 * tmp.y *
    tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y -
    4.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y +
    tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.y * ray->dir.y * ray->dir.y *
    ray->dir.y + 70.0 * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y
    * ray->dir.y * ray->dir.y + tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.y + tmp.y * tmp.y * tmp.y * tmp.y *
    ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z + 16.0 * tmp.x * tmp.y *
    tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y + 48.0 *
    tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.z - 64.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y *
    ray->dir.z + 16.0 * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.y * ray->dir.z + 80.0 * tmp.y * tmp.y * tmp.y *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z - 32.0 * tmp.y *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z + 16.0 * tmp.x *
    tmp.x * tmp.y * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.z
    + 16.0 * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.z - 64.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.x *
    ray->dir.y * ray->dir.z;
  s[5] = 24.0 * tmp.x * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.x *
    ray->dir.y * ray->dir.y - 48.0 * tmp.x * tmp.y * tmp.y * ray->dir.x *
    ray->dir.y * ray->dir.y + 24.0 * tmp.x * tmp.y * tmp.y * tmp.z * tmp.z *
    ray->dir.x * ray->dir.y * ray->dir.y - 32.0 * tmp.x * tmp.z * tmp.z *
    ray->dir.x * ray->dir.y * ray->dir.y + 60.0 * tmp.x * tmp.y * tmp.y *
    tmp.y * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y - 32.0 * tmp.x *
    tmp.y * tmp.y * ray->dir.x * ray->dir.z * ray->dir.z + 4.0 * tmp.x * tmp.y
    * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.z * ray->dir.z + 32.0 *
    tmp.x * ray->dir.x * ray->dir.z * ray->dir.z + 24.0 * tmp.y * tmp.y *
    tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.z * ray->dir.z + 8.0 * tmp.x
    * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z -
    16.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 12.0
    * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z *
    ray->dir.z - 32.0 * tmp.x * tmp.x * tmp.y * ray->dir.y * ray->dir.z *
    ray->dir.z + 4.0 * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x *
    ray->dir.x * ray->dir.x + 40.0 * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z *
    ray->dir.y * ray->dir.y * ray->dir.y + 8.0 * tmp.x * tmp.x * tmp.y * tmp.z
    * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y - 16.0 * tmp.y * tmp.z *
    tmp.z * ray->dir.y * ray->dir.y * ray->dir.y + 40.0 * tmp.x * tmp.x *
    tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y * ray->dir.y + 4.0 * tmp.y
    * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.y +
    56.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.y - 16.0 * tmp.x * tmp.x * tmp.y * ray->dir.y * ray->dir.y *
    ray->dir.y + 4.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.y * ray->dir.y *
    ray->dir.y * ray->dir.y + 4.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z *
    ray->dir.z * ray->dir.z * ray->dir.z + 8.0 * tmp.y * tmp.y * tmp.y * tmp.z
    * tmp.z * ray->dir.x * ray->dir.x * ray->dir.y - 32.0 * tmp.y * tmp.z *
    tmp.z * ray->dir.x * ray->dir.x * ray->dir.y + 24.0 * tmp.x * tmp.x *
    tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y - 16.0 *
    tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x * ray->dir.y + 12.0 *
    tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x *
    ray->dir.y + 32.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z - 32.0 *
    tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 4.0 * tmp.y
    * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z +
    24.0 * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y *
    ray->dir.z - 32.0 * tmp.x * tmp.x * tmp.z * ray->dir.y * ray->dir.y *
    ray->dir.z + 24.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.z - 48.0 * tmp.y * tmp.y * tmp.z * ray->dir.y *
    ray->dir.y * ray->dir.z + 60.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z *
    ray->dir.y * ray->dir.y * ray->dir.z + 32.0 * tmp.x * tmp.y * tmp.y *
    tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z - 128.0 * tmp.x *
    tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z;
  s[6] = -16.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 2.0
    * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x
    + 16.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 6.0 * tmp.x * tmp.x *
    tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x - 4.0 * tmp.y *
    tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 2.0 * tmp.y * tmp.y *
    tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x - 24.0 * tmp.x *
    tmp.x * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 6.0 * tmp.x * tmp.x *
    tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 16.0 * tmp.x *
    tmp.x * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 12.0 * tmp.x * tmp.x *
    tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y - 24.0 * tmp.y *
    tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 30.0 * tmp.y * tmp.y *
    tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 30.0 * tmp.x *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 6.0 *
    tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.y +
    28.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y *
    ray->dir.y + 16.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z - 16.0 * tmp.x
    * tmp.x * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 6.0 * tmp.y * tmp.y *
    tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.z * ray->dir.z + 2.0 * tmp.x *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.z * ray->dir.z - 4.0 *
    tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 2.0 * tmp.y *
    tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 16.0 *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y -
    64.0 * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y + 16.0 *
    tmp.x * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y -
    32.0 * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y + 24.0 *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y -
    64.0 * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.z + 8.0 *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.z +
    64.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.z + 16.0 * tmp.y * tmp.y *
    tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.y * ray->dir.z - 32.0 * tmp.y *
    tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z + 16.0 * tmp.x * tmp.x *
    tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z + 24.0 * tmp.y *
    tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z - 64.0 *
    tmp.x * tmp.x * tmp.y * tmp.z * ray->dir.y * ray->dir.z;
  s[7] = -32.0 * tmp.x * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x + 4.0 *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x + 32.0 *
    tmp.x * tmp.z * tmp.z * ray->dir.x + 4.0 * tmp.x * tmp.x * tmp.x * tmp.y *
    tmp.y * tmp.y * tmp.y * ray->dir.x - 8.0 * tmp.x * tmp.y * tmp.y * tmp.y *
    tmp.y * ray->dir.x + 4.0 * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y *
    tmp.y * ray->dir.x + 8.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.z *
    tmp.z * ray->dir.y - 16.0 * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z *
    ray->dir.y + 12.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z *
    ray->dir.y - 32.0 * tmp.x * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.y -
    16.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.y + 4.0 * tmp.x *
    tmp.x * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.y + 4.0 * tmp.y *
    tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y + 12.0 * tmp.x *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y + 8.0 * tmp.y *
    tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y + 4.0 * tmp.y *
    tmp.y * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z * ray->dir.z + 32.0 * tmp.x *
    tmp.x * tmp.z * ray->dir.z - 32.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.z *
    ray->dir.z + 4.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z *
    ray->dir.z - 8.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.z + 4.0
    * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.z;
  s[8] = 16.0 * tmp.x * tmp.x * tmp.z * tmp.z - 16.0 * tmp.x * tmp.x * tmp.y *
    tmp.y * tmp.z * tmp.z + 2.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y
    * tmp.z * tmp.z - 4.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z + 2.0
    * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z - 4.0 *
    tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y + tmp.x * tmp.x * tmp.x *
    tmp.x * tmp.y * tmp.y * tmp.y * tmp.y + tmp.y * tmp.y * tmp.y * tmp.y *
    tmp.z * tmp.z * tmp.z * tmp.z + 2.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y
    * tmp.y * tmp.y * tmp.y + tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y *
    tmp.y * tmp.y;
  if ((inter->dist = solver_n_degree(s, 8)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect		get_intersect_bohemian_star(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_bohemian_star(ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}