/*
** klein_coefs2.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Mon May  9 05:20:09 2016 Antoine Baché
*/

#include "engine/intersect.h"

inline static double		calc_g_more_klein(t_ray *ray)
{
  return (ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z *
	  ray->pos.z + (3 * ray->pos.y * ray->pos.y - 2 * ray->pos.y + 3 *
			ray->pos.x * ray->pos.x - 11) * ray->pos.z * ray->pos.z
	  * ray->pos.z * ray->pos.z + 16 * ray->pos.x * ray->pos.z * ray->pos.z
	  * ray->pos.z + (3 * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y
			  - 4 * ray->pos.y * ray->pos.y * ray->pos.y +
			  (6 * ray->pos.x * ray->pos.x - 18) * ray->pos.y *
			  ray->pos.y + (-4 * ray->pos.x * ray->pos.x - 12) *
			  ray->pos.y + 3 * ray->pos.x * ray->pos.x * ray->pos.x
			  * ray->pos.x - 14 * ray->pos.x * ray->pos.x + 11));
}

double				calc_g_klein(t_ray *ray)
{
  return (calc_g_more_klein(ray) * ray->pos.z * ray->pos.z +
	  (16 * ray->pos.x * ray->pos.y * ray->pos.y - 32 * ray->pos.x *
	   ray->pos.y + 16 * ray->pos.x * ray->pos.x * ray->pos.x - 16 *
	   ray->pos.x) * ray->pos.z + ray->pos.y * ray->pos.y * ray->pos.y *
	  ray->pos.y * ray->pos.y * ray->pos.y - 2 * ray->pos.y * ray->pos.y *
	  ray->pos.y * ray->pos.y * ray->pos.y + (3 * ray->pos.x * ray->pos.x -
						  7) * ray->pos.y * ray->pos.y
	  * ray->pos.y * ray->pos.y + (12 - 4 * ray->pos.x * ray->pos.x) *
	  ray->pos.y * ray->pos.y * ray->pos.y +
	  (3 * ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x - 10 *
	   ray->pos.x * ray->pos.x + 7) * ray->pos.y * ray->pos.y +
	  (-2 * ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x + 4 *
	   ray->pos.x * ray->pos.x - 2) * ray->pos.y + ray->pos.x * ray->pos.x
	  * ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x - 3 * ray->pos.x
	  * ray->pos.x * ray->pos.x * ray->pos.x + 3 * ray->pos.x * ray->pos.x
	  - 1);
}

inline static double   		calc_f_more_2_klein(t_ray *ray)
{
  return (ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z +
	  (12 * ray->pos.y * ray->pos.y * ray->pos.y - 12 * ray->pos.y *
	   ray->pos.y + (12 * ray->pos.x * ray->pos.x - 36) * ray->pos.y - 4 *
	   ray->pos.x * ray->pos.x - 12) * ray->pos.z * ray->pos.z +
	  (32 * ray->pos.x * ray->pos.y - 32 * ray->pos.x) * ray->pos.z + 6 *
	  ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y -
	  10 * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y +
	  (12 * ray->pos.x * ray->pos.x - 28) * ray->pos.y * ray->pos.y *
	  ray->pos.y);
}

inline static double		calc_f_more_klein(t_ray *ray)
{
  return ((6 * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z +
	   (12 * ray->pos.y * ray->pos.y - 8 * ray->pos.y + 12 * ray->pos.x *
	    ray->pos.x - 44) * ray->pos.z * ray->pos.z * ray->pos.z + 48 *
	   ray->pos.x * ray->pos.z * ray->pos.z +
	   (6 * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y - 8 *
	    ray->pos.y * ray->pos.y * ray->pos.y +
	    (12 * ray->pos.x * ray->pos.x - 36) * ray->pos.y * ray->pos.y +
	    (-8 * ray->pos.x * ray->pos.x - 24) * ray->pos.y + 6 * ray->pos.x *
	    ray->pos.x * ray->pos.x * ray->pos.x - 28 * ray->pos.x * ray->pos.x
	    + 22) * ray->pos.z + 16 * ray->pos.x * ray->pos.y * ray->pos.y -
	   32 * ray->pos.x * ray->pos.y + 16 * ray->pos.x * ray->pos.x *
	   ray->pos.x - 16 * ray->pos.x) * ray->dir.z);
}

double				calc_f_klein(t_ray *ray)
{
  return (calc_f_more_klein(ray) + ((6 * ray->pos.y - 2) *
				    calc_f_more_2_klein(ray) +
				    (36 - 12 * ray->pos.x * ray->pos.x) *
				    ray->pos.y * ray->pos.y +
				    (6 * ray->pos.x * ray->pos.x * ray->pos.x *
				     ray->pos.x - 20 * ray->pos.x * ray->pos.x
				     + 14) * ray->pos.y - 2 * ray->pos.x *
				    ray->pos.x * ray->pos.x * ray->pos.x + 4 *
				    ray->pos.x * ray->pos.x - 2) * ray->dir.y +
	  (6 * ray->pos.x * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z +
	   16 * ray->pos.z * ray->pos.z * ray->pos.z +
	   (12 * ray->pos.x * ray->pos.y * ray->pos.y - 8 * ray->pos.x *
	    ray->pos.y + 12 * ray->pos.x * ray->pos.x * ray->pos.x - 28 *
	    ray->pos.x) * ray->pos.z * ray->pos.z +
	   (16 * ray->pos.y * ray->pos.y - 32 * ray->pos.y + 48 * ray->pos.x *
	    ray->pos.x - 16) * ray->pos.z + 6 * ray->pos.x * ray->pos.y *
	   ray->pos.y * ray->pos.y * ray->pos.y - 8 * ray->pos.x * ray->pos.y *
	   ray->pos.y * ray->pos.y +
	   (12 * ray->pos.x * ray->pos.x * ray->pos.x - 20 * ray->pos.x) *
	   ray->pos.y * ray->pos.y + (8 * ray->pos.x - 8 * ray->pos.x *
				      ray->pos.x * ray->pos.x) * ray->pos.y + 6
	   * ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x -
	   12 * ray->pos.x * ray->pos.x * ray->pos.x + 6 * ray->pos.x) *
	  ray->dir.x);
}
