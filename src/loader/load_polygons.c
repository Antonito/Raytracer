/*
** load_polygons.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 13 06:44:05 2016 Antoine Baché
** Last update Fri May 13 06:44:27 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_triangle(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = TRIANGLE;
  obj->get_intersect = &get_intersect_triangle;
  obj->triangle.pts[0] = DEFAULT_POLY_PTS0;
  obj->triangle.pts[1] = DEFAULT_POLY_PTS1;
  obj->triangle.pts[2] = DEFAULT_POLY_PTS2;
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_A, 0)))
    obj->triangle.pts[0].x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_A, 1)))
    obj->triangle.pts[0].y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_A, 2)))
    obj->triangle.pts[0].z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_B, 0)))
    obj->triangle.pts[1].x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_B, 1)))
    obj->triangle.pts[1].y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_B, 2)))
    obj->triangle.pts[1].z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_C, 0)))
    obj->triangle.pts[2].x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_C, 1)))
    obj->triangle.pts[2].y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(scope, POLY_PTS_C, 2)))
    obj->triangle.pts[2].z = my_getdouble(tmp);
}
