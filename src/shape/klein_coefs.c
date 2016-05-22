/*
** klein_coefs.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Sun May 22 19:18:32 2016 Ludovic Petrenko
*/

#include "engine/intersect.h"

double	calc_e_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir, t_vec3 pos)
{
  return (-6.0 * pos.x * dir.x - 2.0 * pos.y
	  * dir.x + 18.0 * pos.x * pos.y *
	  dir.x - 10.0 * pos.z * ray->dir.x *
	  ray->dir.x + 18.0 * pos.x * pos.z * ray->dir.x *
	  ray->dir.x + 6.0 * pos.y * pos.z * ray->dir.x *
	  ray->dir.x + 4.0 * tmp.y * pos.z * dir.x +
	  4.0 * pos.y * tmp.y * dir.x + 15.0 * tmp.x
	  * pos.x * tmp.x * dir.x + 3.0 * tmp.y *
	  pos.y * tmp.y * dir.x + 3.0 * pos.z
	  * pos.z * dir.x + 12.0 * pos.x *
	  tmp.y * dir.x + 48.0 * tmp.x * tmp.z * ray->dir.x *
	  ray->dir.x - 2.0 * pos.x * dir.y + 18.0 *
	  pos.x * pos.y * dir.y - 6.0 * tmp.y
	  * tmp.y * dir.y - 10.0 * pos.z * ray->dir.y
	  * ray->dir.y + 6.0 * pos.x * pos.z * ray->dir.y *
	  ray->dir.y + 18.0 * pos.y * pos.z * ray->dir.y *
	  ray->dir.y + 12.0 * tmp.y * pos.z * dir.y +
	  20.0 * pos.y * tmp.y * dir.y + 3.0 * tmp.x
	  * pos.x * tmp.x * dir.y + 15.0 * tmp.y *
	  pos.y * tmp.y * dir.y + 3.0 * pos.z
	  * pos.z * dir.y + 12.0 * pos.x *
	  tmp.y * dir.y + 16.0 * tmp.x * tmp.z * ray->dir.y *
	  ray->dir.y - 10.0 * pos.x * dir.z - 10.0 *
	  pos.y * dir.z + 6.0 * pos.x * tmp.y
	  * tmp.y * dir.z + 18.0 * pos.x * tmp.z *
	  tmp.z * dir.z + 18.0 * pos.y * tmp.z *
	  tmp.z * dir.z - 54.0 * pos.z * ray->dir.z *
	  ray->dir.z + 12.0 * tmp.y * pos.z * dir.z +
	  4.0 * pos.y * tmp.y * dir.z + 3.0 * tmp.x *
	  pos.x * tmp.x * dir.z + 3.0 * pos.y
	  * pos.y * dir.z + 15.0 * pos.z *
	  pos.z * dir.z + 8.0 * ray->dir.z *
	  ray->dir.z + 4.0 * pos.x * tmp.y * dir.z -
	  16.0 * tmp.y * dir.z + 48.0 * tmp.x * tmp.z *
	  dir.z + 24.0 * tmp.x * pos.y * ray->dir.x *
	  ray->dir.y + 8.0 * tmp.x * pos.z * ray->dir.x * ray->dir.y +
	  24.0 * tmp.x * tmp.y * pos.z * ray->dir.x * ray->dir.y + 8.0
	  * pos.x * tmp.x * ray->dir.x * ray->dir.y + 24.0 * tmp.x *
	  pos.y * tmp.y * ray->dir.x * ray->dir.y + 24.0 * tmp.x *
	  pos.x * tmp.y * ray->dir.x * ray->dir.y - 8.0 * tmp.x * tmp.y
	  * ray->dir.x * ray->dir.y - 32.0 * tmp.z * ray->dir.x * ray->dir.y +
	  32.0 * tmp.y * tmp.z * ray->dir.x * ray->dir.y + 48.0 * pos.x
	  * ray->dir.x * ray->dir.z + 16.0 * pos.y * ray->dir.x *
	  ray->dir.z + 48.0 * pos.z * ray->dir.x * ray->dir.z + 24.0 *
	  tmp.x * pos.z * tmp.z * ray->dir.x * ray->dir.z - 16.0 *
	  ray->dir.x * ray->dir.z - 32.0 * tmp.y * ray->dir.x * ray->dir.z +
	  24.0 * tmp.x * pos.y * tmp.z * ray->dir.x * ray->dir.z + 24.0
	  * pos.x * tmp.x * tmp.z * ray->dir.x * ray->dir.z - 40.0 *
	  tmp.x * tmp.z * ray->dir.x * ray->dir.z + 16.0 * tmp.x * tmp.y *
	  tmp.z * ray->dir.x * ray->dir.z + 8.0 * pos.z * tmp.z *
	  ray->dir.y * ray->dir.z + 24.0 * tmp.y * pos.z * tmp.z *
	  ray->dir.y * ray->dir.z - 32.0 * tmp.x * ray->dir.y * ray->dir.z +
	  32.0 * tmp.x * tmp.y * ray->dir.y * ray->dir.z - 32.0 * tmp.z *
	  ray->dir.y * ray->dir.z + 8.0 * pos.x * tmp.z * ray->dir.y *
	  ray->dir.z + 24.0 * pos.y * tmp.z * ray->dir.y * ray->dir.z +
	  24.0 * pos.y * tmp.y * tmp.z * ray->dir.y * ray->dir.z - 40.0
	  * tmp.y * tmp.z * ray->dir.y * ray->dir.z + 24.0 * pos.x *
	  tmp.y * tmp.z * ray->dir.y * ray->dir.z);
}

