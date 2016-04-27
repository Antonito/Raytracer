/*
** node_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 27 05:31:16 2016 Ludovic Petrenko
** Last update Thu Apr 28 01:24:29 2016 Ludovic Petrenko
*/

#include <math.h>
#include "engine/intersect.h"
#include "engine/octree.h"

t_intersect	node_intersect(t_node *node, t_vec3 pos, t_vec3 dir)
{
  t_intersect	cur;
  t_intersect	tmp;
  t_obj		*obj;
  int		i;

  cur.dist = INFINITY;
  obj = &node->obj_list;
  while (!(obj = obj->next))
    {
      tmp = obj_intersect(obj, pos, dir);
      if (tmp.dist > 0.0 && tmp.dist < cur.dist)
	cur = tmp;
    }
  i = -1;
  while (++i < 8)
}
