/*
** fast_sqrt.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 05:14:59 2016 Antoine Baché
** Last update Wed Apr 27 05:47:15 2016 Antoine Baché
*/

#include "tools/math.h"

float		fast_sqrt(float value)
{
  t_sqrt	tmp;

  tmp.val = value;
  tmp.tmp -= 1 << 23;
  tmp.tmp >>= 1;
  tmp.tmp += 1 << 29;
  return (tmp.val);
}

float		inv_fast_sqrt(float value)
{
  float		half;
  int		i;

  i = *(int *)&value;
  half = value * 0.5f;
  i = MAGIC_SQRT_NUMBER - (i >> 1);
  value = *(float *)&i;
  return (value * (1.5f - half * value * value));
}
