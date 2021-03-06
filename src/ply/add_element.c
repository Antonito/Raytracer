/*
** add_element.c for add_element in info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Apr 20 19:14:10 2016 Arthur ARNAUD
** Last update Sun May 15 15:20:54 2016 Antoine Baché
*/

#include "ply.h"
#include "tools/str.h"

int	add_element(char **components,
		    int *elem,
		    int *nb_prop,
		    t_ply_info *info)
{
  int	i;
  i = -1;
  while (components[++i]);
  i--;
  if (i < 2 || (*elem = is_in_tab(components[TYPE], info->list_elem)) == -1 ||
      ((*nb_prop = 0)) ||
      (*elem == VERTEX && (info->nb_vertex =
			   my_getnbr(components[VALUE])) < 0) ||
      (*elem == FACE && (info->nb_face =
			 my_getnbr(components[VALUE])) < 0))
    return (1);
  return (0);
}

int	add_property(char **components,
		     int elem,
		     int *nb_prop,
		     t_ply_info *info)
{
  int	index;
  int	i;

  i = -1;
  index = 0;
  while (components[++i]);
  i--;
  if (i < 2 || elem == NO_ELEM)
    return (1);
  if (elem == VERTEX)
    {
      if ((index = check_vertex_var(components, info->list_v_var)) == -1 ||
	  (info->vertex_prop[index] = *nb_prop) == -1)
	return (1);
    }
  else if (elem == FACE)
    {
      if ((index = check_face_var(components, info->list_f_var, i)) == -1 ||
	  ((info->face_prop[index] = *nb_prop) == -1))
	return (1);
    }
  (*nb_prop)++;
  return (0);
}
