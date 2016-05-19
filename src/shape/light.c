/*
** light.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed May 18 23:46:10 2016 Ludovic Petrenko
** Last update Thu May 19 05:29:42 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_dist_light(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	a;
  double	b;
  double	c;
  double	res;

  a = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y +
    ray->dir.z * ray->dir.z;
  b = 2.0 * (ray->dir.x * ray->pos.x +
	     ray->dir.y * ray->pos.y +
	     ray->dir.z * ray->pos.z);
  c = ray->pos.x * ray->pos.x + ray->pos.y *
    ray->pos.y + ray->pos.z * ray->pos.z -
    obj->light.radius * obj->light.radius;
  if ((res = solver_second_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
  else
    inter->dist = res;
}

t_intersect	get_intersect_light(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  int		i;
  int		tmp;

  inter.dir = ray->dir;
  inter.dist = -1.0;
  inter.mat = NULL;
  get_dist_light(obj, ray, &inter);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos.x = ray->pos.x + ray->dir.x * inter.dist;
  inter.pos.y = ray->pos.y + ray->dir.y * inter.dist;
  inter.pos.z = ray->pos.z + ray->dir.z * inter.dist;
  inter.norm.x = inter.pos.x / obj->light.radius;
  inter.norm.y = inter.pos.y / obj->light.radius;
  inter.norm.z = inter.pos.z / obj->light.radius;
  i = -1;
  while (++i < 3)
    {
      tmp = (0.75 - 0.25 * dot_vec3(inter.dir, inter.norm))
	* obj->light.color.argb[i];
      tmp = MAX(0, tmp);
      inter.color.argb[i] = MIN(tmp, 255);
    }
  return (inter);
}
