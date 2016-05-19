/*
** klein_coefs.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Wed May 18 03:37:28 2016 Antoine Baché
*/

#include "engine/intersect.h"

double	calc_e_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir, t_vec3 pos)
{
  return (-6.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x - 2.0 * tmp.y * tmp.y
	  * ray->dir.x * ray->dir.x + 18.0 * tmp.x * tmp.x * tmp.y * tmp.y *
	  ray->dir.x * ray->dir.x - 10.0 * tmp.z * tmp.z * ray->dir.x *
	  ray->dir.x + 18.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.x *
	  ray->dir.x + 6.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.x *
	  ray->dir.x + 4.0 * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x +
	  4.0 * tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 15.0 * tmp.x
	  * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.x + 3.0 * tmp.y *
	  tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.x + 3.0 * tmp.z * tmp.z
	  * tmp.z * tmp.z * ray->dir.x * ray->dir.x + 12.0 * tmp.x * tmp.x *
	  tmp.y * ray->dir.x * ray->dir.x + 48.0 * tmp.x * tmp.z * ray->dir.x *
	  ray->dir.x - 2.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.y + 18.0 *
	  tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y * ray->dir.y - 6.0 * tmp.y
	  * tmp.y * ray->dir.y * ray->dir.y - 10.0 * tmp.z * tmp.z * ray->dir.y
	  * ray->dir.y + 6.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.y *
	  ray->dir.y + 18.0 * tmp.y * tmp.y * tmp.z * tmp.z * ray->dir.y *
	  ray->dir.y + 12.0 * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.y +
	  20.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 3.0 * tmp.x
	  * tmp.x * tmp.x * tmp.x * ray->dir.y * ray->dir.y + 15.0 * tmp.y *
	  tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.y + 3.0 * tmp.z * tmp.z
	  * tmp.z * tmp.z * ray->dir.y * ray->dir.y + 12.0 * tmp.x * tmp.x *
	  tmp.y * ray->dir.y * ray->dir.y + 16.0 * tmp.x * tmp.z * ray->dir.y *
	  ray->dir.y - 10.0 * tmp.x * tmp.x * ray->dir.z * ray->dir.z - 10.0 *
	  tmp.y * tmp.y * ray->dir.z * ray->dir.z + 6.0 * tmp.x * tmp.x * tmp.y
	  * tmp.y * ray->dir.z * ray->dir.z + 18.0 * tmp.x * tmp.x * tmp.z *
	  tmp.z * ray->dir.z * ray->dir.z + 18.0 * tmp.y * tmp.y * tmp.z *
	  tmp.z * ray->dir.z * ray->dir.z - 54.0 * tmp.z * tmp.z * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.y * tmp.z * tmp.z * ray->dir.z * ray->dir.z +
	  4.0 * tmp.y * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 3.0 * tmp.x *
	  tmp.x * tmp.x * tmp.x * ray->dir.z * ray->dir.z + 3.0 * tmp.y * tmp.y
	  * tmp.y * tmp.y * ray->dir.z * ray->dir.z + 15.0 * tmp.z * tmp.z *
	  tmp.z * tmp.z * ray->dir.z * ray->dir.z + 8.0 * ray->dir.z *
	  ray->dir.z + 4.0 * tmp.x * tmp.x * tmp.y * ray->dir.z * ray->dir.z -
	  16.0 * tmp.y * ray->dir.z * ray->dir.z + 48.0 * tmp.x * tmp.z *
	  ray->dir.z * ray->dir.z + 24.0 * tmp.x * tmp.y * tmp.y * ray->dir.x *
	  ray->dir.y + 8.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.y +
	  24.0 * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.y + 8.0
	  * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.y + 24.0 * tmp.x *
	  tmp.y * tmp.y * tmp.y * ray->dir.x * ray->dir.y + 24.0 * tmp.x *
	  tmp.x * tmp.x * tmp.y * ray->dir.x * ray->dir.y - 8.0 * tmp.x * tmp.y
	  * ray->dir.x * ray->dir.y - 32.0 * tmp.z * ray->dir.x * ray->dir.y +
	  32.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.y + 48.0 * tmp.x * tmp.x
	  * ray->dir.x * ray->dir.z + 16.0 * tmp.y * tmp.y * ray->dir.x *
	  ray->dir.z + 48.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.z + 24.0 *
	  tmp.x * tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.z - 16.0 *
	  ray->dir.x * ray->dir.z - 32.0 * tmp.y * ray->dir.x * ray->dir.z +
	  24.0 * tmp.x * tmp.y * tmp.y * tmp.z * ray->dir.x * ray->dir.z + 24.0
	  * tmp.x * tmp.x * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 40.0 *
	  tmp.x * tmp.z * ray->dir.x * ray->dir.z + 16.0 * tmp.x * tmp.y *
	  tmp.z * ray->dir.x * ray->dir.z + 8.0 * tmp.z * tmp.z * tmp.z *
	  ray->dir.y * ray->dir.z + 24.0 * tmp.y * tmp.z * tmp.z * tmp.z *
	  ray->dir.y * ray->dir.z - 32.0 * tmp.x * ray->dir.y * ray->dir.z +
	  32.0 * tmp.x * tmp.y * ray->dir.y * ray->dir.z - 32.0 * tmp.z *
	  ray->dir.y * ray->dir.z + 8.0 * tmp.x * tmp.x * tmp.z * ray->dir.y *
	  ray->dir.z + 24.0 * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z +
	  24.0 * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z - 40.0
	  * tmp.y * tmp.z * ray->dir.y * ray->dir.z + 24.0 * tmp.x * tmp.x *
	  tmp.y * tmp.z * ray->dir.y * ray->dir.z);
}

