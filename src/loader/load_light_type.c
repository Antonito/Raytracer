/*
** load_light_type.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:48:54 2016 Ludovic Petrenko
** Last update Sun May 22 13:18:18 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "engine/object.h"
#include "tools/str.h"

void	load_point(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->light.type = POINT;
  obj->light.color.full = DEFAULT_LIGHT_COLOR;
  obj->light.radius = DEFAULT_LIGHT_RADIUS;
  obj->light.power = DEFAULT_LIGHT_POWER;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, COLOR_FIELD, 0)))
    obj->light.color.full = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->light.radius = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POWER_FIELD, 0)))
    obj->light.power = my_getdouble(tmp);
}

void	load_directionnal(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->light.type = DIRECTIONNAL;
  obj->light.color.full = DEFAULT_LIGHT_COLOR;
  obj->light.power = DEFAULT_LIGHT_POWER;
  obj->light.dir = DEFAULT_LIGHT_DIR;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, COLOR_FIELD, 0)))
    obj->light.color.full = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POWER_FIELD, 0)))
    obj->light.power = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 0)))
    obj->light.dir.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 1)))
    obj->light.dir.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 2)))
    obj->light.dir.z = my_getdouble(tmp);
  obj->light.dir = vec3_normalize(obj->light.dir);
}

void	load_spot(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->light.type = SPOT;
  obj->light.color.full = DEFAULT_LIGHT_COLOR;
  obj->light.power = DEFAULT_LIGHT_POWER;
  obj->light.dir = DEFAULT_LIGHT_DIR;
  obj->light.angle = DEFAULT_LIGHT_ANGLE;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, COLOR_FIELD, 0)))
    obj->light.color.full = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POWER_FIELD, 0)))
    obj->light.power = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 0)))
    obj->light.dir.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 1)))
    obj->light.dir.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, DIR_FIELD, 2)))
    obj->light.dir.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, ANGLE_FIELD, 2)))
    obj->light.angle = my_getdouble(tmp);
}
