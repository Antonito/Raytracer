/*
** cone.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 03:24:31 2016 Antoine Baché
** Last update Mon May  9 00:30:59 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cone(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  double	d;

  d = ray->dir.z * tan(obj->cone.angle);
  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z * d;
  b = 2.0 * (ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y - ray->pos.z *
	     d);
  c = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y - ray->dir.z * d;
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_cone(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_cone(ray, &inter, obj);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  return (inter);
}
