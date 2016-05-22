/*
** load_obj_part_four.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 20:24:18 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_double_sphere(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = DOUBLE_SPHERE;
  obj->sphere.radius = DEFAULT_SPHERE_RADIUS;
  obj->get_intersect = &no_shape;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->sphere.radius = my_getdouble(tmp);
}

void	load_tooth(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = TOOTH;
  obj->get_intersect = &get_intersect_tooth;
}

void	load_heart(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = HEART;
  obj->get_intersect = &get_intersect_heart;
}

void	load_hunt(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = HUNT;
  obj->get_intersect = &get_intersect_hunt;
}

void	load_miter(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = MITER;
  obj->get_intersect = &get_intersect_miter;
}
