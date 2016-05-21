/*
** cone.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 03:24:31 2016 Antoine Baché
** Last update Sat May 21 19:22:08 2016 Antoine Baché
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
  t_vec3	tmp;

  tmp = ray->pos;
  d = obj->cone.angle * obj->cone.angle;
  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y -
    ((ray->dir.z  * ray->dir.z) / (d));
  b = 2.0 * (tmp.x * ray->dir.x + tmp.y * ray->dir.y -
	     ((tmp.z * ray->dir.z) / (d)));
  c = tmp.x * tmp.x + tmp.y * tmp.y - ((tmp.z * tmp.z) / (d));
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_cone(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	tmp[2];

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_cone(ray, &inter, obj);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  if (inter.pos.z > obj->cone.height || inter.pos.z < 0.0)
    inter.dist = -1.0;
  tmp[0] = 2.0 * (ray->dir.x * inter.pos.x + ray->dir.y *
		  inter.pos.y + ray->dir.z * inter.pos.z);
  tmp[1] = 2.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
		  ray->dir.z * ray->dir.z) * obj->cone.angle * obj->cone.angle;
  inter.norm = sub_vec3(mult_vec3(ray->dir, tmp[0]),
			mult_vec3(inter.pos, tmp[1]));
  inter.obj = obj;
  return (inter);
}
