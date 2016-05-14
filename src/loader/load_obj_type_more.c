/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Sat May 14 23:03:52 2016 Antoine Baché
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

void	load_boy(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BOY;
  obj->get_intersect = &get_intersect_boy;
}

void	load_cassini(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = CASSINI;
  obj->get_intersect = &get_intersect_cassini;
}

void	load_chair(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = CHAIR;
  obj->get_intersect = &get_intersect_chair;
}

void	load_kusner(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = KUSNER;
  obj->get_intersect = &get_intersect_kusner;
}

void	load_tritrumpet(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = TRITRUMPET;
  obj->get_intersect = &get_intersect_tritrumpet;
}

void	load_whitney(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = WHITNEY;
  obj->get_intersect = &get_intersect_whitney;
}

void	load_tetrahedral(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = TETRAHEDRAL;
  obj->get_intersect = &get_intersect_tetrahedral;
}

void	load_barth_sextic(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BARTH_SEXTIC;
  obj->get_intersect = &get_intersect_barth_sextic;
}
