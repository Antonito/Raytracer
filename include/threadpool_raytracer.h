/*
** threadpool_raytracer.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 20 21:03:14 2016 Antoine Baché
** Last update Sat May 21 16:47:42 2016 Antoine Baché
*/

#ifndef	THREADPOOL_RAYTRACER_H_
# define THREADPOOL_RAYTRACER_H_

# include "threadpool.h"
# include "raytracer.h"

typedef enum		e_state_thread
  {
    LIVE,
    RENDER
  }			t_state_thread;

typedef struct		s_threadpool_raytracer
{
  int			id;
  pthread_barrier_t	*barrier;
  pthread_mutex_t	mutex;
  t_data		*data;
  t_ivec2		*pos;
}			t_threadpool_raytracer;

int			render_multithread(t_data *, t_ivec2 **pos, int nb,
					   t_state_thread state);

#endif /* !THREADPOOL_RAYTRACER_H_  */
