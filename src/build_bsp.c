/*
** build_bsp.c for raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri May 13 10:39:58 2016 Ludovic Petrenko
** Last update Sat May 21 06:45:29 2016 Ludovic Petrenko
*/

#include "tools/memory.h"
#include "engine/bsp.h"

static void	push_to_node(t_node *src, t_node *dst, t_obj *obj)
{
  t_obj		*cur;

  cur = &src->obj_list;
  while (cur->next != obj)
    cur = cur->next;
  cur->next = obj->next;
  cur = &src->obj_list;
  while (cur->next)
    cur = cur->next;
  obj->next = NULL;
  cur->next = obj;
  if (dst != src->super)
    ++dst->nb_obj;
  else
    --src->nb_obj;

}

static int	create_subnode(t_node *node)
{
  double	mid;

  if ((node->child[0] = my_malloc(sizeof(t_node))) ||
      (node->child[1] = my_malloc(sizeof(t_node))))
    return (1);
  node->child[0]->box[0] = node->child[1]->box[1] = node->box[0];
  node->child[0]->box[0] = node->child[1]->box[1] = node->box[1];
  mid = (((double *)(node->box))[node->axis] +
	 ((double *)(node->box))[node->axis]) / 2.0;
  ((double *)(node->child[0]->box + 1))[node->axis] = mid;
  ((double *)(node->child[1]->box))[node->axis] = mid;
  return (0);
}

static int	get_obj_node(t_node *node, t_obj *obj)
{
  int		side;

  side = (((double *)(obj->triangle.pts))[node->axis] < node->limit);
  if ((((double *)(obj->triangle.pts + 1))[node->axis] < node->limit) != side)
    return (-1);
  if ((((double *)(obj->triangle.pts + 2))[node->axis] < node->limit) != side)
    return (-1);
  return (side + 1);
}

static int	build_subnode(t_node *node, int level)
{
  if (node->child[0]->nb_obj == 0)
    {
      my_free(node->child[0]);
      node->child[0] = NULL;
    }
  else if (build_bsp(node->child[0], level))
    return (1);
  if (node->child[1]->nb_obj == 0)
    {
      my_free(node->child[1]);
      node->child[1] = NULL;
    }
  else if (build_bsp(node->child[1], level))
    return (1);
  return (0);
}

int	build_bsp(t_node *node, int level)
{
  t_obj	*cur;
  int	subnode;

  if (level >= 12)
    return (0);
  node->axis = level % 3;
  if (create_subnode(node))
    return (1);
  cur = &node->obj_list;
  while ((cur = cur->next))
    {
      subnode = get_obj_node(node, cur);
      if (subnode != -1)
	push_to_node(node, node->child[subnode], cur);
    }
  if (build_subnode(node, level + 1))
    return (1);
  return (0);
}
