/*
** vector.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:30:38 2016 Ludovic Petrenko
** Last update Tue Apr 19 19:06:29 2016 Ludovic Petrenko
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include "tools/types.h"

typedef struct	s_vec3
{
  double	x;
  double	y;
  double	z;
}		t_vec3;

typedef struct	s_vec4
{
  double	x;
  double	y;
  double	z;
  double	w;
}		t_vec4;

typedef struct	s_ivec3
{
  int		x;
  int		y;
  int		z;
}		t_ivec3;

typedef struct	s_ivec4
{
  int		x;
  int		y;
  int		z;
  int		w;
}		t_ivec4;

t_vec3		vec3(double x, double y, double z);
t_vec4		vec4(double x, double y, double z, double w);
t_ivec2		vec2(int x, int y);
t_vec3		vec4_to_3(t_vec4 v);
t_vec4		vec3_to_4(t_vec3 v, double w);
t_vec3		vec3_normalize(t_vec3 v);

#endif /* !VECTOR_H_ */
