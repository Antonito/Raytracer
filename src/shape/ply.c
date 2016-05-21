/*
** ply.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 18:26:44 2016 Antoine Baché
** Last update Sat May 21 06:20:10 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "engine/bsp.h"
#include "tools/math.h"

t_intersect	get_intersect_ply(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  t_vec3	i;
  double	t;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if (!obj->ply.ply || !check_box(obj, ray))
    return (inter);
  inter.obj = obj;
  if (!obj->ply.ply)
    return (inter);
  inter.dir = ray->dir;
  inter.mat = obj->mat;
  node_intersect(obj->ply.node, ray, &inter);
  return (inter);
}
