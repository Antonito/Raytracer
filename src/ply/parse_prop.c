/*
** parse_prop.c for parse_prop in gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue Apr 26 15:35:12 2016 Arthur ARNAUD
** Last update Sun May 22 12:58:01 2016 Ludovic Petrenko
*/

#include "ply.h"
#include "tools/str.h"
#include "tools/memory.h"

int	*add_list_face(char **tab, int *j, int *nb, int count)
{
  int	*list_prop ;
  int	i;

  if ((*nb = my_getnbr(tab[*j + F_VERTICES_INDICES])) <= 0 ||
      *nb + *j + F_VERTICES_INDICES >= count ||
      !(list_prop = my_malloc(sizeof(int) * (*nb))))
    return (NULL);
  i = -1;
  while (++i < *nb)
    {
      list_prop[i] = my_getnbr(tab[*j + F_VERTICES_INDICES + 1 + i]);
    }
  *j += *nb;
  return (list_prop);
}

double		*add_list_texcoord(char **tab, int *j, int *nb, int count)
{
  double	*list_prop ;
  int		i;

  if ((*nb = my_getnbr(tab[*j + F_TEXCOORD])) <= 0 ||
      *nb + *j + F_TEXCOORD >= count ||
      !(list_prop = my_malloc(sizeof(double) * (*nb))))
    return (NULL);
  i = -1;
  while (++i < *nb)
    {
      list_prop[i] = my_getdouble(tab[*j + F_TEXCOORD + 1 + i]);
    }
  *j += *nb ;
  return (list_prop);
}

int	parse_color_face(t_color *color, char **tab, int *face_prop, int dec)
{
  if (F_ALPHA + dec >= count_prop(face_prop, NB_F_VAR))
    return (1);
  color->argb[0] = (face_prop[F_RED] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[face_prop[F_RED] + dec]);
  color->argb[1] = (face_prop[F_GREEN] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[face_prop[F_GREEN] + dec]);
  color->argb[2] = (face_prop[F_BLUE] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[face_prop[F_BLUE] + dec]);
  color->argb[3] = (face_prop[F_ALPHA] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[face_prop[F_ALPHA] + dec]);
  return (0);
}

int	parse_color_vertex(t_color *color, char **tab, int *vertex_prop,
			   bool *get_color)
{
  if (vertex_prop[V_RED] == -1 || vertex_prop[V_GREEN] == -1 ||
      vertex_prop[V_BLUE] == -1)
    *get_color = false;
  else
    *get_color = true;
  color->argb[0] = (vertex_prop[V_RED] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[vertex_prop[V_RED]]);
  color->argb[1] = (vertex_prop[V_GREEN] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[vertex_prop[V_GREEN]]);
  color->argb[2] = (vertex_prop[V_BLUE] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[vertex_prop[V_BLUE]]);
  color->argb[3] = (vertex_prop[V_ALPHA] == -1)
    ? 0 : (unsigned char)my_getnbr(tab[vertex_prop[V_ALPHA]]);
  return (0);
}
