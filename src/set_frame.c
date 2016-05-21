/*
** set_frame.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  2 22:15:55 2016 Ludovic Petrenko
** Last update Sat May 21 23:12:32 2016 Ludovic Petrenko
*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "raytracer.h"
#include "threadpool_raytracer.h"
#include "tools/math.h"

#pragma message "comment"

void			refresh_size(t_data *data, int frame)
{
  double		ratio;
  double		r;
  double		a;

  if (data->config.minimum_fps > 0)
    {
      r = (double)data->config.width / (double)data->config.height;
      ratio = (double)frame / (double)(DEFAULT_FPS /* + data->joy.needed_fps */);
      a = data->config.cur_width * data->config.cur_height;
      data->config.cur_width = (int)sqrt(a * ratio * r);
      data->config.cur_width = (data->config.cur_width > 0) ? data->config.cur_width : 1;
      data->config.cur_width = (data->config.cur_width < data->config.width) ? data->config.cur_width :
	data->config.width;
      data->config.cur_height = (int)(data->config.cur_width / r);
      data->config.cur_height = (data->config.cur_height > 0) ? data->config.cur_height : 1;
      printf("\r\t\t%d x %d\t", data->config.cur_width, data->config.cur_height);
    }
  else
    {
      data->config.cur_width = data->config.width;
      data->config.cur_height = data->config.height;
    }
}

static void		set_pos(t_ivec2 **vec, t_data *data)
{
  int			i;
  int			j;
  int			k;

  i = k = 0;
  while (i < data->config.cur_width)
    {
      j = 0;
      while (j < data->config.cur_height)
	{
	  vec[k][0].x = i;
	  vec[k][0].y = j;
	  vec[k][1].x = MIN(i + 20, data->config.cur_width);
	  vec[k++][1].y = MIN(i + 20, data->config.cur_height);
	  j += 20;
	}
      i += 20;
    }
}

static t_ivec2		**prepare_tab_frame(int size)
{
  t_ivec2		**tab;
  int			i;

  if (!(tab = my_malloc(sizeof(t_ivec2 *) * size)))
    return (NULL);
  i = 0;
  while (i < size)
    {
      if (!(tab[i] = my_malloc(sizeof(t_ivec2) * 2)))
	return (NULL);
      ++i;
    }
  return (tab);
}

static void		free_frame(t_ivec2 **pos, int size)
{
  int			i;

  i = 0;
  while (i < size)
    {
      my_free(pos[i]);
      ++i;
    }
  my_free(pos);
}

int			set_frame(t_data *data)
{
  t_ivec2		**pos;

  if (!(pos = prepare_tab_frame(NB_FRAGMENT)))
    return (1);
  set_vectors(data, &data->scene->cam);
  data->scene->cache->clipable.clip_width = data->config.cur_width;
  data->scene->cache->clipable.clip_height = data->config.cur_height;
  set_pos(pos, data);
  if (data->config.minimum_fps)
    render_multithread(data, pos, NB_FRAGMENT, LIVE);
  else
    render_multithread(data, pos, NB_FRAGMENT, RENDER);
  free_frame(pos, NB_FRAGMENT);
  return (0);
}
