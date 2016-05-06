/*
1;4401;0c** set_frame.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  2 22:15:55 2016 Ludovic Petrenko
** Last update Fri May  6 15:54:12 2016 Ludovic Petrenko
*/

#include "raytracer.h"

int		set_frame(t_data *data)
{
  t_ivec2	pos[8];

  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = data->width;
  pos[1].y = data->height;
  set_vectors(data, &data->scene->cam);
  calc_fragment(data, (unsigned int *)data->scene->cache->pixels, pos);
  bunny_blit(&data->win->buffer, &data->scene->cache->clipable, NULL);
  bunny_display(data->win);
  return (0);
}