double	calc_d_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir, t_vec3 pos)
{
  return (36.0 * tmp.x * tmp.y * tmp.y * ray->dir.x * ray->dir.y * ray->dir.y +
	  12.0 * tmp.x * tmp.z * tmp.z * ray->dir.x * ray->dir.y * ray->dir.y +
	  12.0 * tmp.x * tmp.x * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y -
	  4.0 * tmp.x * ray->dir.x * ray->dir.y * ray->dir.y + 24.0 * tmp.x *
	  tmp.y * ray->dir.x * ray->dir.y * ray->dir.y + 16.0 * tmp.z *
	  ray->dir.x * ray->dir.y * ray->dir.y + 12.0 * tmp.x * tmp.y * tmp.y *
	  ray->dir.x * ray->dir.z * ray->dir.z + 36.0 * tmp.x * tmp.z * tmp.z *
	  ray->dir.x * ray->dir.z * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.x *
	  ray->dir.x * ray->dir.z * ray->dir.z - 20.0 * tmp.x * ray->dir.x *
	  ray->dir.z * ray->dir.z + 8.0 * tmp.x * tmp.y * ray->dir.x *
	  ray->dir.z * ray->dir.z + 48.0 * tmp.z * ray->dir.x * ray->dir.z *
	  ray->dir.z + 4.0 * tmp.x * tmp.x * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.y * tmp.y * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.z * tmp.z * ray->dir.y * ray->dir.z *
	  ray->dir.z + 36.0 * tmp.y * tmp.z * tmp.z * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.y * tmp.y * tmp.y * ray->dir.y * ray->dir.z *
	  ray->dir.z - 16.0 * ray->dir.y * ray->dir.z * ray->dir.z - 20.0 *
	  tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 12.0 * tmp.x * tmp.x *
	  tmp.y * ray->dir.y * ray->dir.z * ray->dir.z + 12.0 * tmp.x * tmp.y *
	  tmp.y * ray->dir.x * ray->dir.x * ray->dir.x + 12.0 * tmp.x * tmp.z *
	  tmp.z * ray->dir.x * ray->dir.x * ray->dir.x + 20.0 * tmp.x * tmp.x *
	  tmp.x * ray->dir.x * ray->dir.x * ray->dir.x - 4.0 * tmp.x *
	  ray->dir.x * ray->dir.x * ray->dir.x + 8.0 * tmp.x * tmp.y *
	  ray->dir.x * ray->dir.x * ray->dir.x + 16.0 * tmp.z * ray->dir.x *
	  ray->dir.x * ray->dir.x + 4.0 * tmp.x * tmp.x * ray->dir.y *
	  ray->dir.y * ray->dir.y + 20.0 * tmp.y * tmp.y * ray->dir.y *
	  ray->dir.y * ray->dir.y + 4.0 * tmp.z * tmp.z * ray->dir.y *
	  ray->dir.y * ray->dir.y + 12.0 * tmp.y * tmp.z * tmp.z * ray->dir.y
	  * ray->dir.y * ray->dir.y + 20.0 * tmp.y * tmp.y * tmp.y *
	  ray->dir.y * ray->dir.y * ray->dir.y + 12.0 * tmp.x * tmp.x * tmp.y
	  * ray->dir.y * ray->dir.y * ray->dir.y - 4.0 * tmp.y * ray->dir.y *
	  ray->dir.y * ray->dir.y + 20.0 * tmp.z * tmp.z * tmp.z * ray->dir.z
	  * ray->dir.z * ray->dir.z + 16.0 * tmp.x * ray->dir.z * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.z * ray->dir.z * ray->dir.z
	  * ray->dir.z + 12.0 * tmp.y * tmp.y * tmp.z * ray->dir.z *
	  ray->dir.z * ray->dir.z - 36.0 * tmp.z * ray->dir.z * ray->dir.z *
	  ray->dir.z + 8.0 * tmp.y * tmp.z * ray->dir.z * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.x * tmp.x * ray->dir.x * ray->dir.x *
	  ray->dir.y + 12.0 * tmp.y * tmp.y * ray->dir.x * ray->dir.x *
	  ray->dir.y + 4.0 * tmp.z * tmp.z * ray->dir.x * ray->dir.x *
	  ray->dir.y + 12.0 * tmp.y * tmp.z * tmp.z * ray->dir.x * ray->dir.x
	  * ray->dir.y + 12.0 * tmp.y * tmp.y * tmp.y * ray->dir.x *
	  ray->dir.x * ray->dir.y + 36.0 * tmp.x * tmp.x * tmp.y * ray->dir.x
	  * ray->dir.x * ray->dir.y - 4.0 * tmp.y * ray->dir.x * ray->dir.x *
	  ray->dir.y + 12.0 * tmp.z * tmp.z * tmp.z * ray->dir.x * ray->dir.x
	  * ray->dir.z + 48.0 * tmp.x * ray->dir.x * ray->dir.x * ray->dir.z -
	  20.0 * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 36.0 * tmp.x *
	  tmp.x * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 12.0 * tmp.y
	  * tmp.y * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 8.0 * tmp.y
	  * tmp.z * ray->dir.x * ray->dir.x * ray->dir.z + 12.0 * tmp.z *
	  tmp.z * tmp.z * ray->dir.y * ray->dir.y * ray->dir.z + 16.0 * tmp.x
	  * ray->dir.y * ray->dir.y * ray->dir.z - 20.0 * tmp.z * ray->dir.y *
	  ray->dir.y * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.z * ray->dir.y
	  * ray->dir.y * ray->dir.z + 36.0 * tmp.y * tmp.y * tmp.z * ray->dir.y
	  * ray->dir.y * ray->dir.z + 24.0 * tmp.y * tmp.z * ray->dir.y *
	  ray->dir.y * ray->dir.z - 32.0 * ray->dir.x * ray->dir.y *
	  ray->dir.z + 32.0 * tmp.y * ray->dir.x * ray->dir.y * ray->dir.z +
	  16.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z + 48.0 *
	  tmp.x * tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z);
}