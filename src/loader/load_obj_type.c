/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Thu May 19 19:51:04 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"

void	load_torus(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = TORUS;
  obj->torus.radius_hole = DEFAULT_TORUS_RADIUS_HOLE;
  obj->torus.radius_solid = DEFAULT_TORUS_RADIUS_SOLID;
  obj->get_intersect = &get_intersect_tore;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_TORE_FIELD, 0)))
    obj->torus.radius_hole = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_TORE_FIELD2, 0)))
    obj->torus.radius_solid = my_getdouble(tmp);
  obj->box[0].x = -obj->torus.radius_solid- obj->torus.radius_hole;
  obj->box[0].y = obj->box[0].x;
  obj->box[0].z = -obj->torus.radius_solid;
  obj->box[1].x = -obj->box[0].x;
  obj->box[1].y = -obj->box[0].y;
  obj->box[1].z = -obj->box[0].z;
}

void	load_sphere(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = SPHERE;
  obj->sphere.radius = DEFAULT_SPHERE_RADIUS;
  obj->get_intersect = &get_intersect_sphere;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->sphere.radius = my_getdouble(tmp);
  obj->box[0].x = obj->box[0].y = obj->box[0].z = -obj->sphere.radius;
  obj->box[1].x = obj->box[1].y = obj->box[1].z = obj->sphere.radius;
}

void	load_plane(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = PLANE;
  obj->plane.normale = DEFAULT_PLANE_NORMALE;
  obj->get_intersect = &get_intersect_plane;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 0)))
    obj->plane.normale.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 1)))
    obj->plane.normale.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, NORMALE_FIELD, 2)))
    obj->plane.normale.z = my_getdouble(tmp);
  obj->plane.normale = vec3_normalize(obj->plane.normale);
  obj->box[0] = obj->box[1] = vec3(0, 0, 0);
}

void	load_cylinder(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = CYLINDER;
  obj->cylinder.radius = DEFAULT_CYLINDER_RADIUS;
  obj->cylinder.height = DEFAULT_CYLINDER_HEIGHT;
  obj->get_intersect = &get_intersect_cylinder;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->cylinder.radius = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->cylinder.height = my_getdouble(tmp);
  obj->box[0] = obj->box[1] = vec3(0, 0, 0);
}

void	load_cone(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = CONE;
  obj->cone.angle = DEFAULT_CONE_ANGLE;
  obj->cone.height = DEFAULT_CONE_HEIGHT;
  obj->get_intersect = &get_intersect_cone;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, RADIUS_FIELD, 0)))
    obj->cone.angle = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, HEIGHT_FIELD, 0)))
    obj->cone.height = my_getdouble(tmp);
  obj->cone.radius = tan(obj->cone.angle * M_PI / 360.0) *
    obj->cone.height;
  obj->cone.angle = tan(obj->cone.angle);
  obj->box[0] = obj->box[1] = vec3(0, 0, 0);
}
