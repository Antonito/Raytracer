/*
** scene_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat May 21 02:22:35 2016 Ludovic Petrenko
** Last update Sun May 22 18:50:49 2016 Ludovic Petrenko
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "raytracer.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "engine/scene.h"

void		scene_intersect(t_scene *scene, t_ray *ray, t_intersect *cur)
{
  t_intersect	tmp;
  t_obj		*obj;
  t_ray		rotated;
  int		i;

  cur->dist = INFINITY;
  cur->obj = NULL;
  obj = scene->objs;
  i = -1;
  while (obj->next)
    {
      if ((obj = scene->objs + ++i)->type == NONE)
	continue ;

      move_ray(obj, ray, &rotated);
      tmp = obj->get_intersect(obj, &rotated);
      tmp.dir = ray->dir;
      tmp.tex = obj->tex;
      tmp.obj = obj;
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist + 0.00001)/*  && */
	  /* (tmp.mat || obj->type == LIGHT)) */
	{
	  if (tmp.mat && !tmp.tex && tmp.obj != scene->select)
	    tmp.color.full = tmp.mat->color;
	  tmp.obj = obj;
	  *cur = tmp;
	}
    }
  unmove_intersect(cur, cur->obj);
  cur->dir = ray->dir;
  cur->pos = add_vec3(ray->pos, mult_vec3(ray->dir, cur->dist));
}
