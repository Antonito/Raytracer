/*
** chubs_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:07:41 2016 Arthur ARNAUD
** Last update Sun May 22 15:09:29 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.x * tmp.x - 2 * inter->pos.x);
}

double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.y * tmp.y - 2 * inter->pos.y);
}
double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.z * tmp.z - 2 * inter->pos.z);
}

void	calc_normale_chubs(t_intersect *inter)
{
  calc_normale(calc_x_derivative, calc_y_derivative, calc_z_derivative,
	       inter);
}
