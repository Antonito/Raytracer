/*
** fill_ply.c for fill_ply in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Mon Apr 25 00:37:50 2016 Arthur ARNAUD
** Last update Mon Apr 25 03:21:12 2016 Arthur ARNAUD
*/

#include "ply.h"

int	count_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

int	fill_face(t_ply *ply,
		  t_ply_info *info,
		  int fd)
{
  int	i;
  char	*str;
  char	**tab;

  while ((str = get_next_line(fd)) != NULL && ++i < info->nb_vertex)
    {
      if (!(tab = str_to_wordtab(str, ' ')) && count_tab(tab) < NB_V_VAR)
	return (1);
    }
}

int	fill_vertex(t_ply *ply,
		 t_ply_info *info,
		 int fd)
{
  int	i;
  char	*str;
  char	**tab;

  while ((str = get_next_line(fd)) != NULL && ++i < info->nb_vertex)
    {
      if (!(tab = str_to_wordtab(str, ' ')) && count_tab(tab) < NB_V_VAR)
	return (1);
      ply->list_vertex[i].vec.x = (info->vertex_prop[V_X] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_X]]);
      ply->list_vertex[i].vec.y = (info->vertex_prop[V_Y] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_Y]]);
      ply->list_vertex[i].vec.z = (info->vertex_prop[V_Z] == -1) ? 0 :
	my_getdouble(tab[info->vertex_prop[V_Z]]);
      ply->list_vertex[i].color.argb[0] = (info->vertex_prop[V_RED] == -1)
	? 0 : (unsigned char)my_getnbr(tab[info->vertex_prop[V_RED]]);
      ply->list_vertex[i].color.argb[1] = (info->vertex_prop[V_BLUE] == -1)
	? 0 : (unsigned char)my_getnbr(tab[info->vertex_prop[V_BLUE]]);
      ply->list_vertex[i].color.argb[2] = (info->vertex_prop[V_GREEN] == -1)
	? 0 : (unsigned char)my_getnbr(tab[info->vertex_prop[V_GREEN]]);
      ply->list_vertex[i].color.argb[3] = (info->vertex_prop[V_ALPHA] == -1)
	? 0 :(unsigned char)my_getnbr(tab[info->vertex_prop[V_ALPHA]]);
      printf("%f/%s  %f/%s  %f/%s %d %d %d %d\n", ply->list_vertex[i].vec.x,
	     tab[info->vertex_prop[V_X]],
	     ply->list_vertex[i].vec.y,
	     tab[info->vertex_prop[V_Y]],
	     ply->list_vertex[i].vec.z,
	     tab[info->vertex_prop[V_Z]],
	     ply->list_vertex[i].color.argb[0],
	     ply->list_vertex[i].color.argb[1],
	     ply->list_vertex[i].color.argb[2],
	     ply->list_vertex[i].color.argb[3]);
    }
}

int	fill_ply(t_ply *ply,
		  t_ply_info *info,
		  int fd)
{
  if (fill_vertex(ply, info, fd) || fill_face(ply, info, fd))
    return (1);
  return (0);
}
