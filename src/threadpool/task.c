/*
** task.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 01:45:57 2016 Antoine Baché
** Last update Sun May 22 12:13:57 2016 Antoine Baché
*/

#include <stdlib.h>
#include "threadpool.h"

void	threadpool_task_init(t_threadpool_task *task, void (*func)(),
			     void *data)
{
  task->func = func;
  task->data = data;
  task->next = NULL;
}

void	threadpool_task_destroy(t_threadpool_task *task)
{
  task->func = NULL;
  task->next = NULL;
  task->data = NULL;
}

int	threadpool_task_exec(t_threadpool_task *task)
{
  if (!task)
    return (-1);
  if (!task->data)
    task->func();
  else
    task->func(task->data);
  return (0);
}
