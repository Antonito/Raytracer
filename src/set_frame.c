/*
** set_frame.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  2 22:15:55 2016 Ludovic Petrenko
** Last update Sun May 22 20:56:05 2016 Antoine Baché
*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "raytracer.h"
#include "threadpool_raytracer.h"
#include "tools/math.h"

void			refresh_size(t_data *data, int frame)
{
  double		ratio;
  double		r;
  double		a;

  if (data->config.minimum_fps > 0)
    {
      r = (double)data->config.width / (double)data->config.height;
      ratio = (double)frame / (double)(DEFAULT_FPS);
      a = data->config.cur_width * data->config.cur_height;
      data->config.cur_width = (int)sqrt(a * ratio * r);
      data->config.cur_width = (data->config.cur_width > 0) ?
	data->config.cur_width : 1;
      data->config.cur_width = (data->config.cur_width < data->config.width) ?
	data->config.cur_width :
	data->config.width;
      data->config.cur_height = (int)(data->config.cur_width / r);
      data->config.cur_height = (data->config.cur_height > 0) ?
	data->config.cur_height : 1;
    }
  else
    {
      data->config.cur_width = data->config.width;
      data->config.cur_height = data->config.height;
    }
}

static void		set_pos(t_ivec2 **vec, t_data *data)
{
  vec[0][0].x = 0;
  vec[0][0].y = 0;
  vec[0][1].x = data->config.cur_width / 2;
  vec[0][1].y = data->config.cur_height / 2;
  vec[1][0].x = data->config.cur_width / 2;
  vec[1][0].y = 0;
  vec[1][1].x = data->config.cur_width;
  vec[1][1].y = data->config.cur_height / 2;
  vec[2][0].x = 0;
  vec[2][0].y = data->config.cur_height / 2;
  vec[2][1].x = data->config.cur_width / 2;
  vec[2][1].y = data->config.cur_height;
  vec[3][0].x = data->config.cur_width / 2;
  vec[3][0].y = data->config.cur_height / 2;
  vec[3][1].x = data->config.cur_width;
  vec[3][1].y = data->config.cur_height;
}

static t_ivec2		**prepare_tab_frame(void)
{
  t_ivec2		**tab;
  int			i;

  if (!(tab = my_malloc(sizeof(t_ivec2 *) * 4)))
    return (NULL);
  i = 0;
  while (i < 4)
    {
      if (!(tab[i] = my_malloc(sizeof(t_ivec2) * 2)))
	return (NULL);
      ++i;
    }
  return (tab);
}

int			set_frame(t_data *data)
{
  static t_ivec2	**pos = NULL;

  if (!pos && !(pos = prepare_tab_frame()))
    return (1);
  set_vectors(data, &data->scene->cam);
  data->scene->cache->clipable.clip_width = data->config.cur_width;
  data->scene->cache->clipable.clip_height = data->config.cur_height;
  set_pos(pos, data);
  if (data->config.minimum_fps)
    {
      render_multithread(data, pos, 4, LIVE);
    }
  else
    {
      data->config.cur_width = data->config.width;
      data->config.cur_height = data->config.height;
      data->scene->cache->clipable.clip_width = data->config.width;
      data->scene->cache->clipable.clip_height = data->config.height;
      set_pos(pos, data);
      render_multithread(data, pos, 4, RENDER);
    }
  return (0);
}
