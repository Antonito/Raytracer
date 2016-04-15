/*
** raytracer.h for Raytracer2 in /raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:39:45 2016 Antoine Baché
** Last update Fri Apr 15 11:43:04 2016 Antoine Baché
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

# define DEFAULT_WIDTH		1280
# define DEFAULT_HEIGHT		720
# define WIN_NAME		"Ray Ta Soeur"

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*render;
  int			width;
  int			height;
  int			log_level;
  t_scene		*scene;
  t_config		config;
  bool			events[NB_EVENT_KEY];
}			t_data;

#endif /* RAYTRACER2_H_ */
