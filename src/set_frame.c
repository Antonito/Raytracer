/*
** set_frame.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  2 22:15:55 2016 Ludovic Petrenko
** Last update Sun May  8 04:32:16 2016 Ludovic Petrenko
*/

#include "raytracer.h"

#include <stdio.h>

void		refresh_size(t_data *data, int frame)
{
  double	ratio;

  ratio = MINIMUM_FPS / (double)frame;
  data->cur_width = (int)(data->cur_width / ratio);
  data->cur_width = (data->cur_width > 0) ? data->cur_width : 1;
  data->cur_width = (data->cur_width < data->width) ? data->cur_width : data->width;
  data->cur_height = data->cur_width * data->height / data->width;
  data->cur_height = (data->cur_height > 0) ? data->cur_height : 1;
  printf("\r%d %d %f                  ", data->cur_width, data->cur_height, ratio);
  fflush(stdout);
}

int		set_frame(t_data *data)
{
  t_ivec2	pos[8];

  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = data->cur_width;
  pos[1].y = data->cur_height;
  set_vectors(data, &data->scene->cam);
  calc_fragment(data, (unsigned int *)data->scene->cache->pixels, pos);
  return (0);
}
