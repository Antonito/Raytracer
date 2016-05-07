/*
** node_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 27 05:31:16 2016 Ludovic Petrenko
** Last update Sat May  7 16:00:34 2016 Antoine Baché
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "engine/octree.h"
#include "engine/intersect.h"
#include "engine/object.h"

static bool	is_in_node(t_vec4 p, t_node *node)
{
  if (p.x >= node->min.x && p.x <= node->max.x &&
      p.y >= node->min.y && p.y <= node->max.y &&
      p.z >= node->min.z && p.z <= node->max.z)
    return (true);
  return (false);
}

static void	get_node_dist(t_node *node, t_ray *ray, double *dist)
{
  int		i;
  t_vec4	t;

  i = -1;
  while (++i < 8)
    {
      dist[i] = INFINITY;
      if (node->child[i])
	{
	  t = get_x(ray, (ray->dir.x > 0.0) ? node->child[i]->min.x
		       : node->child[i]->max.x);
	  if (t.w < dist[i] && is_in_node(t, node->child[i]))
	    dist[i] = t.w;
	  t = get_y(ray, (ray->dir.y > 0.0) ? node->child[i]->min.y
		       : node->child[i]->max.y);
	  if (t.w < dist[i] && is_in_node(t, node->child[i]))
	    dist[i] = t.w;
	  t = get_z(ray, (ray->dir.z > 0.0) ? node->child[i]->min.z
		       : node->child[i]->max.z);
	  if (t.w < dist[i] && is_in_node(t, node->child[i]))
	    dist[i] = t.w;
	}
    }
}

static void	subnode_intersect(t_node *node, t_ray *ray, t_intersect *i)
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
      /* id = get_next_node(dist, last); */
      /* if (id == -1 || dist[id] == INFINITY) */
      /* 	return ; */
      if (dist[x] == INFINITY)
	continue ;
      node_intersect(node->child[x], ray, &tmp);
      if (tmp.dist < i->dist)
	{
	  *i = tmp;
	  return ;
	}
      /* last = dist[id]; */
    }
}

void	node_intersect(t_node *node, t_ray *ray, t_intersect *cur)
{
  t_intersect	tmp;
  t_obj		*obj;

  cur->dist = INFINITY;
  obj = &node->obj_list;
  while ((obj = obj->next))
    {
      tmp = obj->get_intersect(obj, ray);
      if (tmp.dist > 0.0 && tmp.dist < cur->dist)
	*cur = tmp;
    }
  subnode_intersect(node, ray, cur);
}
