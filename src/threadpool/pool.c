/*
** pool.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 02:25:38 2016 Antoine Baché
** Last update Sun May 22 18:33:29 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools/memory.h"
#include "threadpool.h"

static int		threadpool_init_start_threads(t_threadpool *pool)
{
  pthread_attr_t	attr;
  int			i;

  if (pthread_attr_init(&attr) ||
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))
    return (1);
  i = 0;
  while (i < pool->total_threads)
    {
      if (pthread_create(&pool->threads[i], &attr, threadpool_loop, pool))
	break;
      ++i;
    }
  pool->threads[i] = 0;
  return (0);
}

int			threadpool_init(t_threadpool *pool)
{
  pool->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  pool->queue.mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  pool->queue.condition = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
  pool->queue.first = NULL;
  pool->queue.last = NULL;
  pool->queue.over = true;
  pool->total_threads = NB_THREADS;
  if (!(pool->threads = my_malloc(sizeof(pthread_t) *
				  (pool->total_threads + 1)))
      || threadpool_init_start_threads(pool))
    return (1);
  return (0);
}

void			threadpool_destroy(t_threadpool *pool)
{
  int			i;

  i = 0;
  while (i < pool->total_threads)
    {
      pthread_cancel(pool->threads[i]);
      pthread_detach(pool->threads[i]);
      ++i;
    }
  my_free(pool->threads);
  pthread_cond_destroy(&pool->queue.condition);
  pthread_mutex_destroy(&pool->queue.mutex);
  pthread_mutex_destroy(&pool->mutex);
  pool->threads = NULL;
  pool->total_threads = 0;
  pool->init_threads = 0;
}

int			threadpool_pool_exec(t_threadpool *pool, void (*func)(),
					     void *data)
{
  t_threadpool_task	task;
  int			ret;

  if (!pool || !func)
    return (1);
  threadpool_task_init(&task, func, data);
  ret = threadpool_push(&pool->queue, &task);
  threadpool_task_destroy(&task);
  return (ret);
}

void			*threadpool_loop(void *data)
{
  t_threadpool		*pool;
  t_threadpool_task	task;

  pool = (t_threadpool *)data;
  pthread_mutex_lock(&pool->mutex);
  ++pool->init_threads;
  pthread_mutex_unlock(&pool->mutex);
  task.func = NULL;
  task.data = NULL;
  task.next = NULL;
  while (!threadpool_pop(&pool->queue, &task))
    threadpool_task_exec(&task);
  return (NULL);
}
