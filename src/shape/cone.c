/*
** cone.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 03:24:31 2016 Antoine Baché
** Last update Wed May  4 19:36:32 2016 Ludovic Petrenko
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cone(t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;

  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y -
    ray->dir.z * ray->dir.z;
  b = 2.0 * ray->pos.x * ray->dir.x + 2.0 * ray->pos.y * ray->dir.y -
    2.0 * ray->pos.z * ray->dir.z;
  c = ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y -
    ray->pos.z * ray->pos.z;
  inter->dist = (-1.0 * b + sqrt((b * b - 4.0 * a * c))) / (2.0 * a);
  inter->pos = add_vec3(mult_vec3(ray->dir, inter->dist), ray->pos);
}

t_intersect	get_intersect_cone(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_cone(ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  return (inter);
}
