/*
** cushion_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:14:03 2016 Arthur ARNAUD
** Last update Sun May 22 20:26:03 2016 Arthur ARNAUD
*/


#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_cushion(t_intersect *inter, t_vec3 tmp)
{
  return ((2 * tmp.z - 4 * tmp.y + 2) *
	  inter->pos.x - 4 * inter->pos.x * tmp.x);
}

double	calc_y_derivative_cushion(t_intersect *inter, t_vec3 tmp)
{
  return (-2 * inter->pos.y *
	  (2 * tmp.y + tmp.z - 2 *
	   inter->pos.z + 2 * tmp.x - 1));
}
double	calc_z_derivative_cushion(t_intersect *inter, t_vec3 tmp)
{
  return (-2 * (2 * inter->pos.z * tmp.z - 3 *
		tmp.z + (tmp.y - tmp.x + 2) *
		inter->pos.z - tmp.y));
}

void	calc_normale_cushion(t_intersect *inter)
{
  calc_normale(calc_x_derivative_cushion, calc_y_derivative_cushion,
	       calc_z_derivative_cushion,
	       inter);
}
