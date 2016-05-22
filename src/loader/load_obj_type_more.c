/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Sun May 22 12:23:43 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_void_cube(t_obj *obj, const t_bunny_ini_scope *scope)
{
  obj->type = VOID_CUBE;
  obj->get_intersect = &get_intersect_void_cube;
  (void)scope;
}

void	load_mobius(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = MOBIUS;
  obj->get_intersect = &get_intersect_mobius;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->mobius.radius = my_getdouble(tmp);
}

void	load_klein(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = KLEIN;
  obj->box[0] = vec3(-3.5, -3.5, -3.5);
  obj->box[1] = vec3(3.5, 3.5, 3.5);
  obj->get_intersect = &get_intersect_klein;
}

void	load_hyperbola(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = HYPERBOLA;
  obj->get_intersect = &get_intersect_hyperbola;
  obj->hyperbola.length = DEFAULT_HYPERBOLA_HEIGHT;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->hyperbola.length = my_getdouble(tmp);
}

void	load_ellipsoid(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = ELLIPSOID;
  obj->get_intersect = &get_intersect_ellipsoid;
  obj->ellipsoid.height = DEFAULT_ELLIPSOID_HEIGHT;
  obj->ellipsoid.length = DEFAULT_ELLIPSOID_LENGTH;
  obj->ellipsoid.width = DEFAULT_ELLIPSOID_WIDTH;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->ellipsoid.height = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, LENGTH_FIELD, 0)))
    obj->ellipsoid.length = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, WIDTH_FIELD, 0)))
    obj->ellipsoid.width = my_getdouble(tmp);
}
