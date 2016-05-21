/*
** raytracer.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 20 20:55:25 2016 Antoine Baché
** Last update Sat May 21 21:57:12 2016 Antoine Baché
*/

#include "threadpool_raytracer.h"

void				call_thread(t_threadpool_raytracer *arg)
{
  calc_fragment(arg->data, (unsigned int *)arg->data->scene->cache->pixels,
		arg->pos);
  if (arg->barrier)
    pthread_barrier_wait(arg->barrier);
}

static void			threadpool_set_arg(int *loop, t_ivec2 **pos,
						   t_threadpool_raytracer *arg,
						   pthread_barrier_t *barrier)
{
  int				i;

  i = 0;
  while (i < loop[1])
    {
      arg[i].barrier = barrier;
      arg[i].pos = pos[i];
      ++i;
    }
}

static t_threadpool_raytracer	*init_arg(int size, t_data *data)
{
  int				i;
  t_threadpool_raytracer	*arg;

  if (!(arg = my_malloc(sizeof(t_threadpool_raytracer) * (size))))
    return (NULL);
  i = 0;
  while (i < size)
    {
      arg[i].data = data;
      ++i;
    }
  return (arg);
}

static int	threadpool_raytracer_free(t_threadpool_raytracer **arg)
{
  if (*arg)
    my_free(*arg);
  *arg = NULL;
}

int				render_multithread(t_data *data, t_ivec2 **pos,
						   int size,
						   t_state_thread state)
{
  int				i;
  int				ret;
  pthread_barrier_t		barrier;
  static int			loop = -1;
  static t_threadpool_raytracer	*arg = NULL;

  if (state == FREE_T)
    return (threadpool_raytracer_free(&arg));
  i = (ret = 0) - 1;
  if (!arg && (loop = -1) && !(arg = init_arg(size, data)))
    return (1);
  if (state == LIVE && pthread_barrier_init(&barrier, NULL, 5))
    return (1);
  threadpool_set_arg((int [2]){++loop, size}, pos, arg,
		     (state == LIVE) ? &barrier : NULL);
  while (++i < size)
    if (threadpool_exec(call_thread, &arg[i]))
      ret = 1;
  if (state == LIVE)
    {
      pthread_barrier_wait(&barrier);
      if (pthread_barrier_destroy(&barrier))
	ret = 1;
    }
  return (ret);
}
