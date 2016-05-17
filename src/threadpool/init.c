/*
** init.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 02:35:12 2016 Antoine Baché
** Last update Tue May 17 17:36:04 2016 Antoine Baché
*/

#include <unistd.h>
#include "threadpool.h"

static t_threadpool		g_threadpool;

int				threadpool_exec(void (*func)(), void *data)
{
  return (threadpool_pool_exec(&g_threadpool, func, data));
}

void				start_threadpool(void)
{
  if (threadpool_init(&g_threadpool) < 0)
    write(2, "Error creating threadpool\n", 26);
}

void				stop_threadpool(void)
{
  threadpool_destroy(&g_threadpool);
}
