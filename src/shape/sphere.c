/*
** sphere.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 04:39:20 2016 Antoine Baché
** Last update Wed May 18 06:17:45 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_sphere(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;
  double	res;

  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
    ray->dir.z * ray->dir.z;
  b = 2.0 * (ray->dir.x * ray->pos.x +
	     ray->dir.y * ray->pos.y +
	     ray->dir.z * ray->pos.z);
  c = ray->pos.x * ray->pos.x + ray->pos.y *
    ray->pos.y + ray->pos.z * ray->pos.z -
    obj->sphere.radius * obj->sphere.radius;
  if ((res = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
  else
    inter->dist = res;
}

t_intersect	get_intersect_sphere(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_sphere(obj, ray, &inter);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos.x = ray->pos.x + ray->dir.x * inter.dist;
  inter.pos.y = ray->pos.y + ray->dir.y * inter.dist;
  inter.pos.z = ray->pos.z + ray->dir.z * inter.dist;
  inter.norm.x = inter.pos.x / obj->sphere.radius;
  inter.norm.y = inter.pos.y / obj->sphere.radius;
  inter.norm.z = inter.pos.z / obj->sphere.radius;
  return (inter);
}
