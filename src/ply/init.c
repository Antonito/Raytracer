/*
** init.c for init in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Apr 21 17:05:08 2016 Arthur ARNAUD
** Last update Sun Apr 24 19:13:31 2016 Arthur ARNAUD
*/

#include "ply.h"

int	init_info(t_ply_info *info)
{
  char	*tmp;

  if (!(tmp = my_strdup(LIST_ELEM)) ||
      !(info->list_elem = str_to_wordtab(LIST_ELEM, ' ')) || my_free(tmp) ||
      !(tmp = my_strdup(LIST_V_VAR)) ||
      !(info->list_v_var = str_to_wordtab(LIST_V_VAR, ' ')) || my_free(tmp) ||
      !(tmp = my_strdup(LIST_F_VAR)) ||
      !(info->list_f_var = str_to_wordtab(LIST_F_VAR, ' ')) || my_free(tmp) ||
      !(tmp = my_strdup(LIST_KEY)) ||
      !(info->list_key = str_to_wordtab(LIST_KEY, ' ')) || my_free(tmp))
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
