/*
** object.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:33:45 2016 Ludovic Petrenko
** Last update Fri Apr 15 01:28:46 2016 Ludovic Petrenko
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "vector.h"
# include "ray.h"
# include "intersect.h"

typedef enum	e_obj_type
  {
    NONE = -1,
    SPHERE,
    PLANE,
    CYLINDER,
    CONE
  }		t_obj_type;

typedef struct	s_obj
{
  t_vec3	pos;
  t_vec3	rot;
  unsigned int	color;
  double	opacity;
  double	reflectivity;
  struct s_obj	*next;
  struct s_obj	*sub;
  t_intersect	(*get_intersect)(void *, t_ray);
}		t_obj;

#endif /* !OBJECT_H_ */
