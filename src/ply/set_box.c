/*
** set_box.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu May 19 11:04:18 2016 Ludovic Petrenko
** Last update Thu May 19 11:20:03 2016 Ludovic Petrenko
*/

#include "engine/object.h"

void	set_box(t_obj *obj)
{
  int	i;
  int	j;

  if (obj->ply.nb_obj == 0)
    return ;
  obj->box[0] = obj->ply.objs[0].triangle.pts[0];
  obj->box[1] = obj->ply.objs[0].triangle.pts[0];
  i = -1;
  while (++i < obj->ply.nb_obj)
    {
      j = -1;
      while (++j < 3)
	{
	  obj->box[0] =
	    vec3_min(obj->box[0], obj->ply.objs[i].triangle.pts[j]);
	  obj->box[1] =
	    vec3_max(obj->box[1], obj->ply.objs[i].triangle.pts[j]);
	}
    }
}
