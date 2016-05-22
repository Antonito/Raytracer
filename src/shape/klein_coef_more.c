/*
** klein_coefs2.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Sun May 22 20:37:05 2016 Antoine Baché
*/

#include "engine/intersect.h"

double			calc_g_klein(t_ray *ray, t_vec3 tmp, t_vec3 pos)
{
  (void)pos;
  return (-2.0 * tmp.x * tmp.x * tmp.y * tmp.y + 3.0 * tmp.x * tmp.x * tmp.x *
	  tmp.x * tmp.y * tmp.y - 10.0 * tmp.x * tmp.x * tmp.z * tmp.z - 10.0 *
	  tmp.y * tmp.y * tmp.z * tmp.z + 6.0 * tmp.x * tmp.x * tmp.y * tmp.y *
	  tmp.z * tmp.z + 4.0 * tmp.y * tmp.y * tmp.y * tmp.z * tmp.z + 3.0 *
	  tmp.x * tmp.x * tmp.x * tmp.x * tmp.z * tmp.z + 3.0 * tmp.y * tmp.y *
	  tmp.y * tmp.y * tmp.z * tmp.z + 8.0 * tmp.z * tmp.z + 4.0 * tmp.x *
	  tmp.x * tmp.y * tmp.z * tmp.z - 16.0 * tmp.y * tmp.z * tmp.z + 4.0 *
	  tmp.x * tmp.x * tmp.y * tmp.y * tmp.y + 16.0 * tmp.x * tmp.z * tmp.z *
	  tmp.z - tmp.x * tmp.x * tmp.x * tmp.x - tmp.y * tmp.y * tmp.y * tmp.y
	  + 3.0 * tmp.x * tmp.x * tmp.y * tmp.y * tmp.y * tmp.y + 3.0 * tmp.x *
	  tmp.x * tmp.z * tmp.z * tmp.z * tmp.z + 3.0 * tmp.y * tmp.y * tmp.z *
	  tmp.z * tmp.z * tmp.z - 9.0 * tmp.z * tmp.z * tmp.z * tmp.z + 2.0 *
	  tmp.y * tmp.z * tmp.z * tmp.z * tmp.z + 2.0 * tmp.y * tmp.y * tmp.y *
	  tmp.y * tmp.y + tmp.x * tmp.x * tmp.x * tmp.x * tmp.x * tmp.x + tmp.y
	  * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y + tmp.z * tmp.z * tmp.z *
	  tmp.z * tmp.z * tmp.z + 2.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.y +
	  16.0 * tmp.x * tmp.y * tmp.y * tmp.z + 16.0 * tmp.x * tmp.x * tmp.x *
	  tmp.z - 16.0 * tmp.x * tmp.z - 32.0 * tmp.x * tmp.y * tmp.z);
}

inline static double	calc_f_more_klein(t_ray *ray, t_vec3 tmp, t_vec3 pos)
{
  (void)pos;
  return (12.0 * tmp.x * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.x - 4.0 *
	  tmp.x * tmp.y * tmp.y * ray->dir.x + 12.0 * tmp.x * tmp.y * tmp.y *
	  tmp.z * tmp.z * ray->dir.x + 12.0 * tmp.x * tmp.x * tmp.x * tmp.z *
	  tmp.z * ray->dir.x - 20.0 * tmp.x * tmp.z * tmp.z * ray->dir.x + 8.0
	  * tmp.x * tmp.y * tmp.z * tmp.z * ray->dir.x - 4.0 * tmp.x * tmp.x *
	  tmp.x * ray->dir.x + 8.0 * tmp.x * tmp.y * tmp.y * tmp.y * ray->dir.x
	  + 16.0 * tmp.z * tmp.z * tmp.z * ray->dir.x + 6.0 * tmp.x * tmp.y *
	  tmp.y * tmp.y * tmp.y * ray->dir.x + 6.0 * tmp.x * tmp.z * tmp.z *
	  tmp.z * tmp.z * ray->dir.x + 6.0 * tmp.x * tmp.x * tmp.x * tmp.x *
	  tmp.x * ray->dir.x + 8.0 * tmp.x * tmp.x * tmp.x * tmp.y * ray->dir.x
	  + 48.0 * tmp.x * tmp.x * tmp.z * ray->dir.x + 16.0 * tmp.y * tmp.y *
	  tmp.z * ray->dir.x - 16.0 * tmp.z * ray->dir.x - 32.0 * tmp.y * tmp.z
	  * ray->dir.x + 12.0 * tmp.x * tmp.x * tmp.y * tmp.y * ray->dir.y +
	  4.0 * tmp.x * tmp.x * tmp.z * tmp.z * ray->dir.y + 12.0 * tmp.y *
	  tmp.y * tmp.z * tmp.z * ray->dir.y + 12.0 * tmp.y * tmp.y * tmp.y *
	  tmp.z * tmp.z * ray->dir.y - 16.0 * tmp.z * tmp.z * ray->dir.y - 20.0
	  * tmp.y * tmp.z * tmp.z * ray->dir.y + 12.0 * tmp.x * tmp.x * tmp.y *
	  tmp.z * tmp.z * ray->dir.y);
}

