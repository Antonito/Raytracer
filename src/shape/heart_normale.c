/*
** heart_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:21:42 2016 Arthur ARNAUD
** Last update Sun May 22 15:24:59 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ((240 * inter->pos.x * tmp.x * tmp.x +
	   (240 * tmp.z + 240 * tmp.y - 240) *
	   inter->pos.x * tmp.x +
	   (60 * tmp.z * tmp.z - inter->pos.z *
	    tmp.z + (120 * tmp.y - 120) *
	    tmp.z + 60 * tmp.y * tmp.y - 120 *
	    tmp.y + 60) * inter->pos.x) / 5);
}

double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (6 * inter->pos.y * tmp.y * tmp.y +
	  (12 * tmp.z + 24 * tmp.x - 12) *
	  inter->pos.y * tmp.y +
	  (6 * tmp.z * tmp.z - 2 * inter->pos.z *
	   tmp.z + (24 * tmp.x - 12) *
	   tmp.z + 24 * tmp.x * tmp.x - 24 *
	   tmp.x + 6) * inter->pos.y);
}
double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (3 * inter->pos.z *
	  (20 * tmp.z * tmp.z +
	   (40 * tmp.y + 80 * tmp.x - 40) *
	   tmp.z + (-10 * tmp.y - tmp.x) *
	   inter->pos.z + 20 * tmp.y *
	   tmp.y + (80 * tmp.x - 40) *
	   tmp.y + 80 * tmp.x * tmp.x - 80 * tmp.x + 20) / 10);
}

void	calc_normale_heart(t_intersect *inter)
{
  calc_normale(calc_x_derivative, calc_y_derivative, calc_z_derivative,
	       inter);
}
