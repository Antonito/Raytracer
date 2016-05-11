/*
** klein_normale.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 06:43:20 2016 Antoine Baché
** Last update Tue May 10 15:36:29 2016 Antoine Baché
*/

#include "engine/intersect.h"

inline static double	calc_x_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (6 * inter->pos.x * tmp.z * tmp.z + 16 * tmp.z * inter->pos.z +
	  ((-28 * inter->pos.x) + 12 * tmp.x *
	   inter->pos.x - 8 * inter->pos.x * inter->pos.y + 12 * inter->pos.x *
	   tmp.y) * tmp.z +
	  ((-16) + 48 * tmp.x - 32 * inter->pos.y + 16 *
	   tmp.y) * inter->pos.z + 6 * inter->pos.x *
	  tmp.y * tmp.y - 8 *
	  inter->pos.x * tmp.y * inter->pos.y +
	  (12 * tmp.x * inter->pos.x - 20 * inter->pos.x)
	  * tmp.y + (8 * inter->pos.x - 8 * inter->pos.x * tmp.x) *
	  inter->pos.y + 6 * inter->pos.x * tmp.x * tmp.x - 12 * tmp.x *
	  inter->pos.x + 6 * inter->pos.x);
}

inline static double	calc_y_derivative(t_intersect *inter, t_vec3 tmp)
{
  return ((6 * inter->pos.y - 2) * tmp.z * tmp.z +
	  ((-12) - 4 * tmp.x + (12 * tmp.x - 36) * inter->pos.y - 12 *
	   tmp.y + 12 * tmp.y * inter->pos.y) *
	  tmp.z + (32 * inter->pos.x * inter->pos.y - 32 *
		   inter->pos.x) * inter->pos.z + 6 * tmp.y * tmp.y *
	  inter->pos.y - 10 * tmp.y * tmp.y  +
	  (12 * tmp.x - 28) * inter->pos.y * tmp.y +
	  (36 - 12 * tmp.x) * tmp.y  +
	  (14 - 20 * tmp.x + 6 * tmp.x * tmp.x) *
	  inter->pos.y - 2 * tmp.x  * tmp.x + 4 * tmp.x - 2);
}

inline static double	calc_z_derivative(t_intersect *inter, t_vec3 tmp)
{
  return (6 * tmp.z * tmp.z * inter->pos.z +
	  ((-44) + 12 * tmp.x - 8 * inter->pos.y + 12 * tmp.y) *
	  tmp.z * inter->pos.z + 48 * inter->pos.x * tmp.z +
	  (22 - 28 * tmp.x + 6 * tmp.x * tmp.x + ((-8 * tmp.x) - 24) *
	   inter->pos.y + (12 * tmp.x - 36) * inter->pos.y *
	   inter->pos.y - 8 * inter->pos.y * tmp.y + 6 *
	   tmp.y * tmp.y) * inter->pos.z + 16 * inter->pos.x * tmp.y - 32 *
	  inter->pos.x * inter->pos.y + 16 * tmp.x * inter->pos.x -
	  16 * inter->pos.x);
}

inline static void	calc_new_pts_klein(t_vec3 *d, t_vec3 *ori)
{
  t_vec3		tmp;
  t_intersect		inter;

  inter.pos.x = ori->x + 0.001;
  inter.pos.y = ori->y + 0.001;
  inter.pos.z = (-1.0 * (d[0].x * (inter.pos.x - ori->x))
		  - (d[0].y * (inter.pos.y - ori->y))
		  + (ori->z * d[0].z)) / d[0].z;
  tmp.x = inter.pos.x * inter.pos.x;
  tmp.y = inter.pos.y * inter.pos.y;
  tmp.z = inter.pos.z * inter.pos.z;
  d[1].x = calc_x_derivative(&inter, tmp);
  d[1].y = calc_y_derivative(&inter, tmp);
  d[1].z = calc_z_derivative(&inter, tmp);
  inter.pos.x = ori->x + 0.002;
  inter.pos.y = ori->y + 0.002;
  inter.pos.z = (-1.0 * (d[0].x * (inter.pos.x - ori->x))
		  - (d[0].y * (inter.pos.y - ori->y))
		  + (ori->z * d[0].z)) / d[0].z;
  tmp.x = inter.pos.x * inter.pos.x;
  tmp.y = inter.pos.y * inter.pos.y;
  tmp.z = inter.pos.z * inter.pos.z;
  d[2].x = calc_x_derivative(&inter, tmp);
  d[2].y = calc_y_derivative(&inter, tmp);
  d[2].z = calc_z_derivative(&inter, tmp);
}

void			calc_normale_klein(t_intersect *inter)
{
  t_vec3		d[3];
  t_vec3		v[2];
  t_vec3		tmp;

  tmp.x = inter->pos.x * inter->pos.x;
  tmp.y = inter->pos.y * inter->pos.y;
  tmp.z = inter->pos.z * inter->pos.z;
  d[0].x = calc_x_derivative(inter, tmp);
  d[0].y = calc_y_derivative(inter, tmp);
  d[0].z = calc_z_derivative(inter, tmp);
  calc_new_pts_klein(d, &inter->pos);
  v[0] = sub_vec3(d[1], d[0]);
  v[1] = sub_vec3(d[2], d[0]);
  inter->norm = vec3_normalize(cross_vec3(v[0], v[1]));
}
