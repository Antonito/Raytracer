/*
** ply.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 18:26:44 2016 Antoine Baché
** Last update Sun May 15 17:43:15 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

static void	get_dist_ply(t_intersect *inter, t_ply *ply, t_ray *ray)
{
  int		i;
  t_obj		obj;

  i = 0;
  while (i < ply->nb_face)
    {
      if (ply->list_face[i].nb_face != 3)
	return ;
      obj.triangle.pts[0] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[0]].vec, 2);
      obj.triangle.pts[1] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[1]].vec, 2);;
      obj.triangle.pts[2] =
	div_vec3(ply->list_vertex[ply->list_face[i].face[2]].vec, 2);
      (*inter) = get_intersect_triangle(&obj, ray);
      if (IS_ZERO(inter->dist))
	return ;
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
  get_dist_ply(&inter, obj->ply.ply, ray);
  return (inter);
}
