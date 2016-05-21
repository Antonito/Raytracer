/*
** tore.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 08:11:21 2016 Antoine Baché
** Last update Sat May 21 14:57:37 2016 Antoine Baché
*/

#include "raytracer.h"
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
  t_vec3	tmp;

  double	test[5];

  tmp = ray->pos;
  a = /* (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z * */
    /*    ray->dir.z) * */
    /* (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z * */
    /*  ray->dir.z) */1.0;
  b = 4.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
	     ray->dir.z * ray->dir.z) *
    (ray->dir.x * tmp.x + ray->dir.y * tmp.y + ray->dir.z * tmp.z);
  c = 2.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
	     ray->dir.z) * (tmp.x * tmp.x + tmp.y * tmp.y +
			    tmp.z * tmp.z + obj->torus.radius_hole *
			    obj->torus.radius_hole - obj->torus.radius_solid *
			    obj->torus.radius_solid) +
    4.0 * (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z * tmp.z) *
    (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z *
     tmp.z) - 4.0 * obj->torus.radius_hole * obj->torus.radius_hole *
    (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y);
  d = 4.0 * (tmp.x * ray->dir.x + ray->dir.y * tmp.y + ray->dir.z *
	     tmp.z) * (tmp.x * tmp.x + tmp.y * tmp.y +
			    tmp.z * tmp.z + obj->torus.radius_hole *
			    obj->torus.radius_hole - obj->torus.radius_solid *
			    obj->torus.radius_solid) -
    8.0 * obj->torus.radius_hole * obj->torus.radius_hole *
    (ray->dir.x * tmp.x + ray->dir.y * tmp.y);
  e = (tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z + obj->torus.radius_hole *
       obj->torus.radius_hole - obj->torus.radius_solid *
       obj->torus.radius_solid) *
    (tmp.x * tmp.x + tmp.y * tmp.y + tmp.z * tmp.z + obj->torus.radius_hole *
     obj->torus.radius_hole - obj->torus.radius_solid *
     obj->torus.radius_solid) - 4.0 * obj->torus.radius_hole *
    obj->torus.radius_hole * (tmp.x * tmp.x + tmp.y * tmp.y);
  test[0] = a;
  test[1] = b;
  test[2] = c;
  test[3] = d;
  test[4] = e;
  /* if ((inter->dist = solver_fourth_degree(a, b, c, d, e)) > 0.0001) */
  /*   { */
  /*     printf("%f %f %f %f %f\n", a, b, c, d, e); */
  /*     printf("4: %f N: %f 4: %f\n",inter->dist, */
  /* 	     (test[0] = solver_n_degree(test, 4)), */
  /* 	     (test[1] = solver_fourth_degree(a, b, c, d, e))); */
  /*     read(0, test, 1); */
  /*   } */
  /* inter->dist = solver_fourth_degree(a, b, c, d, e); */
  inter->dist = solver_n_degree(test, 4);
  /* if (inter->dist > 0.0 && fabs(inter->dist - solver_n_degree(test, 4)) > 0.001) */
  /*   { */
  /*     asm("int $3"); */
  /*     solver_n_degree(test, 4); */
  /*   } */
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
