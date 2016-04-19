/*
** vector.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 01:41:06 2016 Ludovic Petrenko
** Last update Tue Apr 19 19:05:56 2016 Ludovic Petrenko
*/

#include "engine/vector.h"
#include "tools/types.h"

t_vec3		vec3(double x, double y, double z)
{
  t_vec3	new;

  new.x = x;
  new.y = y;
  new.z = z;
  return (new);
}

t_vec4		vec4(double x, double y, double z, double w)
{
  t_vec4	new;

  new.x = x;
  new.y = y;
  new.z = z;
  new.w = w;
  return (new);
}

t_ivec2		ivec2(int x, int y)
{
  t_ivec2	new;

  new.x = x;
  new.y = y;
  return (new);
}

t_vec3		vec4_to_3(t_vec4 v)
{
  t_vec3	new;

  new.x = v.x;
  new.y = v.y;
  new.z = v.z;
  return (new);
}

t_vec4		vec3_to_4(t_vec3 v, double w)
{
  t_vec4	new;

  new.x = v.x;
  new.y = v.y;
  new.z = v.z;
  new.w = w;
  return (new);
}
