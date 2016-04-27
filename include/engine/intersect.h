/*
** intersect.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:23:21 2016 Ludovic Petrenko
** Last update Wed Apr 27 05:33:15 2016 Ludovic Petrenko
*/

#ifndef INTERSECT_H_
# define INTERSECT_H_

# include "vector.h"
# include "ray.h"

typedef struct	s_intersect
{
  t_vec3	pos;
  t_vec3	dir;
  t_vec3	norm;
  double	dist;
  unsigned int	color;
}		t_intersect;

#endif /* !INTERSECT_H_ */
