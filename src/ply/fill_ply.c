/*
** fill_ply.c for fill_ply in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Apr 25 00:37:50 2016 Arthur ARNAUD
** Last update Sun May 15 18:07:03 2016 Antoine Baché
*/

#include "ply.h"
#include "tools/get_next_line.h"
#include "tools/str.h"
#include "tools/memory.h"

static int	count_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i]);
  return (i);
}

int		count_prop(const int * const list_prop, int nb)
{
  int		i;
  int		j;

  j = 0;
  i = -1;
  while (++i < nb)
    if (list_prop[i] != -1)
      j++;
  return (j);
}

int		fill_face(t_ply *ply, t_ply_info *info, int fd)
{
  int		i;
  int		j;
  int		count;
  int		size;
  char		*str;
  char		**tab;

  i = -1;
  count = count_prop(info->face_prop, NB_F_VAR);
  while (++i < info->nb_face && (str = get_next_line(fd)))
    {
      j = 0;
      if (!(tab = str_to_wordtab(str, ' ')) || (size = count_tab(tab)) < count)
	return (1);
      ply->list_face[i].face =
	(info->face_prop[F_VERTICES_INDICES] == -1)
	? NULL : add_list_face(tab, &j, &ply->list_face[i].nb_face, size);
      ply->list_face[i].texcoord = (info->face_prop[F_TEXCOORD] == -1)
	? NULL : add_list_texcoord(tab, &j, &ply->list_face[i].nb_tex ,size);
      ply->list_face[i].texnumber = (info->face_prop[F_TEXNUMBER] == -1)
	? 0 : (F_TEXNUMBER + j >= size)
	? 0 : my_getnbr(tab[info->face_prop[F_TEXNUMBER] + j]);
      my_free(tab);
      my_free(str);
    }
  return (0);
}

int	fill_vertex(t_ply *ply,
		 t_ply_info *info,
		 int fd)
{
  int	i;
  char	*str;
  char	**tab;

  i = -1;
  while (++i < info->nb_vertex && (str = get_next_line(fd)))
    {
      if (!(tab = str_to_wordtab(str, ' ')) ||
	  count_tab(tab) < count_prop(info->vertex_prop, NB_V_VAR))
	return (1);
      ply->list_vertex[i].vec.x = (info->vertex_prop[V_X] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_X]]);
      ply->list_vertex[i].vec.y = (info->vertex_prop[V_Y] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_Y]]);
      ply->list_vertex[i].vec.z = (info->vertex_prop[V_Z] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_Z]]);
      if (parse_color_vertex
	  (&ply->list_vertex[i].color, tab, info->vertex_prop))
	return (1);
      my_free(tab);
      my_free(str);
    }
  return (0);
}

int	fill_ply(t_ply *ply,
		  t_ply_info *info,
		  int fd)
{
  if (fill_vertex(ply, info, fd) || fill_face(ply, info, fd))
    return (1);
  return (0);
}
