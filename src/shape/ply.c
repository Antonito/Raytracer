/*
** ply.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 18:26:44 2016 Antoine Baché
** Last update Wed May 18 01:17:40 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/math.h"

/* static void	get_dist_ply(t_obj *obj, t_intersect *inter) */
/* { */
/*   t_intersect	tmp; */
/*   t_obj		*cur_obj; */

/*   cur->dist = INFINITY; */
/*   obj = &node->obj_list; */
/*   while ((cur_obj = obj->next)) */
/*     { */
/*       tmp.mat = obj->mat; */
/*       tmp = obj->get_intersect(obj, ray); */
/*       if (tmp.dist > 0.0 && tmp.dist < cur->dist) */
/* 	{ */
/* 	  tmp.color.full = (tmp.mat) ? (tmp.mat->color) : DEFAULT_MAT_COLOR; */
/* 	  tmp.obj = obj; */
/* 	  *cur = tmp; */
/* 	} */
/*     } */
/*   subnode_intersect(node, ray, cur); */
/* } */

t_intersect	get_intersect_ply(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if (!obj->ply.ply)
    return (inter);
  /* get_dist_ply(&inter, obj); */
  inter.dir = ray->dir;
  inter.mat = obj->mat;
  node_intersect(obj->ply.node, ray, &inter);
  return (inter);
}
