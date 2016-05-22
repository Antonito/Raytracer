/*
** bohemian_dome_normale.c for  in gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 14:51:17 2016 Arthur ARNAUD
** Last update Sun May 22 14:52:50 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ();
}

double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ();
}
double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ();
}

void			calc_normale_bohemian_dome(t_intersect *inter)
{
  calc_normale(calc_x_derivative, calc_y_derivative, calc_z_derivative,
	       inter);
}
