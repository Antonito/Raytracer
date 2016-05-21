/*
** node_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 27 05:31:16 2016 Ludovic Petrenko
** Last update Sat May 21 07:00:42 2016 Ludovic Petrenko
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "engine/bsp.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	subnode_intersect(t_node *node ,t_ray *ray, t_intersect *cur)
{
  t_intersect	tmp;
  int		side;

  side = (((double *)(&ray->dir))[node->axis] < 0.0);
  tmp = *cur;
  if (node->child[side])
    {
      node_intersect(node->child[side], ray, &tmp);
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist + 0.00001)
	  *cur = tmp;
    }
  if (node->child[!side])
    {
      node_intersect(node->child[!side], ray, &tmp);
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist + 0.00001)
	  *cur = tmp;
    }
}

void		node_intersect(t_node *node, t_ray *ray, t_intersect *cur)
{
  t_intersect	tmp;
  t_obj		*obj;

  cur->obj = NULL;
  cur->dist = INFINITY;
  obj = &node->obj_list;
  while ((obj = obj->next))
    {
      tmp.obj = obj;
      tmp = obj->get_intersect(obj, ray);
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist)
	{
	  tmp.obj = obj;
	  *cur = tmp;
	}
    }
  cur->dir = ray->dir;
  cur->pos = add_vec3(ray->pos, mult_vec3(ray->dir, cur->dist));
  subnode_intersect(node, ray, cur);
}
