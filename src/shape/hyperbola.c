/*
** hyperbola.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 13:28:30 2016 Antoine Baché
** Last update Sun May 22 21:28:51 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_hyperbola(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  t_vec3	tmp;

  tmp = sub_vec3(ray->pos, obj->pos);
  a = ((ray->dir.x * ray->dir.x) / 4.0) - ((ray->dir.y * ray->dir.y) / 3.0) +
    (ray->dir.z * ray->dir.z);
  b = ((2.0 * ray->dir.x * tmp.x) / 4.0) -
    ((2.0 * tmp.y * ray->dir.y) / 3.0) + (2.0 * tmp.z * ray->dir.z);
  c = ((tmp.x * tmp.x) / 4.0) - ((tmp.y * tmp.y) / 3.0) + tmp.z * tmp.z - 1.0;
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_hyperbola(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_hyperbola(ray, &inter, obj);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  if (inter.pos.x > obj->hyperbola.length || inter.pos.z < 0.0)
    inter.dist = -1.0;
  inter.obj = obj;
  inter.norm = vec3(0, 0, 0);
  return (inter);
}
