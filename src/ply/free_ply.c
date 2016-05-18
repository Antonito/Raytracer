/*
** free_ply.c for free_ply in /home/arnaud_e/rendu/info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Thu Apr 28 09:55:44 2016 Arthur ARNAUD
** Last update Sun May 15 15:20:01 2016 Antoine Baché
*/

#include "ply.h"
#include "tools/memory.h"

void	free_ply_info(t_ply_info *info)
{
  my_free(info->list_elem);
  my_free(info->list_v_var);
  my_free(info->list_f_var);
  my_free(info->list_key);
  my_free(info);
  info = NULL;
}

void	free_ply(t_ply *ply)
{
  int	i;

  i = -1;
  while (++i < ply->nb_face - 1)
    {
      if (ply->list_face[i].face)
  	my_free(ply->list_face[i].face);
      if (ply->list_face[i].texcoord)
  	my_free(ply->list_face[i].texcoord);
    }
  my_free(ply->list_face);
  my_free(ply->list_vertex);
  my_free(ply);
  ply = NULL;
}
