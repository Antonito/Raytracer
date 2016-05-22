/*
** load_obj_part_seven.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 12:23:05 2016 Antoine Baché
** Last update Sun May 22 13:24:32 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/str.h"
#include "engine/vector.h"
#include "engine/object.h"

void	load_cushion(t_obj *obj, const t_bunny_ini_scope *scope)
{
  (void)scope;
  obj->type = CUSHION;
  obj->get_intersect = &get_intersect_cushion;
}
