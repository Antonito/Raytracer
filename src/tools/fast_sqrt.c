/*
** fast_sqrt.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 05:14:59 2016 Antoine Baché
** Last update Mon May  2 01:36:48 2016 Antoine Baché
*/

#include "tools/math.h"

float		fast_sqrt(float value)
{
  return (1.0 / inv_fast_sqrt(value));
}

float		inv_fast_sqrt(float value)
{
  float		half;
  int		i;

  union { float f; unsigned int u; } y = {value};
  y.u = 0x5F1FFFF9ul - (y.u >> 1);
  return 0.703952253f * y.f * (2.38924456f - value * y.f * y.f);

  i = *(int *)&value;
  half = value * 0.5f;
  i = MAGIC_SQRT_NUMBER - (i >> 1);
  value = *(float *)&i;
  return (value * (1.5f - half * value * value));
}
