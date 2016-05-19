/*
** obj_type.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 23:15:28 2016 Ludovic Petrenko
** Last update Thu May 19 02:34:10 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

void		load_obj_spec(t_obj *obj, const t_bunny_ini_scope *scope)
{
  static char	*types[] =
    {"sphere", "plane", "cylinder", "cone", "triangle", "torus", "mobius",
     "void_cube", "klein", "hyperbola", "ellipsoid", "ply", "boy", "cassini",
     "chair", "kusner", "tritrumpet", "whitney", "tetrahedral", "barth_sextic",
     "bifolia", "duplin", "cushion", "double_sphere", "tooth", "heart",
     "hunt", "miter", "kiss", "kummer", "enneper", "bohemian_dome",
     "bohemian_star", "c8", "chubs", "devil", "quartic_cylinder", "spheroid"};
  static void	(*loader[])(t_obj *, const t_bunny_ini_scope *) =
    {load_sphere, load_plane, load_cylinder, load_cone, load_triangle,
     load_torus, load_mobius, load_void_cube, load_klein, load_hyperbola,
     load_ellipsoid, load_ply, load_boy, load_cassini, load_chair, load_kusner,
     load_tritrumpet, load_whitney, load_tetrahedral, load_barth_sextic,
     load_bifolia, load_duplin, load_cushion, load_double_sphere,
     load_tooth, load_heart, load_hunt, load_miter, load_kiss, load_kummer,
     load_enneper, load_bohemian_dome, load_bohemian_star, load_c8, load_chubs,
     load_devil, load_quartic_cylinder, load_spheroid};
  int		i;
  char		*type;

  i = -1;
  type = (char *)bunny_ini_scope_get_field(scope, "type", 0);
  while (++i < NB_OBJ_TYPE - SPHERE && type)
    if (!my_strcmp(type, types[i]))
      {
	loader[i](obj, scope);
	return ;
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
  obj->get_intersect = &get_intersect_light;
  obj->mat = NULL;
  while (i < NB_LIGHT_TYPE && type)
    {
      if (!my_strcmp(type, types[i]))
	{
	  loader[i](obj, scope);
	  return ;
	}
      ++i;
    }
  loader[0](obj, scope);
}
