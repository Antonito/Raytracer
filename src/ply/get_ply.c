/*
** get_ply.c for get_ply in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Apr 20 09:34:34 2016 Arthur ARNAUD
** Last update Sun Apr 24 16:55:55 2016 Arthur ARNAUD
*/

#include "ply.h"
#include <stdio.h>

t_ply	*get_ply(char *name)
{
  int		fd;
  t_ply_info	*info;
  t_ply		*ply;

  if ((fd = open(name, O_RDONLY)) == -1 ||
      !(info = malloc(sizeof(t_ply_info *))) ||
      init_info(info) ||
      read_header(fd, info) ||
      !(ply = malloc(sizeof(t_ply *))) ||
      init_ply(ply, info))
    return (NULL);
  printf("nb_vertex = %d\n", info->nb_vertex);
  printf("nb_face = %d\n", info->nb_face);
  printf("============ VERTEX ============\n");
  printf("v_x = %d\n", info->vertex_prop[V_X]);
  printf("v_y = %d\n", info->vertex_prop[V_Y]);
  printf("v_z = %d\n", info->vertex_prop[V_Z]);
  printf("v_red = %d\n", info->vertex_prop[V_RED]);
  printf("v_green = %d\n", info->vertex_prop[V_GREEN]);
  printf("v_blue = %d\n", info->vertex_prop[V_BLUE]);
  printf("v_alpha = %d\n", info->vertex_prop[V_ALPHA]);
  printf("v_confidence = %d\n", info->vertex_prop[V_CONFIDENCE]);
  printf("v_intensity = %d\n", info->vertex_prop[V_INTENSITY]);
  printf("============ FACE ============\n");
  printf("f_x = %d\n", info->face_prop[F_VERTICES_INDICES]);
  printf("f_y = %d\n", info->face_prop[F_TEXCOORD]);
  printf("f_z = %d\n", info->face_prop[F_TEXNUMBER]);
  printf("f_red = %d\n", info->face_prop[F_RED]);
  printf("f_green = %d\n", info->face_prop[F_GREEN]);
  printf("f_blue = %d\n", info->face_prop[F_BLUE]);
  printf("f_alpha = %d\n", info->face_prop[F_ALPHA]);
  return (ply);
}
