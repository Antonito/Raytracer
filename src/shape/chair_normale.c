/*
** chair_normale.c for  in /home/arnaud_e/rendu/info/gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 15:05:45 2016 Arthur ARNAUD
** Last update Sun May 22 20:24:20 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_chair(t_intersect *inter, t_vec3 tmp)
{
  return (40 * inter->pos.x * tmp.x +
	  (72 * tmp.z + 32 * inter->pos.z - 24 * tmp.y - 150)
	  * inter->pos.x);
}

double	calc_y_derivative_chair(t_intersect *inter, t_vec3 tmp)
{
  return (4 * inter->pos.y * tmp.y +
	  (72 * tmp.z - 32 * inter->pos.z - 24 * tmp.x - 150)
	  * inter->pos.y);
}
double	calc_z_derivative_chair(t_intersect *inter, t_vec3 tmp)
{
  return (8 * inter->pos.z * tmp.z +
	  (72 * tmp.y + 72 * tmp.x - 150)
	  * inter->pos.z - 16 * tmp.y + 16 * tmp.x);
}

void	calc_normale_chair(t_intersect *inter)
{
  calc_normale(calc_x_derivative_chair, calc_y_derivative_chair,
	       calc_z_derivative_chair,
	       inter);
}
