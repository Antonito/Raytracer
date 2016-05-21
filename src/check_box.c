/*
** check_box.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu May 19 11:36:49 2016 Ludovic Petrenko
** Last update Sat May 21 05:53:39 2016 Ludovic Petrenko
*/

#include <stdbool.h>
#include "engine/object.h"

bool	check_box(t_obj *obj, t_ray *ray)
{
  t_vec3	i;
  double	t;

  t = (((ray->dir.x > 0.0) ? obj->box[0].x : obj->box[1].x) - ray->pos.x)
    / ray->dir.x;
  i.y = ray->pos.y + t * ray->dir.y;
  i.z = ray->pos.z + t * ray->dir.z;
  if (i.y >= obj->box[0].y && i.y <= obj->box[1].y &&
      i.z >= obj->box[0].z && i.z <= obj->box[1].z)
    return (true);
  t = (((ray->dir.y > 0.0) ? obj->box[0].y : obj->box[1].y) - ray->pos.y)
    / ray->dir.y;
  i.x = ray->pos.x + t * ray->dir.x;
  i.z = ray->pos.z + t * ray->dir.z;
  if (i.x >= obj->box[0].x && i.x <= obj->box[1].x &&
      i.z >= obj->box[0].z && i.z <= obj->box[1].z)
    return (true);
  t = (((ray->dir.z > 0.0) ? obj->box[0].z : obj->box[1].z) - ray->pos.z)
    / ray->dir.z;
  i.x = ray->pos.x + t * ray->dir.x;
  i.y = ray->pos.y + t * ray->dir.y;
  if (i.x >= obj->box[0].x && i.x <= obj->box[1].x &&
      i.y >= obj->box[0].y && i.y <= obj->box[1].y)
    return (true);
  return (false);
}
