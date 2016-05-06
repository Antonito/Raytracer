/*
** triangle.c for Triangle in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 01:20:34 2016 Antoine Baché
** Last update Fri May  6 22:17:58 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

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
  det = dot_vec3(edge[0], det_tmp);
  if ((det > -0.000001 && det < 0.000001) || det == 0.0)
    return ;
  inv_det = 1.0 / det;
  dist = sub_vec3((t_vec3){0.0, 0.0, 0.0}, obj->triangle.poly[0]);
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
  edge[0] = sub_vec3(obj->triangle.poly[1], obj->triangle.poly[0]);
  edge[1] = sub_vec3(obj->triangle.poly[2], obj->triangle.poly[0]);
  get_dist_triangle(obj, ray, &inter, edge);
  if (inter.dist == -1.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  return (inter);
}
