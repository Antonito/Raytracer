/*
** sphere.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 04:39:20 2016 Antoine Baché
** Last update Sat May  7 06:13:00 2016 Ludovic Petrenko
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
  b = 2.0 * (ray->dir.x * (ray->pos.x - obj->pos.x) +
	     ray->dir.y * (ray->pos.y - obj->pos.y) +
	     ray->dir.z * (ray->pos.z - obj->pos.z));
  c = (obj->pos.x - ray->pos.x) * (obj->pos.x - ray->pos.x) +
    (obj->pos.y - ray->pos.y) * (obj->pos.y - ray->pos.y) +
    (obj->pos.z - ray->pos.z) * (obj->pos.z - ray->pos.z) -
    obj->sphere.radius * obj->sphere.radius;
  if ((res = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
  else
    inter->dist = res;
}

t_intersect	get_intersect_sphere(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  if (ray->src == obj)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_sphere(obj, ray, &inter);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  inter.norm = vec3_normalize(sub_vec3(inter.pos, obj->pos));
  inter.obj = obj;
  return (inter);
}
