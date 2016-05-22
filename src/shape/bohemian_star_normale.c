/*
** bohemian_star_normale.c for  in gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 14:56:19 2016 Arthur ARNAUD
** Last update Sun May 22 20:22:34 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_star(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.x *
	  (tmp.y * tmp.y * tmp.x +
	   (tmp.y * tmp.y - 8 * tmp.y + 8)
	   * tmp.z + tmp.y * tmp.y * tmp.y - 2 * tmp.y * tmp.y));
}

double	calc_y_derivative_star(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.y *
	  (2 * tmp.y * tmp.y * tmp.y +
	   (3 * tmp.z + 3 * tmp.x) * tmp.y * tmp.y +
	   (tmp.z * tmp.z + (2 * tmp.x - 4) *
	    tmp.z + tmp.x * tmp.x - 4 * tmp.x) * tmp.y - 8 * tmp.x * tmp.z));
}
double	calc_z_derivative_star(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.z *
	  (tmp.y * tmp.y * tmp.z + tmp.y *
	   tmp.y * tmp.y + (tmp.x - 2) *
	   tmp.y * tmp.y - 8 * tmp.x * tmp.y + 8 * tmp.x));
}

void	calc_normale_bohemian_star(t_intersect *inter)
{
  calc_normale(calc_x_derivative_star, calc_y_derivative_star,
	       calc_z_derivative_star,
	       inter);
}
