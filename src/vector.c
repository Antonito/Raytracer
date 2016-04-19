/*
** vector.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 01:41:06 2016 Ludovic Petrenko
** Last update Mon Apr 18 01:46:39 2016 Ludovic Petrenko
*/

#include "engine/vector.h"
#include "tools/types.h"

t_vec3		vec3(double x, double y, double z)
{
  return ((t_vec3){x, y, z});
}

t_vec4		vec4(double x, double y, double z, double w)
{
  return ((t_vec4){x, y, z, w});
}

t_ivec2		ivec2(int x, int y)
{
  return ((t_ivec2){x, y});
}

t_vec3		vec4_to_3(t_vec4 v)
{
  return ((t_vec3){v.x, v.y, v.z});
}

t_vec4		vec3_to_4(t_vec3 v, double w)
{
  return ((t_vec4){v.x, v.y, v.z, w});
}
