/*
** ply.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 18:26:44 2016 Antoine Baché
** Last update Mon May 16 21:29:01 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

inline static void	get_ply_3(t_obj *obj, t_ply *ply, int i)
{
  obj->triangle.pts[0] = ply->list_vertex[ply->list_face[i].face[0]].vec;
  obj->triangle.pts[1] = ply->list_vertex[ply->list_face[i].face[1]].vec;
  obj->triangle.pts[2] = ply->list_vertex[ply->list_face[i].face[2]].vec;
}

inline static void	get_ply_4(t_obj *obj, t_ply *ply, int i)
{
  obj->triangle.pts[0] = ply->list_vertex[ply->list_face[i].face[0]].vec;
  obj->triangle.pts[1] = ply->list_vertex[ply->list_face[i].face[3]].vec;
  obj->triangle.pts[2] = ply->list_vertex[ply->list_face[i].face[2]].vec;
}

static void	get_dist_ply(t_intersect *inter, t_ply *ply, t_ray *ray,
			     t_vec3 *pos)
{
  int		i;
  t_obj		obj;
  t_intersect	tmp;
  t_intersect	tmp2;

  i = 0;
  obj.pos = *pos;
  while (i < ply->nb_face)
    {
      if (ply->list_face[i].nb_face == 3 || ply->list_face[i].nb_face == 4)
	get_ply_3(&obj, ply, i);
      else
	continue;
      tmp = get_intersect_triangle(&obj, ray);
      if (ply->list_face[i].nb_face == 4)
	{
	  get_ply_4(&obj, ply, i);
	  tmp = (((tmp2 = get_intersect_triangle(&obj, ray)).dist > -1.0 &&
		  tmp2.dist < tmp.dist) || tmp.dist == -1.0) ? tmp2 : tmp;
	}
      if (!i || inter->dist == -1.0 ||
	  (tmp.dist != -1.0 && tmp.dist < inter->dist))
	*inter = tmp;
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
  inter.dir = ray->dir;
  inter.mat = obj->mat;
  return (inter);
}
