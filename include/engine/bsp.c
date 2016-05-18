/*
** bsp.c for raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri May 13 10:25:37 2016 Ludovic Petrenko
** Last update Fri May 13 19:22:17 2016 Ludovic Petrenko
*/

#ifndef BSP_H_
# define BSP_H_

# include "object.h"

typedef struct	s_node
{
  enum
    {
      AXIS_X,
      AXIS_Y,
      AXIS_Z
    }		axis;
  double	limit;
  struct s_node	*super;
  struct s_node	*child[2];
  int		nb_obj;
  t_obj		obj_list;
}		t_node;

#endif /* !BSP_H_ */
