/*
** klein_normale.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 06:43:20 2016 Antoine Baché
** Last update Sat May 21 14:48:28 2016 Antoine Baché
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (6 * inter->pos.x * tmp.z * tmp.z + 16 * tmp.z * inter->pos.z +
	  ((-28 * inter->pos.x) + 12 * tmp.x *
	   inter->pos.x - 8 * inter->pos.x * inter->pos.y + 12 * inter->pos.x *
	   tmp.y) * tmp.z +
	  ((-16) + 48 * tmp.x - 32 * inter->pos.y + 16 *
	   tmp.y) * inter->pos.z + 6 * inter->pos.x *
	  tmp.y * tmp.y - 8 *
	  inter->pos.x * tmp.y * inter->pos.y +
	  (12 * tmp.x * inter->pos.x - 20 * inter->pos.x)
	  * tmp.y + (8 * inter->pos.x - 8 * inter->pos.x * tmp.x) *
	  inter->pos.y + 6 * inter->pos.x * tmp.x * tmp.x - 12 * tmp.x *
	  inter->pos.x + 6 * inter->pos.x);
}

double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ((6 * inter->pos.y - 2) * tmp.z * tmp.z +
	  ((-12) - 4 * tmp.x + (12 * tmp.x - 36) * inter->pos.y - 12 *
	   tmp.y + 12 * tmp.y * inter->pos.y) *
	  tmp.z + (32 * inter->pos.x * inter->pos.y - 32 *
		   inter->pos.x) * inter->pos.z + 6 * tmp.y * tmp.y *
	  inter->pos.y - 10 * tmp.y * tmp.y  +
	  (12 * tmp.x - 28) * inter->pos.y * tmp.y +
	  (36 - 12 * tmp.x) * tmp.y  +
	  (14 - 20 * tmp.x + 6 * tmp.x * tmp.x) *
	  inter->pos.y - 2 * tmp.x  * tmp.x + 4 * tmp.x - 2);
}

double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (6 * tmp.z * tmp.z * inter->pos.z +
	  ((-44) + 12 * tmp.x - 8 * inter->pos.y + 12 * tmp.y) *
	  tmp.z * inter->pos.z + 48 * inter->pos.x * tmp.z +
	  (22 - 28 * tmp.x + 6 * tmp.x * tmp.x + ((-8 * tmp.x) - 24) *
	   inter->pos.y + (12 * tmp.x - 36) * inter->pos.y *
	   inter->pos.y - 8 * inter->pos.y * tmp.y + 6 *
	   tmp.y * tmp.y) * inter->pos.z + 16 * inter->pos.x * tmp.y - 32 *
	  inter->pos.x * inter->pos.y + 16 * tmp.x * inter->pos.x -
	  16 * inter->pos.x);
}

void			calc_normale_klein(t_intersect *inter)
{
  calc_normale(calc_x_derivative, calc_y_derivative, calc_z_derivative,
	       inter);
}
