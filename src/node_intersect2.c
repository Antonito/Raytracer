/*
** node_intersect2.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 30 22:16:15 2016 Ludovic Petrenko
** Last update Mon May  2 05:45:35 2016 Ludovic Petrenko
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "engine/intersect.h"
#include "engine/ray.h"

int	get_next_node(double *dist, double last)
{
  int	i;
  int	next;

  i = -1;
  next = -1;
  while (++i < 8)
    if (dist[i] > last)
      next = i;
  return (next);
}

t_vec4		get_x(t_ray ray, double x)
{
  t_vec4	t;

  if (ray.dir.x == 0.0)
    {
      t.w = INFINITY;
      return (t);
    }
  t.w = (x - ray.pos.x) / ray.dir.x;
  t.x = x;
  t.y = ray.dir.y * t.w + ray.pos.y;
  t.z = ray.dir.z * t.w + ray.pos.z;
  return (t);
}

t_vec4		get_y(t_ray ray, double y)
{
  t_vec4	t;

  if (ray.dir.y == 0.0)
    {
      t.w = INFINITY;
      return (t);
    }
  t.w = (y - ray.pos.y) / ray.dir.y;
  t.x = ray.dir.x * t.w + ray.pos.x;
  t.y = y;
  t.z = ray.dir.z * t.w + ray.pos.z;
  return (t);
}

t_vec4		get_z(t_ray ray, double z)
{
  t_vec4	t;

  if (ray.dir.z == 0.0)
    {
      t.w = INFINITY;
      return (t);
    }
  t.w = (z - ray.pos.z) / ray.dir.z;
  t.x = ray.dir.x * t.w + ray.pos.x;
  t.y = ray.dir.y * t.w + ray.pos.y;
  t.z = z;
  return (t);
}
