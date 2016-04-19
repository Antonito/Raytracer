/*
** octree.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 00:24:50 2016 Ludovic Petrenko
** Last update Mon Apr 18 11:04:51 2016 Antoine Baché
*/

#ifndef OCTREE_H_
# define OCTREE_H_

# include "vector.h"
# include "object.h"

typedef enum	e_node_name
{
  N,
  NE,
  NW,
  S,
  SE,
  SW,
  E,
  W
}		t_node_name;

typedef struct	s_node
{
  t_vec3	min;
  t_vec3	max;
  struct s_node	*child[8];
  int		nb_obj;
  t_obj		**objs;
}		t_node;

#endif /* !OCTREE_H_ */
