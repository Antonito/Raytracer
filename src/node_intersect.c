/*
** node_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 27 05:31:16 2016 Ludovic Petrenko
** Last update Fri May 20 17:37:18 2016 Luka Boulagnon
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
      if (dist[x] == INFINITY)
	continue ;
      node_intersect(node->child[x], ray, &tmp);
      if (tmp.dist < i->dist)
	{
	  *i = tmp;
	  return ;
	}
    }
}

void	node_intersect(t_node *node, t_ray *ray, t_intersect *cur)
{
  t_intersect	tmp;
  t_obj		*obj;
  t_ray		rotated;

  cur->obj = NULL;
  cur->dist = INFINITY;
  obj = &node->obj_list;
  while ((obj = obj->next))
    {
      tmp.obj = obj;
      move_ray(obj, ray, &rotated);
      tmp.mat = obj->mat;
      tmp = obj->get_intersect(obj, &rotated);
      /* printf("tmp.dist %f\n", tmp.dist); */
      /* printf("cur.dist %f\n", cur->dist); */
      /* printf("tmp.mat %p\n", tmp.mat); */
      /* printf("obj->type %d\n", obj->type); */
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist + 0.00001 &&
	  (tmp.mat || obj->type == LIGHT))
	{
	  if (tmp.mat)
	    tmp.color.full = tmp.mat->color;
	  tmp.obj = obj;
	  *cur = tmp;
	}
    }
  unmove_intersect(cur, cur->obj);
  cur->dir = ray->dir;
  cur->pos = add_vec3(ray->pos, mult_vec3(ray->dir, cur->dist));
  /* subnode_intersect(node, ray, cur); */
}
