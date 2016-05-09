/*
** klein_coefs.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 03:28:07 2016 Antoine Baché
** Last update Mon May  9 05:00:22 2016 Antoine Baché
*/

#include "engine/intersect.h"

static double			calc_e_part_2_klein(t_ray *ray)
{
  return (((24 * ray->pos.x * ray->pos.y - 8
	    * ray->pos.x) * ray->pos.z *
	   ray->pos.z +
	   (32 * ray->pos.y - 32) *
	   ray->pos.z + 24 * ray->pos.x * ray->pos.y * ray->pos.y *
	   ray->pos.y - 24 * ray->pos.x * ray->pos.y * ray->pos.y +
	   (24 * ray->pos.x * ray->pos.x *
	    ray->pos.x - 40 * ray->pos.x) * ray->pos.y - 8 * ray->pos.x *
	   ray->pos.x * ray->pos.x + 8 *
	   ray->pos.x) * ray->dir.x * ray->dir.y +
	  (3 * ray->pos.z *
	   ray->pos.z * ray->pos.z * ray->pos.z +
	   (6 * ray->pos.y * ray->pos.y - 4 * ray->pos.y + 18 *
	    ray->pos.x * ray->pos.x - 14) * ray->pos.z *
	   ray->pos.z + 48 * ray->pos.x * ray->pos.z + 3 *
	   ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y - 4 *
	   ray->pos.y * ray->pos.y * ray->pos.y +
	   (18 * ray->pos.x * ray->pos.x - 10) * ray->pos.y *
	   ray->pos.y + (4 - 12 * ray->pos.x * ray->pos.x) *
	   ray->pos.y + 15 * ray->pos.x * ray->pos.x * ray->pos.x
	   * ray->pos.x - 18 * ray->pos.x * ray->pos.x + 3) *
	  ray->dir.x * ray->dir.x);
}

static double			calc_e_part_klein(t_ray *ray)
{
  return ((((24 * ray->pos.y - 8) * ray->pos.z * ray->pos.z *
	    ray->pos.z + (24 * ray->pos.y * ray->pos.y * ray->pos.y - 24 *
			  ray->pos.y * ray->pos.y +
			  (24 * ray->pos.x * ray->pos.x -
			   72) * ray->pos.y - 8 *
			  ray->pos.x * ray->pos.x - 24) *
	    ray->pos.z + 32 * ray->pos.x *
	    ray->pos.y - 32 * ray->pos.x) *
	   ray->dir.y +
	   (24 * ray->pos.x * ray->pos.z * ray->pos.z *
	    ray->pos.z + 48 *
	    ray->pos.z *
	    ray->pos.z +
	    (24 * ray->pos.x *
	     ray->pos.y * ray->pos.y - 16 *
	     ray->pos.x * ray->pos.y + 24 *
	     ray->pos.x * ray->pos.x *
	     ray->pos.x - 56 * ray->pos.x) *
	    ray->pos.z + 16 * ray->pos.y *
	    ray->pos.y - 32 * ray->pos.y +
	    48 * ray->pos.x * ray->pos.x -
	    16) * ray->dir.x) * ray->dir.z);
}

