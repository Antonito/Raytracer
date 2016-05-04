/*
** obj_type.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 23:15:28 2016 Ludovic Petrenko
** Last update Mon May  2 23:06:22 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

void		load_obj_spec(t_obj *obj, const t_bunny_ini_scope *scope)
{
  static char	*types[] = {"sphere", "plane", "cylinder", "cone"};
  static void	(*loader[])(t_obj *, const t_bunny_ini_scope *) =
    {&load_sphere, &load_plane, &load_cylinder, &load_cone};
  int		i;
  char		*type;

  i = 0;
  type = (char *)bunny_ini_scope_get_field(scope, "type", 0);
  while (i < NB_OBJ_TYPE - SPHERE && type)
    {
      if (!my_strcmp(type, types[i]))
	{
	  loader[i](obj, scope);
	  return ;
	}
      i++;
    }
  loader[0](obj, scope);
}

void	        load_light_spec(t_obj *obj, const t_bunny_ini_scope *scope)
{
  static char	*types[] = {"point", "directionnal", "spot"};
  static void	(*loader[])(t_obj *, const t_bunny_ini_scope *) =
    {&load_point, &load_directionnal, &load_spot};
  int		i;
  const char	*type;

  i = 0;
  type = bunny_ini_scope_get_field(scope, "type", 0);
  obj->type = LIGHT;
  obj->get_intersect = &get_intersect_sphere;
  while (i < NB_LIGHT_TYPE && type)
    {
      if (!my_strcmp(type, types[i]))
	{
	  loader[i](obj, scope);
	  return ;
	}
      i++;
    }
  loader[0](obj, scope);
}
