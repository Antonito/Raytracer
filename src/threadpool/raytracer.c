/*
** raytracer.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 20 20:55:25 2016 Antoine Baché
** Last update Sat May 21 04:43:48 2016 Antoine Baché
*/

#include "threadpool_raytracer.h"

void				call_thread(t_threadpool_raytracer *arg)
{
  calc_fragment(arg->data, (unsigned int *)arg->data->scene->cache->pixels,
		arg->pos);
  pthread_mutex_lock(arg->mutex);
  pthread_cond_signal(arg->cond);
  pthread_mutex_unlock(arg->mutex);
}

static void			threadpool_set_arg(int *loop, t_data *data,
						   t_ivec2 **pos,
						   t_threadpool_raytracer *arg)
{
  int				i;

  i = 0;
  while (i < loop[1])
    {
      arg[i].pos = pos[i];
      ++i;
    }
}

static t_threadpool_raytracer	*init_arg(int size, pthread_cond_t *cond,
					  pthread_mutex_t *mutex,
					  t_data *data)
{
  int				i;
  t_threadpool_raytracer	*arg;

  if (!(arg = my_malloc(sizeof(t_threadpool_raytracer) * (size))))
    return (NULL);
  i = 0;
  while (i < size)
    {
      arg[i].data = data;
      arg[i].cond = cond;
      arg[i].mutex = mutex;
      ++i;
    }
  return (arg);
}

int				render_multithread(t_data *data, t_ivec2 **pos,
						   int size)
{
  int				i;
  int				ret;
  static pthread_cond_t		cond = PTHREAD_COND_INITIALIZER;
  static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
  static int			loop = 0;
  static t_threadpool_raytracer	*arg = NULL;

  if (!arg && !(loop = 0) && !(arg = init_arg(size, &cond, &mutex, data)))
    return (1);
  threadpool_set_arg((int [2]){loop, size}, data, pos, arg);
  i = (ret = 0) - 1;
  while (++i < size)
    {
      if (threadpool_exec(call_thread, &arg[i]))
	ret = 1;
    }
  i = -1;
  pthread_mutex_lock(arg[0].mutex);
  while (++i < size)
    {
      printf("Wait %d : %x %x\n", i, arg[i].mutex, arg[i].cond);
      pthread_cond_wait(arg[0].cond, arg[0].mutex);
    }
  pthread_mutex_unlock(arg[0].mutex);
  if (!loop)
    ++loop;
  return (ret);
}
