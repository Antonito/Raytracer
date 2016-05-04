/*
** tore.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  2 08:11:21 2016 Antoine Baché
** Last update Mon May  2 21:34:03 2016 Ludovic Petrenko
*/

#define HOLE_RADIUS	1.0
#define SOLID_RADIUS	1.0

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_tore(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	tmp[3];
  double	a;
  double	b;
  double	c;
  double	d;
  double	e;

  tmp[0] = ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y + ray->dir.z *
    ray->dir.z;
  tmp[1] = ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y + ray->dir.z *
    ray->pos.z;
  tmp[3] = ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
    ray->pos.z * ray->pos.z + (HOLE_RADIUS * HOLE_RADIUS) -
    (SOLID_RADIUS * SOLID_RADIUS);
  a = tmp[0] * tmp[0];
  b = 4 * tmp[0] * tmp[1];
  c = 2 * tmp[0] * tmp[3] + (tmp[1] * tmp[1]) - 4 * HOLE_RADIUS * HOLE_RADIUS *
    (ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z);
  d = 4 * tmp[1] * tmp[3] - 8 * HOLE_RADIUS * HOLE_RADIUS *
    (ray->dir.x * ray->pos.x + ray->dir.z * ray->pos.z);
  e = tmp[3] * tmp[3] - 4 * HOLE_RADIUS * HOLE_RADIUS *
    (ray->pos.x * ray->pos.x + ray->pos.z * ray->pos.z);
  inter->dist = solver_fourth_degree(a, b, c, d, e);
}

t_intersect	get_intersect_tore(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	tmp[2];

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  get_dist_tore(obj, ray, &inter);
  if (inter.dist == -1.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(inter.dir, inter.dist), ray->pos);
  tmp[0] = inter.pos.x * inter.pos.x + inter.pos.y * inter.pos.y +
    inter.pos.z * inter.pos.z + HOLE_RADIUS * HOLE_RADIUS -
    SOLID_RADIUS * SOLID_RADIUS;
  tmp[1] = 8 * HOLE_RADIUS * HOLE_RADIUS;
  inter.norm.x = 4 * inter.pos.x * tmp[0] - tmp[1] * inter.pos.x;
  inter.norm.y = 4 * inter.pos.y * tmp[0];
  inter.norm.z = 4 * inter.pos.y * tmp[0] - tmp[1] * inter.pos.z;
  return (inter);
}
