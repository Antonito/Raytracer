/*
** init_data.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:32:39 2016 Ludovic Petrenko
** Last update Sun May 22 23:26:54 2016 Antoine Baché
*/

#include "raytracer.h"
#include "threadpool.h"
#include "loader.h"
#include "tools/math.h"

static void	set_fields(t_data *data)
{
  start_threadpool();
  data->config.fullscreen = true;
  data->config.minimum_fps = DEFAULT_FPS;
  data->effect = NO_EFFECT;
  data->joy.lon = 0;
  data->joy.lat = 0;
  data->joy.hor = 0;
  data->joy.ver = 0;
  data->rendering = false;
  my_sin(0.0, DRAW);
  my_cos(0.0, DRAW);
}

static int	load_all_scenes(int ac, char **av, t_data *data)
{
  int		i;
  t_scene	*s;

  if (ac == 1 && (!(s = load_scene(SCENE_DEFAULT, data)) ||
		  !(data->scene = s->next = s->prev = s)))
    return (1);
  else
    {
      i = 0;
      while (++i < ac)
	{
	  if (!(s = load_scene(av[i], data)))
	    return (1);
	  if (i == 1)
	    data->scene = s->next = s->prev = s;
	  else
	    {
	      s->next = data->scene;
	      data->scene->prev->next = s;
	      s->prev = data->scene->prev;
	      data->scene->prev = s;
	    }
	}
    }
  return (0);
}

int	init_data(int ac, char **av, t_data **data)
{
  bunny_set_maximum_ram(2 * 1000 * 1000 * 1000);
  bunny_set_memory_check(true);
  if (!(*data = my_calloc(1, sizeof(t_data))))
    return (1);
  set_fields(*data);
  if (load_config(*data, CONFIG_FILE) ||
      !((*data)->win = bunny_start((*data)->config.width,
				   (*data)->config.height,
				   (*data)->config.fullscreen, WIN_NAME)) ||
      !((*data)->render = bunny_new_pixelarray((*data)->config.width,
					       (*data)->config.height)) ||
      load_all_scenes(ac, av, *data))
    return (1);
  return (0);
}
