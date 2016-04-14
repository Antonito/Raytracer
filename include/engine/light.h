/*
** light.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:57:52 2016 Ludovic Petrenko
** Last update Fri Apr 15 01:01:07 2016 Ludovic Petrenko
*/

#ifndef LIGHT_H_
# define LIGHT_H_

# include "vector.h"

typedef enum	e_light_type
  {
    POINT,
    DIRECTIONNAL,
    SPOT
  }		t_light_type;

typedef struct	s_light
{
  t_light_type	type;
  t_vec3	pos;
  t_vec3	dir;
  unsigned int	color;
  double	power;
}		t_light;

#endif /* !LIGHT_H_ */
