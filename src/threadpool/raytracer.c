/*
** raytracer.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 20 20:55:25 2016 Antoine Baché
** Last update Sat May 21 16:34:24 2016 Antoine Baché
*/

#include "threadpool_raytracer.h"

static pthread_cond_t		g_cond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t		g_mutex = PTHREAD_MUTEX_INITIALIZER;
static int			lock[4] = {0};

void				call_thread(t_threadpool_raytracer *arg)
{
  calc_fragment(arg->data, (unsigned int *)arg->data->scene->cache->pixels,
		arg->pos);
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
      lock[i] = 1;
      arg[i].id = i;
      arg[i].data = data;
      arg[i].mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;;
      ++i;
    }
  return (arg);
}

int				render_multithread(t_data *data, t_ivec2 **pos,
						   int size)
{
  int				i;
  int				ret;
  pthread_barrier_t		barrier;
  static int			loop = 0;
  static t_threadpool_raytracer	*arg = NULL;

  if (!arg && !(loop = 0) && !(arg = init_arg(size, data)))
    return (1);
  pthread_barrier_init(&barrier, NULL, size + 1);
  threadpool_set_arg((int [2]){loop, size}, pos, arg, &barrier);
  i = (ret = 0) - 1;
  while (++i < size)
    {
      if (threadpool_exec(call_thread, &arg[i]))
	ret = 1;
    }
  i = -1;
  pthread_barrier_wait(&barrier);
  pthread_barrier_destroy(&barrier);
  if (!loop)
    ++loop;
  return (ret);
}
