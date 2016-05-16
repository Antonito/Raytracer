/*
** load_obj_types.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 01:06:07 2016 Ludovic Petrenko
** Last update Mon May 16 02:50:01 2016 Antoine Baché
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

void	load_bifolia(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BIFOLIA;
  obj->get_intersect = &get_intersect_bifolia;
}

void	load_duplin(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = DUPLIN;
  obj->get_intersect = &get_intersect_duplin;
}

void	load_cushion(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = DUPLIN;
  obj->get_intersect = &get_intersect_cushion;
}

void	load_double_sphere(t_obj *obj, const t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->type = DOUBLE_SPHERE;
  obj->sphere.radius = DEFAULT_SPHERE_RADIUS;
  obj->get_intersect = &get_intersect_double_sphere;
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

void	load_kiss(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = KISS;
  obj->get_intersect = &get_intersect_kiss;
}

void	load_kummer(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = KUMMER;
  obj->get_intersect = &get_intersect_kummer;
}

void	load_enneper(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = ENNEPER;
  obj->get_intersect = &get_intersect_enneper;
}

void	load_bohemian_dome(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BOHEMIAN_DOME;
  obj->get_intersect = &get_intersect_bohemian_dome;
}

void	load_bohemian_star(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BOHEMIAN_DOME;
  obj->get_intersect = &get_intersect_bohemian_star;
}

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
