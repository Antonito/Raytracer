/*
** devil_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:17:03 2016 Arthur ARNAUD
** Last update Sun May 22 20:26:41 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_devil(t_intersect *inter, t_vec3 tmp)
{
  return ((100 * inter->pos.x *
	   tmp.x + (100 * tmp.z - 18) *
	   inter->pos.x) / 25);
}

double	calc_y_derivative_devil(t_intersect *inter, t_vec3 tmp)
{
  return (inter->pos.y / 2 - 4 * inter->pos.y * tmp.y);
}
double	calc_z_derivative_devil(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.z * (tmp.z + tmp.x));
}

void	calc_normale_devil(t_intersect *inter)
{
  calc_normale(calc_x_derivative_devil, calc_y_derivative_devil,
	       calc_z_derivative_devil,
	       inter);
}
