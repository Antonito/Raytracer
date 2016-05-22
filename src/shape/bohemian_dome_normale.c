/*
** bohemian_dome_normale.c for  in gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 14:51:17 2016 Arthur ARNAUD
** Last update Sun May 22 20:21:58 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_dome(t_intersect *inter, t_vec3 tmp)
{
  return (-4 * inter->pos.x * (tmp.x - tmp.z + tmp.y));
}

double	calc_y_derivative_dome(t_intersect *inter, t_vec3 tmp)
{
  return (-4 * inter->pos.y * (tmp.y + tmp.z + tmp.x - 2));
}
double	calc_z_derivative_dome(t_intersect *inter, t_vec3 tmp)
{
  return (-4 * inter->pos.z * (tmp.z + tmp.y - tmp.x));
}

void	calc_normale_bohemian_dome(t_intersect *inter)
{
  calc_normale(calc_x_derivative_dome, calc_y_derivative_dome,
	       calc_z_derivative_dome,
	       inter);
}
