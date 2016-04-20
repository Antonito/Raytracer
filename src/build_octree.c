/*
** build_octree.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 20 00:59:49 2016 Ludovic Petrenko
** Last update Thu Apr 21 00:31:48 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "engine/octree.h"

int	get_obj_node(t_node *n, t_obj *obj)
{
  static bool	(*get_node[])(t_node *, t_obj *) =
    {&light_node, &sphere_node, &plane_node, &cylinder_node, &cone_node};
  bool		node[8];
  int		i;
  int		cur;

  i = -1;
  while (++i < 8)
    node[i] = get_node[obj->type](n->child[i], obj);
  cur = i = -1;
  while (++i < 8)
    if (cur == -1 && node[i])
      cur = i;
    else if (cur != -1 && node[i])
      return (-1);
  return (cur);
}

int	push_obj_to_subnode(t_obj *obj, t_node *node, int subnode)
{
  t_obj	*cur;

  cur = &node->obj_list;
  while (cur->next != obj)
    cur = cur->next;
  cur->next = obj->next;
  cur = &node->child[subnode]->obj_list;
  while (cur->next)
    cur = cur->next;
  cur->next = obj;
  obj->next = NULL;
  return (0);
}

int		build_subnodes(t_node *node)
{
  t_vec3	size;
  int		i;

  size.x = (node->max.x - node->min.x) / 2.0;
  size.y = (node->max.y - node->min.y) / 2.0;
  size.z = (node->max.z - node->min.z) / 2.0;
  i = -1;
  while (++i < 8)
    {
      if (!(node->child[i] = my_calloc(1, sizeof(t_node))))
	return (1);
      node->child[i]->min.x = node->min.x + size.x * ((i >> 2) & 1);
      node->child[i]->min.y = node->min.y + size.y * ((i >> 1) & 1);
      node->child[i]->min.z = node->min.z + size.z * (i & 1);
      node->child[i]->max.x = node->min.x + size.x * (1 + ((i >> 2) & 1));
      node->child[i]->max.y = node->min.y + size.y * (1 + ((i >> 1) & 1));
      node->child[i]->max.z = node->min.z + size.z * (1 + (i & 1));
    }
  return (0);
}

int	build_octree(t_node *node, int level)
{
  t_obj	*cur;
  int	subnode;
  int	i;

  if (level >= 16)
    return (0);
  if (build_subnodes(node))
    return (1);
  cur = &node->obj_list;
  while ((cur = cur->next))
    if ((subnode = get_obj_node(node, cur)) >= 0)
      if (push_obj_to_subnode(cur, node, subnode))
	return (1);
  i = -1;
  while (++i < 8)
    if (node->child[i]->nb_obj == 0)
      {
	my_free(node->child[i]);
	node->child[i] = NULL;
      }
    else if (build_octree(node->child[i], level + 1))
      return (1);
  return (0);
}