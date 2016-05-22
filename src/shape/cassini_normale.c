/*
** cassini_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:03:36 2016 Arthur ARNAUD
** Last update Sun May 22 15:30:07 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.x * tmp.x + (4 * tmp.y - 1) * inter->pos.x);
}

double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.y * tmp.y + 4 * tmp.x * inter->pos.y + inter->pos.y);
}
double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (-4 * inter->pos.z * tmp.z);
}

void	calc_normale_cassini(t_intersect *inter)
{
  calc_normale(calc_x_derivative, calc_y_derivative, calc_z_derivative,
	       inter);
}
