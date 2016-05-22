/*
** hunt_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:25:54 2016 Arthur ARNAUD
** Last update Sun May 22 21:20:29 2016 Antoine Baché
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_hunt(t_intersect *inter, t_vec3 tmp)
{
  return (24 * inter->pos.x * tmp.x *
	  tmp.x + (48 * tmp.z + 48 * tmp.y + 348) *
	  inter->pos.x * tmp.x +
	  (24 * tmp.z * tmp.z +
	   (48 * tmp.y - 1920) *
	   tmp.z + 24 * tmp.y * tmp.y - 300 * tmp.y + 168) *
	  inter->pos.x);
}

double	calc_y_derivative_hunt(t_intersect *inter, t_vec3 tmp)
{
  return (24 * inter->pos.y * tmp.y *
	  tmp.y + (48 * tmp.z + 48 * tmp.x - 516) *
	  inter->pos.y * tmp.y +
	  (24 * tmp.z * tmp.z +
	   (48 * tmp.x - 1056) * tmp.z + 24 *
	   tmp.x * tmp.x - 300 * tmp.x + 2760) * inter->pos.y);
}

double	calc_z_derivative_hunt(t_intersect *inter, t_vec3 tmp)
{
  return (24 * inter->pos.z *
	  (tmp.z * tmp.z +
	   (2 * tmp.y + 2 * tmp.x + 46) *
	   tmp.z + tmp.y * tmp.y + (2 * tmp.x - 44) *
	   tmp.y + tmp.x * tmp.x - 80 * tmp.x + 385));
}

void	calc_normale_hunt(t_intersect *inter)
{
  calc_normale(calc_x_derivative_hunt, calc_y_derivative_hunt,
	       calc_z_derivative_hunt,
	       inter);
}
