/*
** queue.c for Raytracer in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 01:57:52 2016 Antoine Baché
** Last update Tue May 17 17:19:05 2016 Antoine Baché
*/

#include "threadpool.h"
#include "tools/memory.h"

int			threadpool_push(t_threadpool_queue *queue,
					t_threadpool_task *task)
{
  t_threadpool_task	*queue_task;
  pthread_mutex_t	*mutex;
  pthread_cond_t	*condition;

  if (!queue || !task || !(queue_task = my_malloc(sizeof(t_threadpool_task))))
    return (1);
  threadpool_task_init(queue_task, task->func, task->data);
  mutex = &queue->mutex;
  condition = &queue->condition;
  pthread_mutex_lock(mutex);
  if (!queue->last)
    {
      queue->first = queue_task;
      queue->last = queue_task;
    }
  else
    {
      queue->last->next = queue_task;
      queue->last = queue_task;
    }
  pthread_cond_signal(condition);
  pthread_mutex_unlock(mutex);
  return (0);
}

int			threadpool_pop(t_threadpool_queue *queue,
				       t_threadpool_task *task)
{
  t_threadpool_task	*queue_task;
  pthread_mutex_t	*mutex;
  pthread_cond_t	*condition;

  if (!queue || !task)
    return (1);
  condition = &queue->condition;
  mutex = &queue->mutex;
  pthread_mutex_lock(mutex);
  while (!queue->first)
    {
      pthread_cond_wait(condition, mutex);
      if (queue->over)
	{
	  pthread_mutex_unlock(mutex);
	  return (1);
	}
    }
  queue_task = queue->first;
  queue->first = queue->first->next;
  pthread_mutex_unlock(mutex);
  threadpool_task_init(task, queue_task->func, queue_task->data);
  threadpool_task_destroy(queue_task);
  my_free(queue_task);
  return (0);
}