double			calc_f_klein(t_ray *ray, t_vec3 tmp, t_vec3 pos)
{
  return (calc_f_more_klein(ray, tmp, pos) + 12.0 * tmp.x * tmp.x * tmp.y *
	  tmp.y *
	  tmp.y * ray->dir.y - 4.0 * tmp.y * tmp.y * tmp.y * ray->dir.y + 2.0 *
	  tmp.x * tmp.x * tmp.x * tmp.x * ray->dir.y + 10.0 * tmp.y * tmp.y *
	  tmp.y * tmp.y * ray->dir.y + 2.0 * tmp.z * tmp.z * tmp.z * tmp.z *
	  ray->dir.y + 6.0 * tmp.y * tmp.z * tmp.z * tmp.z * tmp.z * ray->dir.y
	  + 6.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.y * ray->dir.y - 4.0 *
	  tmp.x * tmp.x * tmp.y * ray->dir.y + 6.0 * tmp.x * tmp.x * tmp.x *
	  tmp.x * tmp.y * ray->dir.y - 32.0 * tmp.x * tmp.z * ray->dir.y + 32.0
	  * tmp.x * tmp.y * tmp.z * ray->dir.y + 16.0 * tmp.x * tmp.y * tmp.y *
	  ray->dir.z + 48.0 * tmp.x * tmp.z * tmp.z * ray->dir.z + 16.0 * tmp.x
	  * tmp.x * tmp.x * ray->dir.z + 12.0 * tmp.x * tmp.x * tmp.z * tmp.z
	  * tmp.z * ray->dir.z + 12.0 * tmp.y * tmp.y * tmp.z * tmp.z * tmp.z *
	  ray->dir.z - 36.0 * tmp.z * tmp.z * tmp.z * ray->dir.z + 8.0 * tmp.y
	  * tmp.z * tmp.z * tmp.z * ray->dir.z + 6.0 * tmp.z * tmp.z * tmp.z *
	  tmp.z * tmp.z * ray->dir.z - 16.0 * tmp.x * ray->dir.z - 32.0 * tmp.x
	  * tmp.y * ray->dir.z - 20.0 * tmp.x * tmp.x * tmp.z * ray->dir.z -
	  20.0 * tmp.y * tmp.y * tmp.z * ray->dir.z + 12.0 * tmp.x * tmp.x *
	  tmp.y * tmp.y * tmp.z * ray->dir.z + 8.0 * tmp.y * tmp.y * tmp.y *
	  tmp.z * ray->dir.z + 6.0 * tmp.x * tmp.x * tmp.x * tmp.x * tmp.z *
	  ray->dir.z + 6.0 * tmp.y * tmp.y * tmp.y * tmp.y * tmp.z * ray->dir.z
	  + 16.0 * tmp.z * ray->dir.z - 32.0 * tmp.y * tmp.z * ray->dir.z +
	  8.0 * tmp.x * tmp.x * tmp.y * tmp.z * ray->dir.z);
}
