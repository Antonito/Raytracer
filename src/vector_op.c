/*
** vector_op.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 18:58:07 2016 Ludovic Petrenko
** Last update Mon May  9 04:50:37 2016 Ludovic Petrenko
*/

#include <math.h>
#include "engine/vector.h"
#include "tools/math.h"

t_vec3		vec3_normalize(t_vec3 v)
{
  double	coeff;

  coeff = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  if (coeff != 0.0)
    {
      v.x /= coeff;
      v.y /= coeff;
      v.z /= coeff;
    }
  return (v);
}

t_vec3		vec3_min(t_vec3 u, t_vec3 v)
{
  t_vec3	min;

  min.x = (u.x <= v.x) ? u.x : v.x;
  min.y = (u.y <= v.y) ? u.y : v.y;
  min.z = (u.z <= v.z) ? u.z : v.z;
  return (min);
}

t_vec3		vec3_max(t_vec3 u, t_vec3 v)
{
  t_vec3	max;

  max.x = (u.x >= v.x) ? u.x : v.x;
  max.y = (u.y >= v.y) ? u.y : v.y;
  max.z = (u.z >= v.z) ? u.z : v.z;
  return (max);
}

double	dot_vec3(t_vec3 u, t_vec3 v)
{
  return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	vec3_len(t_vec3 u)
{
  return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}
