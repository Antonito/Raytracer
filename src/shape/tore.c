/*
** tore.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 08:11:21 2016 Antoine Baché
** Last update Mon May  9 10:08:37 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_tore(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;

  a = (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
       ray->dir.z) *
    (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
     ray->dir.z);
  b = 4.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
	     ray->dir.z * ray->dir.z) *
    (ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y + ray->dir.z *
     ray->pos.z);
  c = 2.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
	     ray->dir.z) * (ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
			    ray->pos.z * ray->pos.z + obj->torus.radius_hole *
			    obj->torus.radius_hole - obj->torus.radius_solid *
			    obj->torus.radius_solid) +
    4.0 * (ray->pos.x * ray->dir.x + ray->dir.y * ray->pos.y + ray->dir.z *
	   ray->pos.z) *
    (ray->pos.x * ray->dir.x + ray->dir.y * ray->pos.y + ray->dir.z *
     ray->pos.z) - 4.0 * obj->torus.radius_hole * obj->torus.radius_hole *
    (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y);
  d = 4.0 * (ray->pos.x * ray->dir.x + ray->dir.y * ray->pos.y + ray->dir.z *
	     ray->pos.z) * (ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
			    ray->pos.z * ray->pos.z + obj->torus.radius_hole *
			    obj->torus.radius_hole - obj->torus.radius_solid *
			    obj->torus.radius_solid) -
    8.0 * obj->torus.radius_hole * obj->torus.radius_hole *
    (ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y);
  e = (ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
       ray->pos.z * ray->pos.z + obj->torus.radius_hole *
       obj->torus.radius_hole - obj->torus.radius_solid *
       obj->torus.radius_solid) *
    (ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
     ray->pos.z * ray->pos.z + obj->torus.radius_hole *
     obj->torus.radius_hole - obj->torus.radius_solid *
     obj->torus.radius_solid) - 4.0 * obj->torus.radius_hole *
    obj->torus.radius_hole * (ray->pos.x * ray->pos.x + ray->pos.y *
			      ray->pos.y);
  inter->dist = solver_fourth_degree(a, b, c, d, e);
}

t_intersect	get_intersect_tore(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  t_vec3	u;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  get_dist_tore(ray, &inter, obj);
  if (inter.dist < 0.0 || inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  u = sub_vec3(inter.pos, obj->pos);
  u.z = 0.0;
  u = mult_vec3(vec3_normalize(u), obj->torus.radius_hole);
  u = add_vec3(u, obj->pos);
  inter.norm = vec3_normalize(sub_vec3(inter.pos, u));
  return (inter);
}