double				calc_e_klein(t_ray *ray)
{
  return ((15 * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z +
	   (18 * ray->pos.y * ray->pos.y - 12 * ray->pos.y + 18 * ray->pos.x *
	    ray->pos.x - 66) * ray->pos.z * ray->pos.z + 48 * ray->pos.x *
	   ray->pos.z + 3 * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y -
	   4 * ray->pos.y * ray->pos.y * ray->pos.y +
	   (6 * ray->pos.x * ray->pos.x - 18) * ray->pos.y * ray->pos.y +
	   (-4 * ray->pos.x * ray->pos.x - 12) * ray->pos.y + 3 * ray->pos.x *
	   ray->pos.x * ray->pos.x * ray->pos.x - 14 * ray->pos.x * ray->pos.x
	   + 11) * ray->dir.z * ray->dir.z + calc_e_part_klein(ray) +
	  (3 * ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z +
	   (18 * ray->pos.y * ray->pos.y - 12 * ray->pos.y + 6 * ray->pos.x *
	    ray->pos.x - 18) * ray->pos.z * ray->pos.z + 16 * ray->pos.x *
	   ray->pos.z + 15 * ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y
	   - 20 * ray->pos.y * ray->pos.y * ray->pos.y +
	   (18 * ray->pos.x * ray->pos.x - 42) * ray->pos.y * ray->pos.y +
	   (36 - 12 * ray->pos.x * ray->pos.x) * ray->pos.y + 3 * ray->pos.x *
	   ray->pos.x * ray->pos.x * ray->pos.x - 10 * ray->pos.x * ray->pos.x
	   + 7) * ray->dir.y * ray->dir.y + calc_e_part_2_klein(ray));
}

inline static double		calc_d_part_klein(t_ray *ray)
{
  return (((12 * ray->pos.y - 4) * ray->pos.z * ray->pos.z + 20 * ray->pos.y *
	   ray->pos.y * ray->pos.y - 20 * ray->pos.y * ray->pos.y +
	   (12 * ray->pos.x * ray->pos.x - 28) * ray->pos.y - 4 * ray->pos.x *
	   ray->pos.x + 12) * ray->dir.y * ray->dir.y * ray->dir.y +
	  (12 * ray->pos.x * ray->pos.z * ray->pos.z + 16 * ray->pos.z + 36 *
	   ray->pos.x * ray->pos.y * ray->pos.y - 24 * ray->pos.x * ray->pos.y
	   + 12 * ray->pos.x * ray->pos.x * ray->pos.x - 20 * ray->pos.x) *
	  ray->dir.x * ray->dir.y * ray->dir.y + ((12 * ray->pos.y - 4) *
						  ray->pos.z * ray->pos.z + 12
						  * ray->pos.y * ray->pos.y *
						  ray->pos.y - 12 * ray->pos.y
						  * ray->pos.y +
						  (36 * ray->pos.x * ray->pos.x
						   - 20) * ray->pos.y - 12 *
						  ray->pos.x * ray->pos.x + 4)
	  * ray->dir.x * ray->dir.x * ray->dir.y +
	  (12 * ray->pos.x * ray->pos.z * ray->pos.z + 16 * ray->pos.z + 12 *
	   ray->pos.x * ray->pos.y * ray->pos.y - 8 * ray->pos.x * ray->pos.y +
	   20 * ray->pos.x * ray->pos.x * ray->pos.x - 12 * ray->pos.x) *
	  ray->dir.x * ray->dir.x * ray->dir.x);
}

double				calc_d_klein(t_ray *ray)
{
  return ((20 * ray->pos.z * ray->pos.z * ray->pos.z +
	   (12 * ray->pos.y * ray->pos.y - 8 * ray->pos.y + 12 * ray->pos.x *
	    ray->pos.x - 44) * ray->pos.z + 16 * ray->pos.x) * ray->dir.z *
	  ray->dir.z * ray->dir.z + (((36 * ray->pos.y - 12) * ray->pos.z *
				      ray->pos.z + 12 * ray->pos.y * ray->pos.y
				      * ray->pos.y - 12 * ray->pos.y *
				      ray->pos.y +
				      (12 * ray->pos.x * ray->pos.x - 36) *
				      ray->pos.y - 4 * ray->pos.x * ray->pos.x
				      - 12) * ray->dir.y +
				     (36 * ray->pos.x * ray->pos.z * ray->pos.z
				      + 48 * ray->pos.z + 12 * ray->pos.x *
				      ray->pos.y * ray->pos.y - 8 * ray->pos.x
				      * ray->pos.y + 12 * ray->pos.x *
				      ray->pos.x * ray->pos.x - 28 * ray->pos.x)
				     * ray->dir.x) * ray->dir.z * ray->dir.z +
	  calc_d_part_klein(ray));
}
