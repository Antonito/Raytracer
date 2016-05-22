/*
** loop.c for Raytracer2 in /gfx_raytracer2/src/threadpool
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 21 23:37:35 2016 Antoine Baché
** Last update Sun May 22 15:52:32 2016 Antoine Baché
*/

#include "threadpool_raytracer.h"

int				render_multithread(t_data *data, t_ivec2 **pos,
						   int size,
						   t_state_thread state)
{
  static int			loop = 0;
  static t_state_thread		previous = FREE_T;

  if (state == RENDER && previous == RENDER)
    {
      if (!loop)
	{
	  ++loop;
	  loop_raytracer_th(data, pos, size, state);
	}
      return ;
    }
  if (state != RENDER)
    loop = 0;
  previous = state;
  return (loop_raytracer_th(data, pos, size, state));
}
