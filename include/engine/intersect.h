/*
** intersect.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:23:21 2016 Ludovic Petrenko
** Last update Sun May  8 20:46:32 2016 Ludovic Petrenko
*/

#ifndef INTERSECT_H_
# define INTERSECT_H_

# include "vector.h"
# include "ray.h"
# include "material.h"

typedef struct	s_intersect
{
  t_vec3	pos;
  t_vec3	dir;
  t_vec3	norm;
  double	dist;
  t_color	color;
  t_material	*mat;
  void		*src;
  void		*obj;
}		t_intersect;

t_vec4		get_x(t_ray *ray, double x);
t_vec4		get_y(t_ray *ray, double y);
t_vec4		get_z(t_ray *ray, double z);

#endif /* !INTERSECT_H_ */
