/*
** c8_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:01:04 2016 Arthur ARNAUD
** Last update Sun May 22 20:22:58 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_c8(t_intersect *inter, t_vec3 tmp)
{
  return (512 * tmp.x * tmp.x * tmp.x *
	  inter->pos.x - 768 * inter->pos.x *
	  tmp.x * tmp.x + 320 * inter->pos.x *
	  tmp.x - 32 * inter->pos.x);
}

double	calc_y_derivative_c8(t_intersect *inter, t_vec3 tmp)
{
  return (512 * tmp.y * tmp.y * tmp.y *
	  inter->pos.y - 768 * inter->pos.y *
	  tmp.y * tmp.y + 320 * inter->pos.y *
	  tmp.y - 32 * inter->pos.y);
}
double	calc_z_derivative_c8(t_intersect *inter, t_vec3 tmp)
{
  return (512 * tmp.z * tmp.z * tmp.z *
	  inter->pos.z - 768 * inter->pos.z *
	  tmp.z * tmp.z + 320 * inter->pos.z *
	  tmp.z - 32 * inter->pos.z);
}

void	calc_normale_c8(t_intersect *inter)
{
  calc_normale(calc_x_derivative_c8, calc_y_derivative_c8,
	       calc_z_derivative_c8,
	       inter);
}
