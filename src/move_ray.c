/*
** move_ray.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue May 17 13:05:49 2016 Ludovic Petrenko
** Last update Sun May 22 20:06:23 2016 Antoine Baché
*/

#include "engine/ray.h"
#include "engine/object.h"
#include "tools/math.h"

void		move_ray(t_obj *obj, t_ray *src, t_ray *dest)
{
  t_vec3	a;
  t_vec3	b;

  a.x = src->dir.x;
  a.y = src->dir.y * my_cos(obj->rot.x, DRAW) -
    src->dir.z * my_sin(obj->rot.x, DRAW);
  a.z = src->dir.y * my_sin(obj->rot.x, DRAW) +
    src->dir.z * my_cos(obj->rot.x, DRAW);
  b.x = a.x * my_cos(obj->rot.y, DRAW) +
    a.z * my_sin(obj->rot.y, DRAW);
  b.y = a.y;
  b.z = -a.x * my_sin(obj->rot.y, DRAW) +
    a.z * my_cos(obj->rot.y, DRAW);
  dest->dir.x = b.x * my_cos(obj->rot.z, DRAW) -
    b.y * my_sin(obj->rot.z, DRAW);
  dest->dir.y = b.x * my_sin(obj->rot.z, DRAW) +
    b.y * my_cos(obj->rot.z, DRAW);
  dest->dir.z = b.z;
  b.x = src->pos.x - obj->pos.x;
  b.y = src->pos.y - obj->pos.y;
  b.z = src->pos.z - obj->pos.z;
  a.x = b.x;
  a.y = b.y * my_cos(obj->rot.x, DRAW) -
    b.z * my_sin(obj->rot.x, DRAW);
  a.z = b.y * my_sin(obj->rot.x, DRAW) +
    b.z * my_cos(obj->rot.x, DRAW);
  b.x = a.x * my_cos(obj->rot.y, DRAW) +
    a.z * my_sin(obj->rot.y, DRAW);
  b.y = a.y;
  b.z = -a.x * my_sin(obj->rot.y, DRAW) +
    a.z * my_cos(obj->rot.y, DRAW);
  dest->pos.x = b.x * my_cos(obj->rot.z, DRAW) -
    b.y * my_sin(obj->rot.z, DRAW);
  dest->pos.y = b.x * my_sin(obj->rot.z, DRAW) +
    b.y * my_cos(obj->rot.z, DRAW);
  dest->pos.z = b.z;
}


void		unmove_intersect(t_intersect *i, t_obj *obj)
{
  t_vec3	a;
  t_vec3	b;

  if (obj == NULL)
    return ;
  a.x = i->norm.x * my_cos(obj->rot.z, DRAW) -
    i->norm.y * my_sin(-obj->rot.z, DRAW);
  a.y = i->norm.x * my_sin(-obj->rot.z, DRAW) +
    i->norm.y * my_cos(obj->rot.z, DRAW);
  a.z = i->norm.z;
  b.x = a.x * my_cos(obj->rot.y, DRAW) +
    a.z * my_sin(-obj->rot.y, DRAW);
  b.y = a.y;
  b.z = -a.x * my_sin(-obj->rot.y, DRAW) +
    a.z * my_cos(obj->rot.y, DRAW);
  i->norm.x = b.x;
  i->norm.y = b.y * my_cos(obj->rot.x, DRAW) -
    b.z * my_sin(-obj->rot.x, DRAW);
  i->norm.z = b.y * my_sin(-obj->rot.x, DRAW) +
    b.z * my_cos(obj->rot.x, DRAW);
}
