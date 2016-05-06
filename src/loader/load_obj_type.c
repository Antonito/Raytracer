/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Wed May  4 19:13:13 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"

void	load_sphere(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = SPHERE;
  obj->spec.sphere.radius = DEFAULT_SPHERE_RADIUS;
  obj->get_intersect = &get_intersect_sphere;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->spec.sphere.radius = my_getdouble(tmp);
}

void	load_plane(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = PLANE;
  obj->spec.plane.normale = DEFAULT_PLANE_NORMALE;
  obj->get_intersect = &get_intersect_plane;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 0)))
    obj->spec.plane.normale.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 1)))
    obj->spec.plane.normale.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 2)))
    obj->spec.plane.normale.z = my_getdouble(tmp);
  obj->spec.plane.normale = vec3_normalize(obj->spec.plane.normale);
}

void	load_cylinder(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = CYLINDER;
  obj->spec.cylinder.radius = DEFAULT_CYLINDER_RADIUS;
  obj->spec.cylinder.height = DEFAULT_CYLINDER_HEIGHT;
  obj->get_intersect = &get_intersect_cylinder;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->spec.cylinder.radius = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->spec.cylinder.height = my_getdouble(tmp);
}

void	load_cone(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = CONE;
  obj->spec.cone.angle = DEFAULT_CONE_ANGLE;
  obj->spec.cone.height = DEFAULT_CONE_HEIGHT;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->spec.cone.angle = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->spec.cone.height = my_getdouble(tmp);
  obj->spec.cone.radius = tan(obj->spec.cone.angle * M_PI / 360.0) *
    obj->spec.cone.height;
}
