/*
** vector_tools.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 02:28:25 2016 Antoine Baché
** Last update Fri May 13 02:30:24 2016 Antoine Baché
*/

#include "engine/vector.h"

inline t_vec3	square_vec3(t_vec3 a)
{
  t_vec3	res;

  res.x = a.x * a.x;
  res.y = a.y * a.y;
  res.z = a.z * a.z;
  return (res);
}
