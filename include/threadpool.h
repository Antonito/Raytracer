/*
** threadpool.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 01:20:45 2016 Antoine Baché
** Last update Tue May 17 16:15:54 2016 Antoine Baché
*/

#ifndef THREADPOOL_H_
# define THREADPOOL_H_

# define NB_THREADS		4
# define CONSTRUCTOR		__attribute__((constructor))
# define DESTRUCTOR		__attribute__((destructor))

# include <stdbool.h>
# include <pthread.h>

typedef struct			s_threadpool_task
{
  void				(*func)();
  void				*data;
  struct s_threadpool_task	*next;
}				t_threadpool_task;

typedef struct			s_threadpool_queue
{
  pthread_mutex_t		mutex;
  pthread_cond_t		condition;
  t_threadpool_task		*first;
  t_threadpool_task		*last;
  bool				over;
}				t_threadpool_queue;

typedef struct			s_threadpool
{
  t_threadpool_queue		queue;
  pthread_mutex_t		mutex;
  pthread_t			*threads;
  int				init_threads;
  int				total_threads;
}				t_threadpool;

void				start_threadpool(void);
void				stop_threadpool(void);
int				threadpool_exec(void (*func)(), void *);

/*
** These functions should not be called.
*/
int				threadpool_push(t_threadpool_queue *,
						t_threadpool_task *);
int				threadpool_pop(t_threadpool_queue *,
					       t_threadpool_task *);
int				threadpool_pool_exec(t_threadpool *,
						     void (*func)(),
						     void *);
void				*threadpool_loop(void *);
int				threadpool_task_exec(t_threadpool_task *);
void				threadpool_task_init(t_threadpool_task *,
						     void (*func)(), void *);
void				threadpool_task_destroy(t_threadpool_task *);
int				threadpool_init(t_threadpool *);
void				threadpool_destroy(t_threadpool *);

#endif /* !THREADPOOL_H_  */
