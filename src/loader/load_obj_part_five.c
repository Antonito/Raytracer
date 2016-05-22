/*
** load_obj_part_five.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 20:26:17 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

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
  obj->get_intersect = &no_shape;
}

void	load_enneper(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = ENNEPER;
  obj->get_intersect = &no_shape;
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
