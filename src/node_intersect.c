/*
** node_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 27 05:31:16 2016 Ludovic Petrenko
** Last update Fri Apr 29 19:27:55 2016 Ludovic Petrenko
*/

#include <math.h>
#include "engine/intersect.h"
#include "engine/octree.h"

static void	get_node_dist(t_node *node, t_ray ray, double *dist)
{
  int		i;
  t_intersect	t;
  t_intersect	tmp;

  i = -1;
  while (++i < 8)
    {
      t.dist = INFINITY;
      if (node->child[i] == NULL)
	dist[i] = INFINITY;
      else
	{
	  tmp = get_x(ray, (ray.dir.x > 0.0) ? node->child[i]->min.x
		      : node->child[i]->max.x);
	  if (tmp.dist < t.dist && is_in_node(tmp.pos, node->child + i,
					      bvec3(false, true, true)))
	    t = tmp;
	  tmp = get_y(ray, (ray.dir.y > 0.0) ? node->child[i]->min.y
		      : node->child[i]->max.y);
	  if (tmp.dist < t.dist && is_in_node(tmp.pos, node->child + i,
					      bvec3(true, false, true)))
	    t = tmp;
	  tmp = get_z(ray, (ray.dir.z > 0.0) ? node->child[i]->min.z
		      : node->child[i]->max.z);
	  if (tmp.dist < t.dist && is_in_node(tmp.pos, node->child + i,
					      bvec3(true, true, false)))
	    t = tmp;
	}
    }
}

static void	subnode_intersect(t_node *node, t_ray ray, t_intersect *i)
{
  double	dist[8];
  int		x;
  double	last;
  int		id;
  t_intersect	tmp;

  get_node_dist(node, ray, dist);
  x = -1;
  last = 0.0;
  while (++x < 8)
    {
      id = get_next_node(dist, last);
      if (id == -1 || dist[id] <= i->dist)
	return ;
      tmp = node_intersect(node->child + id, ray);
      if (tmp.dist < i->dist)
	{
	  *i = tmp;
	  return ;
	}
    }
}

t_intersect	node_intersect(t_node *node, t_ray ray)
{
  t_intersect	cur;
  t_intersect	tmp;
  t_obj		*obj;

  cur.dist = INFINITY;
  obj = &node->obj_list;
  while (!(obj = obj->next))
    {
      tmp = obj_intersect(obj, ray);
      if (tmp.dist > 0.0 && tmp.dist < cur.dist)
	cur = tmp;
    }
  subnode_intersect(node, ray, &cur);
  return (cur);
}
