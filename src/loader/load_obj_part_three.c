/*
** load_obj_part_three.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 12:29:08 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

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
