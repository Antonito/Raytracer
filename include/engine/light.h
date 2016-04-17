/*
** light.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:57:52 2016 Ludovic Petrenko
** Last update Sun Apr 17 16:03:21 2016 Ludovic Petrenko
*/

#ifndef LIGHT_H_
# define LIGHT_H_

# include "vector.h"

typedef struct	s_light
{
  t_light_type	type;
  t_vec3	pos;
  t_vec3	dir;
  unsigned int	color;
  double	radius;
  double	power;
}		t_light;

#endif /* !LIGHT_H_ */
