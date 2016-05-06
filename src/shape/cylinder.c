/*
** cylinder.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May  3 02:16:26 2016 Antoine Baché
** Last update Fri May  6 22:17:13 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cylinder_special(t_obj *obj, t_ray *ray,
					  t_intersect *inter)
{
  if ((ray->pos.x > obj->cylinder.height) ||
      (ray->pos.x > 0.0 && ray->pos.x < obj->cylinder.height))
    {
      inter->norm.x = 1.0;
      inter->dist = (ray->dir.x) ? (obj->cylinder.height - ray->pos.x) /
	ray->dir.x : -1.0;
    }
  else if (ray->pos.x < 0.0 || (ray->pos.x > 0.0 &&
				ray->pos.x < obj->cylinder.height))
    {
      inter->norm.x = -1.0;
      inter->dist = (ray->dir.x) ? (-1.0 * ray->pos.x) / ray->dir.x : -1.0;
    }
  inter->pos = add_vec3(mult_vec3(ray->dir, inter->dist), ray->pos);
}

static void	get_dist_cylinder(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;

  a = ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z;
  b = 2.0 * ray->dir.y * ray->pos.y + ray->dir.z * ray->pos.z;
  c = ray->pos.y * ray->pos.y + ray->pos.z * ray->pos.z -
    (obj->cylinder.radius * obj->cylinder.radius);
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
  if (inter->dist == -1.0 &&
      (ray->pos.y * ray->pos.y + ray->pos.z * ray->pos.z <=
       obj->cylinder.radius * obj->cylinder.radius))
    {
      get_dist_cylinder_special(obj, ray, inter);
      return ;
    }
  inter->pos = add_vec3(mult_vec3(ray->dir, inter->dist), ray->pos);
  /* inter->norm.y = inter->pos.y / ; */
  /* inter->norm.z = inter->pos.z / ; */
}

t_intersect	get_intersect_cylinder(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.norm.x = 0.0;
  inter.norm.y = 0.0;
  inter.norm.z = 0.0;
  get_dist_cylinder(obj, ray, &inter);
  return (inter);
}
