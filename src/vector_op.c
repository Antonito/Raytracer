/*
** vector_op.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 18:58:07 2016 Ludovic Petrenko
** Last update Tue Apr 19 19:01:23 2016 Ludovic Petrenko
*/

#include <math.h>
#include "engine/vector.h"

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
