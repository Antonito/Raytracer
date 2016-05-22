/*
** no_shape.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 20:19:41 2016 Antoine Baché
** Last update Sun May 22 21:29:27 2016 Antoine Baché
*/

#include "engine/object.h"
#include "engine/intersect.h"

t_intersect	no_shape(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  (void)obj;
  (void)ray;
  inter.dist = -1.0;
  inter.norm = vec3(0, 0, 0);
  return (inter);
}
