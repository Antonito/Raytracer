/*
** build_bsp.c for raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri May 13 10:39:58 2016 Ludovic Petrenko
** Last update Fri May 13 19:38:12 2016 Ludovic Petrenko
*/

#include "engine/bsp.h"

void	push_to_node(t_node *src, t_node *dst, t_obj *obj)
{
  t_obj	*cur;

  cur = &src->obj_list;
  while (cur->next != obj)
    cur = cur->next;
  cur->next = obj->next;
  cur = &src->obj_list;
  while (cur->next)
    cur = cur->next;
  obj->next = cur->next;
  cur->next = obj;
}

int	create_subnode(t_node *node)
{
  if ((node->child[0] = my_malloc(sizeof(t_node))) ||
      (node->child[0] = my_malloc(sizeof(t_node))))
    return (1);

  return (0);
}

int	build_bsp(t_node *node, int level)
{
  t_obj	*cur;
  int	subnode;

  if (level >= 48)
    return (0);
  node->axis = level % 3;
  if (create_subnode(node))
    return (1);
  cur = &node->obj_list;
  while ((cur = cur->next))
    {
      subnode = get_obj_node(node, cur);
      if (subnode != -1)
	push_to_node(node, child[subnode], cur);
    }
  if (build_bsp(level + 1))
    return (1);
  return (0);
}
