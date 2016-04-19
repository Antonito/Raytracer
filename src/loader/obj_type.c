/*
** obj_type.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 23:15:28 2016 Ludovic Petrenko
** Last update Tue Apr 19 01:50:05 2016 Ludovic Petrenko
*/

#include "raytracer.h"

void		load_obj_spec(t_obj *obj, t_bunny_ini_scope *scope)
{
  static char	*types[] = {"sphere", "plane", "cylinder", "cone"};
  static void	(*loader[])(t_obj *, t_bunny_ini_scope *) =
    {&load_sphere, &load_plane, &load_cylinder, &load_cone};
  int		i;

  i = 0;
  while (i < NB_OBJ_TYPE - SPHERE)
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

void	        load_light_spec(t_obj *obj, t_bunny_ini_scope *scope)
{
  static char	*types[] = {"point", "directionnal", "spot"};
  static void	(*loader[])(t_obj *, t_bunny_ini_scope *) =
    {&load_point, &load_directionnal, &load_spot};
  int		i;

  i = 0;
  obj->type = LIGHT;
  while (i < NB_LIGHT_TYPE)
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
