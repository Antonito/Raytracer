/*
** task.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 01:45:57 2016 Antoine Baché
** Last update Tue May 17 16:14:13 2016 Antoine Baché
*/

#include "threadpool.h"
#include "tools/memory.h"

void	threadpool_task_init(t_threadpool_task *task, void (*func)(), void *data)
{
  if (!(task->next = my_malloc(sizeof(t_threadpool_task))))
    return ;
  task->next->func = func;
  task->next->data = data;
  task->next->next = NULL;
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
