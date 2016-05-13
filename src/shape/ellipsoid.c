/*
** ellipsoid.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 03:24:31 2016 Antoine Baché
** Last update Fri May 13 01:54:06 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_ellipsoid(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  t_vec3	tmp;

  tmp = sub_vec3(ray->pos, obj->pos);
  a = ((ray->dir.x * ray->dir.x) / obj->ellipsoid.height) -
    ((ray->dir.y * ray->dir.y) / obj->ellipsoid.width) +
    ((ray->dir.z * ray->dir.z) / obj->ellipsoid.width);
  b = ((2.0 * ray->dir.x * tmp.x) / obj->ellipsoid.height) -
    ((2.0 * tmp.y * ray->dir.y) / obj->ellipsoid.width) +
    ((2.0 * tmp.z * ray->dir.z) / obj->ellipsoid.width);
  c = ((tmp.x * tmp.x) / obj->ellipsoid.height) -
    ((tmp.y * tmp.y) / obj->ellipsoid.width) +
    ((tmp.z * tmp.z) / obj->ellipsoid.width) - 1.0;
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_ellipsoid(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_ellipsoid(ray, &inter, obj);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  if (inter.pos.z < 0.0)
    inter.dist = -1.0;
  inter.norm.x = (2.0 / obj->ellipsoid.height) * inter.pos.x;
  inter.norm.y = (2.0 / obj->ellipsoid.width) * inter.pos.y;
  inter.norm.z = (2.0 / obj->ellipsoid.length) * inter.pos.z;
  inter.norm = vec3_normalize(inter.norm);
  inter.obj = obj;
  return (inter);
}
