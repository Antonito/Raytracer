/*
** load_obj_part_two.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 20:56:27 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_boy(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = BOY;
  obj->get_intersect = &no_shape;
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
