/*
** sphere.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 04:39:20 2016 Antoine Baché
** Last update Mon May  2 17:11:40 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"

static void	get_dist_sphere(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;
  double	res;

  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
    ray->dir.z + ray->dir.z;
  b = 2 * ray->dir.x * (ray->pos.x - obj->pos.x) +
    2 * ray->dir.y * (ray->pos.y - obj->pos.y) +
    2 * ray->dir.z * (ray->pos.z - obj->pos.z);
  c = obj->pos.x * obj->pos.x + obj->pos.y * obj->pos.y +
    obj->pos.z * obj->pos.z + ray->pos.x * ray->pos.x +
    ray->pos.y * ray->pos.y + ray->pos.z * ray->pos.z -
    2 * (obj->pos.x * ray->pos.x + obj->pos.y * ray->pos.y +
	 obj->pos.z * ray->pos.z) -
    obj->spec.sphere.radius * obj->spec.sphere.radius;
  if ((res = solver_second_degree(a, b, c)) == NOT_A SOLUTION || res == -1.0)
    {
      inter->dist = -1.0;
      return ;
    }
  inter->dist = res;
}

t_intersect	get_intersect_sphere(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.material = obj->mat;
  get_dist_sphere(obj, ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(ray->pos, mult_vec3(inter.dir, inter.dist));
  inter.norm = div_vec3(sub_vec3(inter.pos - obj->pos), obj->spec.radius);
  return (inter);
}
