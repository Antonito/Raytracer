/*
** cylinder.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May  3 02:16:26 2016 Antoine Baché
** Last update Sun May 22 14:36:51 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_dist_cylinder_face(t_obj *obj, t_ray *ray,
				       t_intersect *inter)
{
  double	t;
  t_vec3	pos;
  double	s;

  s = -1.0;
  while (s < 2.0)
    {
      t = (s * obj->cylinder.height - ray->pos.x) / ray->dir.x;
      pos.x = s * obj->cylinder.height;
      pos.y = ray->pos.y + t * ray->dir.y;
      pos.z = ray->pos.z + t * ray->dir.z;
      if (t > 0.0 && (t < inter->dist || inter->dist < 0.0)
	  && pos.y * pos.y + pos.z * pos.z <=
	  obj->cylinder.radius * obj->cylinder.radius)
	{
	  inter->dist = t;
	  inter->pos = pos;
	  inter->norm = vec3(s, 0, 0);
	}
      s += 2.0;
    }
}

static void	get_dist_cylinder(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;
  t_vec3	tmp;

  tmp = sub_vec3(ray->pos, obj->pos);
  a = ray->dir.y * ray->dir.y + ray->dir.z * ray->dir.z;
  b = 2.0 * (ray->dir.y * tmp.y + ray->dir.z * tmp.z);
  c = tmp.y * tmp.y + tmp.z * tmp.z -
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
  if (inter.dist != -1.0)
    {
      inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
#pragma message("Il faut afficher les face du cylindre")
      inter.norm = vec3(0, inter.pos.y / obj->cylinder.radius,
			inter.pos.z / obj->cylinder.radius);
    }
  if (inter.pos.x >= obj->cylinder.height - 0.00001 ||
      inter.pos.x <= -obj->cylinder.height + 0.00001)
    inter.dist = -1.0;
  get_dist_cylinder_face(obj, ray, &inter);
  return (inter);
}
