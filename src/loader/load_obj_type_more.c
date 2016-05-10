/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Tue May 10 08:29:45 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_triangle(t_obj *obj, const t_bunny_ini_scope *scope)
{
  /* char	*tmp; */

  /* obj->type = TRIANGLE; */
  /* obj->get_intersect = &get_intersect_triangle; */
  /* obj->triangle.poly[0] = DEFAULT_POLY_VEC0; */
  /* obj->triangle.poly[1] = DEFAULT_POLY_VEC1; */
  /* obj->triangle.poly[2] = DEFAULT_POLY_VEC2; */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE0, 0))) */
  /*   obj->triangle.poly[0].x = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE0, 1))) */
  /*   obj->triangle.poly[0].y = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE0, 2))) */
  /*   obj->triangle.poly[0].z = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE1, 0))) */
  /*   obj->triangle.poly[1].x = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE1, 1))) */
  /*   obj->triangle.poly[1].y = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE1, 2))) */
  /*   obj->triangle.poly[1].z = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE2, 0))) */
  /*   obj->triangle.poly[2].x = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE2, 1))) */
  /*   obj->triangle.poly[2].y = my_getdouble(tmp); */
  /* if ((tmp = (char *)bunny_ini_scope_get_field(scope, VECTOR_TRIANGLE2, 2))) */
  /*   obj->triangle.poly[2].z = my_getdouble(tmp); */
}

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
  char	*tmp;

  obj->type = KLEIN;
  obj->get_intersect = &get_intersect_klein;
}
