/*
** hyperbola.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 13:28:30 2016 Antoine Baché
** Last update Tue May 10 13:57:19 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_hyperbola(t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;

  a = ((ray->dir.x * ray->dir.x) / 4.0) - ((ray->dir.y * ray->dir.y) / 3.0) +
    (ray->dir.z * ray->dir.z);
  b = ((2.0 * ray->dir.x * ray->pos.x) / 4.0) -
    ((2.0 * ray->pos.y * ray->dir.y) / 3.0) + (2.0 * ray->pos.z * ray->dir.z);
  c = ((ray->pos.x * ray->pos.x) / 4.0) - ((ray->pos.y * ray->pos.y) / 3.0) +
    ray->pos.z * ray->pos.z - 1.0;
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_hyperbola(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_hyperbola(ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  if (inter.pos.x > obj->hyperbola.length || inter.pos.z < 0.0)
    inter.dist = -1.0;
  inter.obj = obj;
  return (inter);
}
