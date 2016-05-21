/*
** scene_intersect.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat May 21 02:22:35 2016 Ludovic Petrenko
** Last update Sat May 21 04:57:52 2016 Ludovic Petrenko
*/

#define _ISOC99_SOURCE

#include <math.h>
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
  obj = scene->objs;
  i = -1;
  while (obj->next)
    {
      obj = scene->objs + ++i;
      tmp.obj = obj;
      move_ray(obj, ray, &rotated);
      tmp.mat = obj->mat;
      tmp = obj->get_intersect(obj, &rotated);
      /* printf("tmp.dist %f\n", tmp.dist); */
      /* printf("cur->dist %f\n", cur->dist); */
      /* printf("tmp.mat %p\n", tmp.mat); */
      /* printf("obj->type %d\n", obj->type); */
      if (tmp.dist > 0.00001 && tmp.dist < cur->dist + 0.00001 &&
	  (tmp.mat || obj->type == LIGHT))
	{
	  if (tmp.mat)
	    tmp.color.full = tmp.mat->color;
	  tmp.obj = obj;
	  *cur = tmp;
	}
    }
  unmove_intersect(cur, cur->obj);
  cur->dir = ray->dir;
  cur->pos = add_vec3(ray->pos, mult_vec3(ray->dir, cur->dist));
}
