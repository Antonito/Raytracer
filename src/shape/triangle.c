/*
** triangle.c for Triangle in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 01:20:34 2016 Antoine Baché
** Last update Sat May 21 05:35:07 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_dist_triangle(t_obj *obj, t_ray *ray, t_intersect *inter,
				  t_vec3 *edge)
{
  double	inv_det;
  double	det;
  double	u;
  double	v;
  t_vec3	dist;
  t_vec3	tmp;
  t_vec3	det_tmp;

  det_tmp = cross_vec3(ray->dir, edge[1]);
  det = dot_vec3(det_tmp, edge[0]);
  if (IS_ZERO(det))
    return ;
  inv_det = 1.0 / det;
  dist = sub_vec3(ray->pos, obj->triangle.pts[0]);
  u = dot_vec3(dist, det_tmp) * inv_det;
  tmp = cross_vec3(dist, edge[0]);
  v = dot_vec3(ray->dir, tmp) * inv_det;
  if (u < 0.0 || u > 1.0 || v < 0.0 || u + v > 1.0)
    return ;
  inter->dist = ((inter->dist = dot_vec3(edge[1], tmp) * inv_det) > 0.000001) ?
    inter->dist : -1.0;
  inter->norm = vec3_normalize(cross_vec3(edge[0], edge[1]));
}

t_intersect	get_intersect_triangle(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  t_vec3	edge[2];

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if (!check_box(obj, ray))
    return (inter);
  edge[0] = sub_vec3(obj->triangle.pts[1], obj->triangle.pts[0]);
  edge[1] = sub_vec3(obj->triangle.pts[2], obj->triangle.pts[0]);
  get_dist_triangle(obj, ray, &inter, edge);
  if (inter.dist == -1.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  return (inter);
}
