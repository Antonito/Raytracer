/*
** ply.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 18:26:44 2016 Antoine Baché
** Last update Mon May 16 00:36:50 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_dist_ply(t_intersect *inter, t_ply *ply, t_ray *ray,
			     t_vec3 *pos)
{
  int		i;
  t_obj		obj;
  t_intersect	tmp;

  i = 0;
  obj.pos = *pos;
  while (i < ply->nb_face)
    {
      if (ply->list_face[i].nb_face < 3)
	return ;
      obj.triangle.pts[0] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[0]].vec, 2);
      obj.triangle.pts[1] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[1]].vec, 2);
      obj.triangle.pts[2] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[2]].vec, 2);
      tmp = get_intersect_triangle(&obj, ray);
      if (!i)
	*inter = tmp;
      if (tmp.dist != -1.0 && tmp.dist < inter->dist)
	*inter = tmp;
      obj.pos = add_vec3(obj.pos, obj.triangle.pts[0]);
      ++i;
    }
}

t_intersect	get_intersect_ply(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if (!obj->ply.ply)
    return (inter);
  get_dist_ply(&inter, obj->ply.ply, ray, &obj->pos);
  return (inter);
}
