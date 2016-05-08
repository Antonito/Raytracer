/*
** cylinder.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May  3 02:16:26 2016 Antoine Baché
** Last update Sun May  8 02:14:32 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cylinder(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;

  a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
  b = 2.0 * (ray->dir.x * ray->pos.x + ray->dir.z * ray->pos.z);
  c = ray->pos.x * ray->pos.x + ray->pos.z * ray->pos.z -
    obj->cylinder.radius * obj->cylinder.radius;
  if ((inter->dist = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_cylinder(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.norm.x = 0.0;
  inter.norm.y = 0.0;
  inter.norm.z = 0.0;
  inter.dist = -1.0;
  get_dist_cylinder(obj, ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
#pragma message("Il faut afficher les face du cylindre")
  if (inter.pos.y > obj->cylinder.height ||
      inter.pos.y < -obj->cylinder.height)
    {
      inter.dist = -1.0;
    }
  return (inter);
}
