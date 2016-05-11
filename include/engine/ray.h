/*
** ray.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:18:58 2016 Ludovic Petrenko
** Last update Tue May 10 16:04:22 2016 Ludovic Petrenko
*/

#ifndef RAY_H_
# define RAY_H_

# include "vector.h"

typedef struct	s_ray
{
  t_vec3	pos;
  t_vec3	dir;
  void		*env;
  void		*src;
  bool		_void;
}		t_ray;

#endif /* !RAY_H_ */
