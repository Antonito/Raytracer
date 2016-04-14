/*
** ray.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:18:58 2016 Ludovic Petrenko
** Last update Fri Apr 15 01:23:09 2016 Ludovic Petrenko
*/

#ifndef RAY_H_
# define RAY_H_

# include "vector.h"

typedef struct	s_ray
{
  t_vec4	pos;
  t_vec4	dir;
}		t_ray;

#endif /* !RAY_H_ */
