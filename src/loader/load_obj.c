/*
** load_obj.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 20:37:43 2016 Ludovic Petrenko
** Last update Tue Apr 19 22:34:13 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "tools/str.h"
#include "loader.h"

void		load_obj_basics(t_obj *obj, const t_bunny_ini_scope *s)
{
  const char	*tmp;

  if ((tmp = bunny_ini_scope_get_field(s, "position", 0)))
    obj->pos.x = my_getdouble(tmp);
  if ((tmp = bunny_ini_scope_get_field(s, "position", 1)))
    obj->pos.y = my_getdouble(tmp);
  if ((tmp = bunny_ini_scope_get_field(s, "position", 2)))
    obj->pos.z = my_getdouble(tmp);
  if ((tmp = bunny_ini_scope_get_field(s, "rotation", 0)))
    obj->rot.x = my_getdouble(tmp);
  if ((tmp = bunny_ini_scope_get_field(s, "rotation", 1)))
    obj->rot.y = my_getdouble(tmp);
  if ((tmp = bunny_ini_scope_get_field(s, "rotation", 2)))
    obj->rot.z = my_getdouble(tmp);
}

void		load_obj_data(t_scene *scene, t_obj *obj,
			      const t_bunny_ini_scope *scope)
{
  const char	*tmp;

  obj->mat = scene->mat;
  if ((tmp = bunny_ini_scope_get_field(scope, "material", 0)))
    obj->mat = get_material(scene->mat, scene->nb_mat, tmp);
  load_obj_spec(obj, scope);
}

void	load_objs(t_scene *scene, t_obj *obj, const t_bunny_ini *ini)
{
  t_bunny_ini_scope	*scope;
  const char		*scope_name;
  int			i;

  i = 0;
  if (!(scope = bunny_ini_first((t_bunny_ini *)ini)))
    return ;
  while ((scope = bunny_ini_next((t_bunny_ini *)ini, scope)))
    {
      scope_name = bunny_ini_scope_name(ini, scope);
      if (scope_name && !my_strncmp(scope_name, "obj_", 4))
	{
	  load_obj_basics(obj + i, scope);
	  load_obj_data(scene, obj + i, scope);
	  i++;
	}
      else if (scope_name && !my_strncmp(scope_name, "light_", 6))
	{
	  load_obj_basics(obj + i, scope);
	  load_light_spec(obj + i, scope);
	  i++;
	}
    }
}
