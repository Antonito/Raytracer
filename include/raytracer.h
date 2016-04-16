/*
** raytracer.h for Raytracer2 in /raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:39:45 2016 Antoine Baché
** Last update Sat Apr 16 18:16:32 2016 Ludovic Petrenko
*/

#ifndef	RAYTRACER2_H_
# define RAYTRACER2_H_

# ifdef	__APPLE__
#  include "OpenCL/opencl.h"
# else
#  include "CL/cl.h"
# endif
# include <lapin.h>
# include <stdbool.h>
# include "engine/scene.h"
# include "config.h"
# include "events.h"
# include "tools/memory.h"

# define DEFAULT_WIDTH		1280
# define DEFAULT_HEIGHT		720
# define WIN_NAME		"Ray Ta Soeur"

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*render;
  int			width;
  int			height;
  bool			fullscreen;
  t_scene		*scene;
  t_config		config;
  bool			events[NB_EVENT_KEY];
}			t_data;

int			init_data(int ac, char **av, t_data **data);
int			launch_raytracer(t_data *data);
t_bunny_response	main_events(t_bunny_event_state s,
				    t_bunny_keysym k,
				    t_data *data);
t_bunny_response	main_loop(t_data *data);
int			set_frame(t_data *data);

#endif /* RAYTRACER2_H_ */
