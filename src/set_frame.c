/*
** set_frame.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  2 22:15:55 2016 Ludovic Petrenko
** Last update Wed May 18 04:08:33 2016 Ludovic Petrenko
*/

#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "raytracer.h"

void			refresh_size(t_data *data, int frame)
{
  double		ratio;
  double		r;
  double		a;

  if (MINIMUM_FPS)
    {
      r = (double)data->width / (double)data->height;
      ratio = (double)frame / (double)MINIMUM_FPS;
      a = data->cur_width * data->cur_height;
      data->cur_width = (int)sqrt(a * ratio * r);
      data->cur_width = (data->cur_width > 0) ? data->cur_width : 1;
      data->cur_width = (data->cur_width < data->width) ? data->cur_width :
	data->width;
      data->cur_height = (int)(data->cur_width / r);
      data->cur_height = (data->cur_height > 0) ? data->cur_height : 1;
      printf("\r\t\t%d x %d\t", data->cur_width, data->cur_height);
    }
  else
    {
      data->cur_width = data->width;
      data->cur_height = data->height;
    }
}

static void		*call_thread(void *arg)
{

  t_calc_fragment	*args;

  args = arg;
  calc_fragment(args->data, (unsigned int *)args->data->scene->cache->pixels,
		args->pos);
  return (NULL);
}

static void		set_pos(t_calc_fragment *thread_calc, t_data *data)
{
  thread_calc[0].pos[0].x = 0;
  thread_calc[0].pos[0].y = 0;
  thread_calc[0].pos[1].x = data->cur_width / 2;
  thread_calc[0].pos[1].y = data->cur_height / 2;
  thread_calc[1].pos[0].x = data->cur_width / 2;
  thread_calc[1].pos[0].y = 0;
  thread_calc[1].pos[1].x = data->cur_width;
  thread_calc[1].pos[1].y = data->cur_height / 2;
  thread_calc[2].pos[0].x = 0;
  thread_calc[2].pos[0].y = data->cur_height / 2;
  thread_calc[2].pos[1].x = data->cur_width / 2;
  thread_calc[2].pos[1].y = data->cur_height;
  thread_calc[3].pos[0].x = data->cur_width / 2;
  thread_calc[3].pos[0].y = data->cur_height / 2;
  thread_calc[3].pos[1].x = data->cur_width;
  thread_calc[3].pos[1].y = data->cur_height;
}

int			set_frame(t_data *data)
{
  /* pthread_t		thread[4]; */
  /* t_calc_fragment	thread_calc[4]; */
  /* int			i; */

  /* i = -1; */
  /* while (++i < 4) */
  /*   thread_calc[i].data = data; */
  /* set_pos(thread_calc, data); */
  /* set_vectors(data, &data->scene->cam); */
  /* if (pthread_create(&thread[0], NULL, call_thread, &thread_calc[0]) || */
  /*     pthread_create(&thread[1], NULL, call_thread, &thread_calc[1]) || */
  /*     pthread_create(&thread[2], NULL, call_thread, &thread_calc[2]) || */
  /*     pthread_create(&thread[3], NULL, call_thread, &thread_calc[3]) || */
  /*     pthread_join(thread[0], NULL) || pthread_join(thread[1], NULL) || */
  /*     pthread_join(thread[2], NULL) || pthread_join(thread[3], NULL)) */
  /*   return (1); */
  t_ivec2	pos[2];

  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = data->cur_width;
  pos[1].y = data->cur_height;
  set_vectors(data, &data->scene->cam);
  calc_fragment(data, (unsigned int *)data->scene->cache->pixels, pos);
  return (0);
}
