/*
** load_obj_part_six.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 13:21:40 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_c8(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = C8;
  obj->get_intersect = &get_intersect_c8;
}

void	load_chubs(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = CHUBS;
  obj->get_intersect = &get_intersect_chubs;
}

void	load_devil(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = DEVIL;
  obj->get_intersect = &get_intersect_devil;
}

void	load_quartic_cylinder(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = QUARTIC_CYLINDER;
  obj->get_intersect = &get_intersect_quartic_cylinder;
}

#pragma message("Spheroid a implementer")
void	load_spheroid(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = SPHEROID;
  obj->spheroid.radius = DEFAULT_SPHEROID_RADIUS;
  obj->spheroid.height = DEFAULT_SPHEROID_HEIGHT;
  obj->get_intersect = &get_intersect_spheroid;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->spheroid.radius = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->spheroid.height = my_getdouble(tmp);
}
