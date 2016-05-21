/*
** threadpool_raytracer.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri May 20 21:03:14 2016 Antoine Baché
** Last update Sun May 22 00:00:55 2016 Antoine Baché
*/

#ifndef	THREADPOOL_RAYTRACER_H_
# define THREADPOOL_RAYTRACER_H_

# include "threadpool.h"
# include "raytracer.h"

typedef enum		e_state_thread
  {
    LIVE,
    RENDER,
    FREE_T
  }			t_state_thread;

typedef struct		s_threadpool_raytracer
{
  pthread_barrier_t	*barrier;
  pthread_mutex_t	mutex;
  t_data		*data;
  t_ivec2		*pos;
}			t_threadpool_raytracer;

/*
** nb is the the number of fragments.
** This value must always be passed (to draw or free).
**
** Three modes are possible : Live / Render / Free_t
** Free should be called before you exit your program
*/
int			render_multithread(t_data *, t_ivec2 **pos, int nb,
					   t_state_thread state);

/*
** These functions should not be called
*/
int			loop_raytracer_th(t_data *, t_ivec2 **, int,
					  t_state_thread);

#endif /* !THREADPOOL_RAYTRACER_H_  */
