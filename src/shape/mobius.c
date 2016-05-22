/*
** mobius.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 07:24:31 2016 Antoine Baché
** Last update Sun May 22 21:17:00 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "tools/math.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	calc_mobius_normale(t_intersect *inter, double v, double t)
{
  t_vec3       	dt;
  t_vec3       	dv;

  dt.x = (1.0 / 2.0) * cos(v) * cos(v / 2.0);
  dt.y = (1.0 / 2.0) * sin(v) * cos(v / 2.0);
  dt.z = (1.0 / 2.0) * sin(v / 2.0);
  dv.y = -sin(v) - (t / 2.0) * sin(v) * cos(v / 2.0) - (t / 4.0) * cos(v) *
    sin(v / 2);
  dv.y = cos(v) + (t / 2.0) * cos(v) * cos(v / 2.0) - (t / 4.0) * sin(v) *
    sin(v / 2);
  dv.z = (t / 4.0) * cos(v / 2.0);
  inter->norm.x = dt.y * dv.z - dt.z * dv.y;
  inter->norm.y = dt.z * dv.x - dt.x * dv.z;
  inter->norm.z = dt.x * dv.y - dt.y * dv.x;
}

static void	get_dist_mobius(t_ray *ray, t_intersect *inter)
{
  double	s[4];

  s[0] = ray->dir.x * ray->dir.x * ray->dir.y - 2 * ray->dir.x * ray->dir.x *
    ray->dir.z - 2 * ray->dir.y * ray->dir.y * ray->dir.z + ray->dir.y *
    ray->dir.z * ray->dir.z + ray->dir.y * ray->dir.y * ray->dir.y;
  s[1] = ray->dir.x * ray->dir.x * ray->pos.y - 2 * ray->dir.x * ray->dir.x *
    ray->pos.z + 2 * ray->dir.x * ray->dir.y * ray->pos.x - 2 * ray->dir.x *
    ray->dir.y - 4 * ray->dir.y * ray->dir.z * ray->pos.y + 2 * ray->dir.y *
    ray->dir.z * ray->pos.z - 4 * ray->dir.x * ray->dir.z * ray->pos.x + 3 *
    ray->dir.y * ray->dir.y * ray->pos.y - 2 * ray->dir.y * ray->dir.y *
    ray->pos.z + ray->dir.z * ray->dir.z * ray->pos.y;
  s[2] = 2 * ray->dir.x * ray->pos.x * ray->pos.y - 4*ray->dir.x * ray->pos.x *
    ray->pos.z - 2 * ray->dir.x * ray->pos.y + ray->dir.y * ray->pos.x *
    ray->pos.x - 2 * ray->dir.y * ray->pos.x + 3 * ray->dir.y * ray->pos.y *
    ray->pos.y - 4*ray->dir.y * ray->pos.y * ray->pos.z + ray->dir.y *
    ray->pos.z * ray->pos.z - ray->dir.y - 2 * ray->dir.z * ray->pos.x *
    ray->pos.x - 2 * ray->dir.z * ray->pos.y * ray->pos.y + 2 * ray->dir.z *
    ray->pos.y * ray->pos.z;
  s[3] = ray->pos.x * ray->pos.x * ray->pos.y - 2 * ray->pos.x * ray->pos.x *
    ray->pos.z - 2 * ray->pos.x * ray->pos.y + ray->pos.y * ray->pos.y *
    ray->pos.y - 2 * ray->pos.y * ray->pos.y * ray->pos.z + ray->pos.y *
    ray->pos.z * ray->pos.z - ray->pos.y;
  if ((inter->dist = solver_n_degree(s, 4)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_mobius(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	v;
  double	t;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_mobius(ray, &inter);
  if (inter.dist == -1.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  v = atan(inter.pos.y / inter.pos.x);
  t = (2.0 * inter.pos.z) / sin((v / 2.0));
  if (!(v > 0 && v < 2 * M_PI && t >= -1.0 && t <= 1.0))
    inter.dist = -1.0;
  calc_mobius_normale(&inter, v, t);
  return (inter);
}
