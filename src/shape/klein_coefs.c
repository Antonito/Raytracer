/*
** klein_coefs.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Fri May 13 02:51:12 2016 Antoine Baché
*/

#include "engine/intersect.h"

double	calc_e_klein(t_ray *ray, t_vec3 *tmp, t_vec3 dir, t_vec3 pos)
{
  return ((15 * pos.z * pos.z + (18 * pos.y - 12 * tmp->y + 18 * pos.x - 66) *
	   pos.z + 48 * tmp->x * tmp->z + 3 * pos.y * pos.y - 4 * pos.y *
	   tmp->y + (6 * pos.x - 18) * pos.y + (-4 * pos.x - 12) * tmp->y + 3 *
	   pos.x * pos.x - 14 * pos.x + 11) * dir.z +
	  (((24 * tmp->y - 8) *pos.z * tmp->z +
	    (24 * pos.y * tmp->y - 24 * pos.y + (24 * pos.x - 72) * tmp->y - 8
	     * pos.x - 24) * tmp->z + 32 * tmp->x * tmp->y - 32 * tmp->x) *
	   ray->dir.y + (24 * tmp->x * pos.z * tmp->z + 48 * pos.z +
			 (24 * tmp->x * pos.y - 16 * tmp->x * tmp->y + 24 *
			  pos.x * tmp->x - 56 * tmp->x) * tmp->z + 16 * pos.y
			 - 32 * tmp->y + 48 * pos.x - 16) * ray->dir.x) *
	  ray->dir.z +
	  (3 * pos.z * pos.z + (18 * pos.y - 12 * tmp->y + 6 * pos.x - 18) *
	   pos.z + 16 * tmp->x * tmp->z + 15 * pos.y * pos.y - 20 * pos.y *
	   tmp->y + (18 * pos.x - 42) * pos.y + (36 - 12 * pos.x) * tmp->y + 3
	   * pos.x * pos.x - 10 * pos.x + 7) * dir.y +
	  ((24 * tmp->x * tmp->y - 8 * tmp->x) * pos.z + (32 * tmp->y - 32) *
	   tmp->z + 24 * tmp->x * pos.y * tmp->y - 24 * tmp->x * pos.y +
	   (24 * pos.x * tmp->x - 40 * tmp->x) * tmp->y - 8 * pos.x * tmp->x +
	   8 * tmp->x) * ray->dir.x * ray->dir.y +
	  (3 * pos.z * pos.z + (6 * pos.y - 4 * tmp->y + 18 * pos.x - 14) *
	   pos.z + 48 * tmp->x * tmp->z + 3 * pos.y * pos.y - 4 * pos.y *
	   tmp->y + (18 * pos.x - 10) * pos.y + (4 - 12 * pos.x) * tmp->y + 15
	   * pos.x * pos.x - 18 * pos.x + 3) * dir.x);
}

double	calc_d_klein(t_ray *ray, t_vec3 *tmp, t_vec3 dir, t_vec3 pos)
{
  return ((20 * pos.z * tmp->z + (12 * pos.y - 8 * tmp->y + 12 * pos.x - 44) *
	   tmp->z + 16 * tmp->x) * dir.z * ray->dir.z +
	  (((36 * tmp->y - 12) *pos.z + 12 * pos.y * tmp->y - 12 * pos.y +
	    (12 * pos.x - 36) * tmp->y - 4 * pos.x - 12) * ray->dir.y +
	   (36 * tmp->x * pos.z + 48 * tmp->z + 12 * tmp->x * pos.y - 8 *
	    tmp->x * tmp->y + 12 * pos.x * tmp->x - 28 * tmp->x) * ray->dir.x)
	  * dir.z +
	  ((12 * pos.z * tmp->z + (36 * pos.y - 24 * tmp->y + 12 * pos.x - 36)
	    * tmp->z + 16 * tmp->x) * dir.y +
	   ((48 * tmp->x * tmp->y - 16 * tmp->x) * tmp->z + 32 * tmp->y - 32)
	   * ray->dir.x * ray->dir.y +
	   (12 * pos.z * tmp->z + (12 * pos.y - 8 * tmp->y + 36 * pos.x - 28)
	    * tmp->z + 48 * tmp->x) * dir.x) * ray->dir.z +
	  ((12 * tmp->y - 4)* pos.z + 20 * pos.y * tmp->y - 20 * pos.y +
	   (12 * pos.x - 28) * tmp->y - 4 * pos.x + 12) * dir.y * ray->dir.y +
	  (12 * tmp->x * pos.z + 16 * tmp->z + 36 * tmp->x * pos.y - 24 *
	   tmp->x * tmp->y + 12 * pos.x * tmp->x - 20 * tmp->x) * ray->dir.x *
	  dir.y + ((12 * tmp->y - 4) * pos.z + 12 * pos.y * tmp->y - 12 *
		   pos.y + (36 * pos.x - 20) * tmp->y - 12 * pos.x + 4) *
	  dir.x * ray->dir.y + (12 * tmp->x * pos.z + 16 * tmp->z + 12 *
				tmp->x * pos.y - 8 * tmp->x * tmp->y + 20 *
				pos.x * tmp->x - 12 * tmp->x) * dir.x *
	  ray->dir.x);
}
