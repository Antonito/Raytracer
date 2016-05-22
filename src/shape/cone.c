/*
** cone.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 03:24:31 2016 Antoine Baché
** Last update Sun May 22 19:11:09 2016 Ludovic Petrenko
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cone_face(t_obj *obj, t_ray *ray,
				   t_intersect *inter)
{
  double	t;
  t_vec3	pos;

  t = (obj->cone.height - ray->pos.z) / ray->dir.z;
  pos.x = ray->pos.x + t * ray->dir.x;
  pos.y = ray->pos.y + t * ray->dir.y;
  pos.z = obj->cone.height;
  if (t > 0.0 && (t < inter->dist || inter->dist < 0.0)
      && pos.x * pos.x + pos.y * pos.y <=
      obj->cone.radius * obj->cone.radius)
    {
      inter->dist = t;
      inter->pos = pos;
      inter->norm = vec3(0, 0, 1);
    }
}

static void	get_dist_cone(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  double	d;
  t_vec3	tmp;

  tmp = ray->pos;
  d = tan(obj->cone.angle);
  d *= d;
  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y -
    d * ray->dir.z  * ray->dir.z;
  b = 2.0 * (tmp.x * ray->dir.x + tmp.y * ray->dir.y -
	     d * tmp.z * ray->dir.z);
  c = tmp.x * tmp.x + tmp.y * tmp.y - d * tmp.z * tmp.z;
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
  if (inter.dist != -1.0)
    {
      inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
      if (inter.pos.z > obj->cone.height || inter.pos.z < 0.0)
	inter.dist = -1.0;
      inter.norm = vec3(inter.pos.x, inter.pos.y, -cos(obj->cone.angle));
      inter.norm = vec3_normalize(inter.norm);
    }
  get_dist_cone_face(obj, ray, &inter);
  inter.obj = obj;
  return (inter);
}
