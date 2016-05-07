/*
** ray.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:18:58 2016 Ludovic Petrenko
** Last update Sat May  7 05:48:38 2016 Ludovic Petrenko
*/

#ifndef RAY_H_
# define RAY_H_

# include "vector.h"

typedef struct	s_ray
{
  t_vec3	pos;
  t_vec3	dir;
  void		*src;
}		t_ray;

#endif /* !RAY_H_ */
