/*
** load_obj.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 20:37:43 2016 Ludovic Petrenko
** Last update Sun May 22 23:03:32 2016 Arthur ARNAUD
*/

#include <unistd.h>
#include "raytracer.h"
#include "tools/str.h"
#include "loader.h"

void	load_obj_basics(t_obj *obj, const t_bunny_ini_scope *s)
{
  char	*tmp;

  obj->pos = vec3(0, 0, 0);
  obj->rot = vec3(0, 0, 0);
  if ((tmp = (char *)bunny_ini_scope_get_field(s, POS_FIELD, 0)))
    obj->pos.x = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(s, POS_FIELD, 1)))
    obj->pos.y = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(s, POS_FIELD, 2)))
    obj->pos.z = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_scope_get_field(s, ROT_FIELD, 0)))
    obj->rot.x = my_getdouble(tmp) * M_PI / 180.0;
  if ((tmp = (char *)bunny_ini_scope_get_field(s, ROT_FIELD, 1)))
    obj->rot.y = my_getdouble(tmp) * M_PI / 180.0;
  if ((tmp = (char *)bunny_ini_scope_get_field(s, ROT_FIELD, 2)))
    obj->rot.z = my_getdouble(tmp) * M_PI / 180.0;
  obj->tex = NULL;
  if ((tmp = (char *)bunny_ini_scope_get_field(s, TEX_FIELD, 0)))
    obj->tex = bunny_load_pixelarray(tmp);
  obj->next = obj + 1;
}

void		load_obj_data(t_scene *scene, t_obj *obj,
			      const t_bunny_ini_scope *scope)
{
  const char	*tmp;

  obj->mat = NULL;
  if ((tmp = bunny_ini_scope_get_field(scope, MAT_FIELD, 0)))
    obj->mat = get_material(scene->mat, scene->nb_mat, tmp);
  load_obj_spec(obj, scope);
}

int			load_objs(t_scene *scene, t_obj *obj,
				  const t_bunny_ini *ini)
{
  t_bunny_ini_scope	*scope;
  const char		*scope_name;
  int			i[2];

  if (!(i[0] = i[1] = 0) && !(scope = bunny_ini_first((t_bunny_ini *)ini)))
    return (1);
  while ((scope = bunny_ini_next((t_bunny_ini *)ini, scope)))
    if ((scope_name = bunny_ini_scope_name(ini, scope)) &&
	!my_strncmp(scope_name, OBJ_PREFIX, 4))
      {
	load_obj_basics(obj + i[0], scope);
	load_obj_data(scene, obj + i[0], scope);
	++i[0];
      }
    else if (scope_name && !my_strncmp(scope_name, LIGHT_PREFIX, 6))
      {
	load_obj_basics(obj + i[0], scope);
	load_light_spec(obj + i[0]++, scope);
	load_obj_basics(scene->lights + i[1], scope);
	load_light_spec(scene->lights + i[1]++, scope);
      }
  if (!i[0])
    return (write(2, "Incorrect ini file\n", 19));
  obj[i[0] - 1].next = NULL;
  return (0);
}
