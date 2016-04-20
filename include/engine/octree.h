/*
** octree.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 00:24:50 2016 Ludovic Petrenko
** Last update Thu Apr 21 00:29:51 2016 Ludovic Petrenko
*/

#ifndef OCTREE_H_
# define OCTREE_H_

# include "vector.h"
# include "object.h"

# define HALF_X		4
# define HALF_Y		2
# define HALF_Z		1

typedef struct	s_node
{
  t_vec3	min;
  t_vec3	max;
  struct s_node	*child[8];
  int		nb_obj;
  t_obj		obj_list;
}		t_node;

bool	light_node(t_node *node, t_obj *obj);
bool    sphere_node(t_node *node, t_obj *obj);
bool    plane_node(t_node *node, t_obj *obj);
bool    cylinder_node(t_node *node, t_obj *obj);
bool	cone_node(t_node *node, t_obj *obj);

#endif /* !OCTREE_H_ */
