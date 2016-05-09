/*
** sphere.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 04:39:20 2016 Antoine Baché
** Last update Mon May  9 04:48:01 2016 Ludovic Petrenko
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
  t_vec3	tmp;

  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
    ray->dir.z * ray->dir.z;
  tmp = sub_vec3(ray->pos, obj->pos);
  b = 2.0 * (ray->dir.x * tmp.x +
	     ray->dir.y * tmp.y +
	     ray->dir.z * tmp.z);
  c = tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z -
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
  /* inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist)); */
  inter.pos.x = ray->pos.x + ray->dir.x * inter.dist;
  inter.pos.y = ray->pos.y + ray->dir.y * inter.dist;
  inter.pos.z = ray->pos.z + ray->dir.z * inter.dist;
  /* inter.norm = sub_vec3(inter.pos, obj->pos); */
  inter.norm.x = (inter.pos.x - obj->pos.x) / obj->sphere.radius;
  inter.norm.y = (inter.pos.y - obj->pos.y) / obj->sphere.radius;
  inter.norm.z = (inter.pos.z - obj->pos.z) / obj->sphere.radius;
  /* if (dot_vec3(inter.dir, inter.norm) >= 0.0 && ray->src == obj) */
  /*   inter.dist = -1.0; */
  /* else */
    inter.obj = obj;
  return (inter);
}
