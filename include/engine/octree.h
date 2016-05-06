/*
** octree.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 00:24:50 2016 Ludovic Petrenko
** Last update Sat May  7 00:14:12 2016 Ludovic Petrenko
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

void		node_intersect(t_node *node, t_ray *ray, t_intersect *i);
int		get_next_node(double *dist, double last);
bool		light_node(t_node *node, t_obj *obj);
bool		sphere_node(t_node *node, t_obj *obj);
bool		plane_node(t_node *node, t_obj *obj);
bool		cylinder_node(t_node *node, t_obj *obj);
bool		cone_node(t_node *node, t_obj *obj);
int		build_octree(t_node *node, int level);

#endif /* !OCTREE_H_ */
