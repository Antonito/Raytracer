/*
** vector_add.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:53:31 2016 Ludovic Petrenko
** Last update Thu Apr 21 21:03:16 2016 Ludovic Petrenko
*/

#include "engine/vector.h"

t_vec3		add_vec3(t_vec3 a, t_vec3 b)
{
  t_vec3	res;

  res.x = a.x + b.x;
  res.y = a.y + b.y;
  res.z = a.z + b.z;
  return (res);
}

t_vec3	        sub_vec3(t_vec3 a, t_vec3 b)
{
  t_vec3	res;

  res.x = a.x - b.x;
  res.y = a.y - b.y;
  res.z = a.z - b.z;
  return (res);
}

t_vec3	        mult_vec3(t_vec3 a, double m)
{
  t_vec3	res;

  res.x = a.x * m;
  res.y = a.y * m;
  res.z = a.z * m;
  return (res);
}

t_vec3	        div_vec3(t_vec3 a, double m)
{
  t_vec3	res;

  res.x = a.x / m;
  res.y = a.y / m;
  res.z = a.z / m;
  return (res);
}

t_vec3	        cross_vec3(t_vec3 a, t_vec3 b)
{
  t_vec3	res;

  res.x = a.y * b.z - a.z * b.y;
  res.y = a.z * b.x - a.x * b.z;
  res.z = a.x * b.y - a.y * b.x;
  return (res);
}
