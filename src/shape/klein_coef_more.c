/*
** klein_coefs2.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Fri May 13 02:57:27 2016 Antoine Baché
*/

#include "engine/intersect.h"

double	calc_g_klein(t_ray *ray, t_vec3 *tmp, t_vec3 pos)
{
  return (pos.z * pos.z * pos.z + (3 * pos.y - 2 * tmp->y + 3 * pos.x - 11) *
	  pos.z * pos.z + 16 * tmp->x * pos.z * tmp->z +
	  (3 * pos.y * pos.y - 4 * pos.y * tmp->y + (6 * pos.x - 18) * pos.y +
	   (- 4 * pos.x - 12) * tmp->y + 3 * pos.x * pos.x - 14 * pos.x + 11) *
	  pos.z + (16 * tmp->x * pos.y - 32 * tmp->x * tmp->y + 16 * pos.x *
		   tmp->x - 16 * tmp->x) * tmp->z + pos.y * pos.y * pos.y - 2 *
	  pos.y * pos.y * tmp->y + (3 * pos.x - 7) * pos.y * pos.y +
	  (12 - 4 * pos.x) * pos.y * tmp->y +
	  (3 * pos.x * pos.x - 10 * pos.x + 7) * pos.y +
	  (-2 * pos.x * pos.x + 4 * pos.x - 2) *
	  tmp->y + pos.x * pos.x * pos.x - 3 * pos.x * pos.x + 3 * pos.x - 1);
}

double	calc_f_klein(t_ray *ray, t_vec3 *tmp, t_vec3 pos)
{
  return ((6 * pos.z * pos.z * tmp->z +
	   (12 * pos.y - 8 * tmp->y + 12 * pos.x - 44) * pos.z * tmp->z + 48 *
	   tmp->x * pos.z + (6 * pos.y * pos.y - 8 * pos.y * tmp->y +
			     (12 * pos.x - 36) * pos.y + (-8 * pos.x - 24) *
			     tmp->y + 6 * pos.x * pos.x - 28 * pos.x + 22) *
	   tmp->z + 16 * tmp->x * pos.y - 32 * tmp->x * tmp->y + 16 * pos.x *
	   tmp->x - 16 * tmp->x) * ray->dir.z +
	  ((6 * tmp->y - 2) * pos.z * pos.z +
	   (12 * pos.y * tmp->y - 12 * pos.y + (12 * pos.x - 36) * tmp->y - 4 *
	    pos.x - 12) * pos.z + (32 * tmp->x * tmp->y - 32 * tmp->x) * tmp->z
	   + 6 * pos.y * pos.y * tmp->y - 10 * pos.y * pos.y +
	   (12 * pos.x - 28) * pos.y * tmp->y + (36 - 12 * pos.x) * pos.y +
	   (6 * pos.x * pos.x - 20 * pos.x + 14) * tmp->y - 2 * pos.x * pos.x +
	   4 * pos.x - 2) * ray->dir.y +
	  (6 * tmp->x * pos.z * pos.z + 16 * pos.z * tmp->z +
	   (12 * tmp->x * pos.y - 8 * tmp->x * tmp->y + 12 * pos.x * tmp->x -
	    28 * tmp->x) * pos.z + (16 * pos.y - 32 * tmp->y + 48 * pos.x - 16)
	   * tmp->z + 6 * tmp->x * pos.y * pos.y - 8 * tmp->x * pos.y * tmp->y
	   + (12 * pos.x * tmp->x - 20 * tmp->x) * pos.y +
	   (8 * tmp->x - 8 * pos.x * tmp->x) * tmp->y + 6 * pos.x * pos.x *
	   tmp->x - 12 * pos.x * tmp->x + 6 * tmp->x) * ray->dir.x);
}
