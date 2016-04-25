/*
** check_var.c for check_var in /info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Apr 22 13:20:37 2016 Arthur ARNAUD
** Last update Mon Apr 25 00:18:44 2016 Arthur ARNAUD
*/

#include "ply.h"

int	check_vertex_var(char **components, char **list)
{
  int	index;

  index = 0;
  if ((index = is_in_tab(components[VALUE], list)) == -1 ||
      (index < V_RED && my_strcmp(components[TYPE], COORD_TYPE)) ||
      (index > V_Z && my_strcmp(components[TYPE], COLOR_TYPE)))
    return (1);
  return (index);
}

int	check_face_var(char **components, char **list, int size)
{
  int	index;

  index = 0;
  if (size == 4 && (my_strcmp(components[TYPE], "list") ||
		    (index = is_in_tab(components[4], list)) == -1))
    return (1);
  if (size == 2 && ((index = is_in_tab(components[VALUE], list)) == -1 ||
		    (index > F_TEXNUMBER && my_strcmp(components[TYPE], COLOR_TYPE))))
    return (1);
  return (index);
}
