/*
** tore.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 08:11:21 2016 Antoine Baché
** Last update Sun May 22 21:13:09 2016 Antoine Baché
*/

#include "raytracer.h"
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static double	calc_d_tore(t_ray *ray, t_vec3 tmp, t_obj *obj)
{
  return (4.0 * (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z *
		 tmp.z) * (tmp.x * tmp.x + tmp.y * tmp.y +
			   tmp.z * tmp.z + obj->torus.radius_hole *
			   obj->torus.radius_hole - obj->torus.radius_solid *
			   obj->torus.radius_solid) -
	  8.0 * obj->torus.radius_hole * obj->torus.radius_hole *
	  (ray->dir.x * tmp.x + ray->dir.y * tmp.y));
}

static double	calc_c_tore(t_ray *ray, t_vec3 tmp, t_obj *obj)
{
  double	fast;

  fast =  (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
	   ray->dir.z * ray->dir.z);
  return (2.0 * fast *
	  (tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z +
	   obj->torus.radius_hole *
	   obj->torus.radius_hole - obj->torus.radius_solid *
	   obj->torus.radius_solid) + 4.0 *
	  (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z * tmp.z) *
	  (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z *
	   tmp.z) - 4.0 * obj->torus.radius_hole * obj->torus.radius_hole *
	  (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y));
}

static void	get_dist_tore(t_ray *ray, t_intersect *inter, t_obj *obj)
{
  double	a[5];
  t_vec3	tmp;
  double	fast;

  tmp = ray->pos;
  a[0] = 1.0;
  fast =  (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
	   ray->dir.z * ray->dir.z);
  a[1] = 4.0 * fast * (ray->dir.x * tmp.x + ray->dir.y * tmp.y + ray->dir.z *
		    tmp.z);
  a[2] = calc_c_tore(ray, tmp, obj);
  a[3] = calc_d_tore(ray, tmp, obj);
  a[4]  = (tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z +
	   obj->torus.radius_hole *
       obj->torus.radius_hole - obj->torus.radius_solid *
       obj->torus.radius_solid) *
    (tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z + obj->torus.radius_hole *
     obj->torus.radius_hole - obj->torus.radius_solid *
     obj->torus.radius_solid) - 4.0 * obj->torus.radius_hole *
    obj->torus.radius_hole * (tmp.x * tmp.x + tmp.y * tmp.y);
  if ((inter->dist = solver_n_degree(a, 4)) < 0)
    inter->dist = -1.0;
}

t_intersect	get_intersect_tore(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  t_vec3	u;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  if (!check_box(obj, ray))
    return (inter);
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
