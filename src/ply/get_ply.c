/*
** get_ply.c for get_ply in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Apr 20 09:34:34 2016 Arthur ARNAUD
** Last update Mon May  2 17:40:31 2016 Arthur ARNAUD
*/

#include "ply.h"
#include <stdio.h>

t_ply	*get_ply(char *name)
{
  int		fd;
  t_ply_info	*info;
  t_ply		*ply;

  if ((fd = open(name, O_RDONLY)) == -1 ||
      !(info = my_malloc(sizeof(t_ply_info))) ||
      init_info(info) ||
      read_header(fd, info) ||
      !(ply = my_malloc(sizeof(t_ply))) ||
      init_ply(ply, info) ||
      fill_ply(ply, info, fd))
    return (NULL);
  free_ply_info(info);
  return (ply);
}