double	calc_d_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir, t_vec3 pos)
{
  return (36.0 * tmp.x * pos.y * ray->dir.x * dir.y +
	  12.0 * tmp.x * pos.z * ray->dir.x * dir.y +
	  12.0 * pos.x * tmp.x * ray->dir.x * dir.y -
	  4.0 * tmp.x * ray->dir.x * dir.y + 24.0 * tmp.x *
	  tmp.y * ray->dir.x * dir.y + 16.0 * tmp.z *
	  ray->dir.x * dir.y + 12.0 * tmp.x * pos.y *
	  ray->dir.x * dir.z + 36.0 * tmp.x * pos.z *
	  ray->dir.x * dir.z + 12.0 * pos.x * tmp.x *
	  ray->dir.x * dir.z - 20.0 * tmp.x * ray->dir.x *
	  dir.z + 8.0 * tmp.x * tmp.y * ray->dir.x *
	  dir.z + 48.0 * tmp.z * ray->dir.x * ray->dir.z *
	  ray->dir.z + 4.0 * pos.x * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * pos.y * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * pos.z * ray->dir.y * ray->dir.z *
	  ray->dir.z + 36.0 * tmp.y * pos.z * ray->dir.y * ray->dir.z *
	  ray->dir.z + 12.0 * pos.y * tmp.y * ray->dir.y * ray->dir.z *
	  ray->dir.z - 16.0 * ray->dir.y * dir.z - 20.0 *
	  tmp.y * ray->dir.y * dir.z + 12.0 * pos.x *
	  tmp.y * ray->dir.y * dir.z + 12.0 * tmp.x * tmp.y *
	  tmp.y * dir.x * ray->dir.x + 12.0 * tmp.x * tmp.z *
	  tmp.z * dir.x * ray->dir.x + 20.0 * pos.x *
	  tmp.x * dir.x * ray->dir.x - 4.0 * tmp.x *
	  dir.x * ray->dir.x + 8.0 * tmp.x * tmp.y *
	  dir.x * ray->dir.x + 16.0 * tmp.z * ray->dir.x *
	  dir.x + 4.0 * pos.x * ray->dir.y *
	  dir.y + 20.0 * pos.y * ray->dir.y *
	  dir.y + 4.0 * pos.z * ray->dir.y *
	  dir.y + 12.0 * tmp.y * pos.z * ray->dir.y
	  * dir.y + 20.0 * pos.y * tmp.y *
	  dir.y * ray->dir.y + 12.0 * pos.x * tmp.y
	  * dir.y * ray->dir.y - 4.0 * tmp.y * ray->dir.y *
	  dir.y + 20.0 * pos.z * tmp.z * ray->dir.z
	  * dir.z + 16.0 * tmp.x * dir.z *
	  ray->dir.z + 12.0 * pos.x * tmp.z * dir.z
	  * ray->dir.z + 12.0 * pos.y * tmp.z * ray->dir.z *
	  dir.z - 36.0 * tmp.z * dir.z *
	  ray->dir.z + 8.0 * tmp.y * tmp.z * dir.z *
	  ray->dir.z + 12.0 * pos.x * dir.x *
	  ray->dir.y + 12.0 * pos.y * dir.x *
	  ray->dir.y + 4.0 * pos.z * dir.x *
	  ray->dir.y + 12.0 * tmp.y * pos.z * dir.x
	  * ray->dir.y + 12.0 * pos.y * tmp.y * ray->dir.x *
	  ray->dir.x * ray->dir.y + 36.0 * pos.x * tmp.y * ray->dir.x
	  * ray->dir.x * ray->dir.y - 4.0 * tmp.y * dir.x *
	  ray->dir.y + 12.0 * pos.z * tmp.z * dir.x
	  * ray->dir.z + 48.0 * tmp.x * dir.x * ray->dir.z -
	  20.0 * tmp.z * dir.x * ray->dir.z + 36.0 * tmp.x *
	  tmp.x * tmp.z * dir.x * ray->dir.z + 12.0 * tmp.y
	  * tmp.y * tmp.z * dir.x * ray->dir.z + 8.0 * tmp.y
	  * tmp.z * dir.x * ray->dir.z + 12.0 * tmp.z *
	  pos.z * dir.y * ray->dir.z + 16.0 * tmp.x
	  * dir.y * ray->dir.z - 20.0 * tmp.z * ray->dir.y *
	  ray->dir.y * ray->dir.z + 12.0 * pos.x * tmp.z * ray->dir.y
	  * ray->dir.y * ray->dir.z + 36.0 * pos.y * tmp.z * ray->dir.y
	  * ray->dir.y * ray->dir.z + 24.0 * tmp.y * tmp.z * ray->dir.y *
	  ray->dir.y * ray->dir.z - 32.0 * ray->dir.x * ray->dir.y *
	  ray->dir.z + 32.0 * tmp.y * ray->dir.x * ray->dir.y * ray->dir.z +
	  16.0 * tmp.x * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z + 48.0 *
	  tmp.x * tmp.y * tmp.z * ray->dir.x * ray->dir.y * ray->dir.z);
}
