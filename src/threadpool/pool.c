/*
** pool.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 02:25:38 2016 Antoine Baché
** Last update Tue May 17 16:45:28 2016 Antoine Baché
*/

#include "threadpool.h"
#include "tools/memory.h"

static int		threadpool_init_start_threads(t_threadpool *pool)
{
  int			i;

  i = 0;
  while (i < NB_THREADS)
    {
      if (pthread_create(&pool->threads[i], NULL, threadpool_loop, pool))
	break;
      ++i;
    }
  pool->threads[i] = 0;
  return (0);
}

int			threadpool_init(t_threadpool *pool)
{
  pool->queue.mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  pool->queue.condition = (pthread_cond_t)PTHREAD_COND_INITIALIZER;
  pool->queue.first = NULL;
  pool->queue.last = pool->queue.first;
  pool->queue.over = true;
  pool->mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  if (!(pool->threads = my_malloc(sizeof(pthread_t) * (NB_THREADS + 1))) ||
      threadpool_init_start_threads(pool))
    return (1);
  pool->total_threads = NB_THREADS;
  return (0);
}

void			threadpool_destroy(t_threadpool *pool)
{
  int			i;

  i = 0;
  while (i < NB_THREADS)
    {
      pthread_join(pool->threads[i], NULL);
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
