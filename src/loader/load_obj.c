/*
** load_obj.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 20:37:43 2016 Ludovic Petrenko
** Last update Tue Apr 19 01:03:24 2016 Ludovic Petrenko
*/

#include "raytracer.h"

void	load_obj_basics(t_object *obj, t_bunny_ini_scope *s)
{
  char	*tmp;

  if (tmp = (char *)bunny_ini_scope_get_field(s, "position", 0))
    obj->pos.x = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(s, "position", 1))
    obj->pos.y = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(s, "position", 2))
    obj->pos.z = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(s, "rotation", 0))
    obj->rot.x = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(s, "rotation", 1))
    obj->rot.y = my_getdouble(tmp);
  if (tmp = (char *)bunny_ini_scope_get_field(s, "rotation", 2))
    obj->rot.z = my_getdouble(tmp);
}

void	load_obj_data(t_scene *scene, t_object *obj, t_bunny_ini_scope *scope)
{
  char	*tmp;

  obj->mat = scene->mat;
  if (tmp = (char *)bunny_ini_scope_get_field(s, "material", 0))
    obj->mat = get_material(scene->mat, tmp);
  load_obj_spec(obj, scope);
}

void	load_objs(t_scene *scene, t_obj *obj, t_bunny_ini *ini)
{
  t_bunny_ini_scope	*scope;
  char			*scope_name;
  int			i;

  i = 0;
  if (!(scope = bunny_ini_first(ini)))
    return (0);
  while (!(scope = bunny_ini_next(ini, scope)))
    {
      scope_name = (char *)bunny_ini_scope_name(ini, scope);
      if (!scope_name && !my_strncmp(scope_name, "obj_", 4))
	{
	  load_obj_basic(obj + i, scope);
	  load_obj_data(scene, obj + i, scope);
	  i++;
	}
      else if (!scope_name && !my_strncmp(scope_name, "light_", 6))
	{
	  load_obj_basic(obj + i, scope);
	  load_light_spec(obj + i, scope);
	  i++;
	}
    }
  return (0);
}
