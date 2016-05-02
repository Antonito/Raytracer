/*
** init.c for init in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Apr 21 17:05:08 2016 Arthur ARNAUD
** Last update Mon May  2 17:36:46 2016 Arthur ARNAUD
*/

#include "ply.h"

int	set_tab(int *tab, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    tab[i] = -1;
  return (0);
}

int	init_info(t_ply_info *info)
{
  char	*tmp;

  if (set_tab(info->vertex_prop, NB_V_VAR) ||
      set_tab(info->face_prop, NB_F_VAR) ||
      !(tmp = my_strdup(LIST_ELEM)) ||
      !(info->list_elem = str_to_wordtab(tmp, ' ')) ||
      !(tmp = my_strdup(LIST_V_VAR)) ||
      !(info->list_v_var = str_to_wordtab(tmp, ' ')) ||
      !(tmp = my_strdup(LIST_F_VAR)) ||
      !(info->list_f_var = str_to_wordtab(tmp, ' ')) ||
      !(tmp = my_strdup(LIST_KEY)) ||
      !(info->list_key = str_to_wordtab(tmp, ' ')))
    return (1);
  return (0);
}

int	init_ply(t_ply *ply, t_ply_info *info)
{
  ply->nb_vertex = info->nb_vertex;
  ply->nb_face = info->nb_face;
  if (!(ply->list_vertex = my_malloc(sizeof(t_vertex) * ply->nb_vertex)) ||
      !(ply->list_face = my_malloc(sizeof(t_face) * ply->nb_face)))
    return (1);
  return (0);
}
