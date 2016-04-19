/*
** load_light_type.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:48:54 2016 Ludovic Petrenko
** Last update Tue Apr 19 01:57:31 2016 Ludovic Petrenko
*/

#include "raytracer.h"

void	load_point(t_obj *obj, t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->spec.light.type = POINT;
  obj->spec.light.color = DEFAULT_LIGHT_COLOR;
  obj->spec.light.radius = DEFAULT_LIGHT_RADIUS;
  obj->spec.light.power = DEFAULT_LIGHT_POWER;
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "color", 0))
    obj->spec.light.color = my_gethexa(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "radius", 0))
    obj->spec.light.radius = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "power", 0))
    obj->spec.light.power = my_getdouble(tmp);
}

void	load_directionnal(t_obj *obj, t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->spec.light.type = DIRECTIONNAL;
  obj->spec.light.color = DEFAULT_LIGHT_COLOR;
  obj->spec.light.power = DEFAULT_LIGHT_POWER;
  obj->spec.light.dir = DEFAULT_LIGHT_DIR;
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "color", 0))
    obj->spec.light.color = my_gethexa(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "power", 0))
    obj->spec.light.power = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 0))
    obj->spec.light.dir.x = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 1))
    obj->spec.light.dir.y = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 2))
    obj->spec.light.dir.z = my_getdouble(tmp);
}

void	load_directionnal(t_obj *obj, t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->spec.light.type = SPOT;
  obj->spec.light.color = DEFAULT_LIGHT_COLOR;
  obj->spec.light.power = DEFAULT_LIGHT_POWER;
  obj->spec.light.dir = DEFAULT_LIGHT_DIR;
  obj->spec.light.angle = DEFAULT_LIGHT_ANGLE;
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "color", 0))
    obj->spec.light.color = my_gethexa(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "power", 0))
    obj->spec.light.power = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 0))
    obj->spec.light.dir.x = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 1))
    obj->spec.light.dir.y = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "direction", 2))
    obj->spec.light.dir.z = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(scope, "angle", 2))
    obj->spec.light.angle = my_getdouble(tmp);
}
