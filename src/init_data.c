/*
** init_data.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:32:39 2016 Ludovic Petrenko
** Last update Thu May 19 02:37:54 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/math.h"

static void	set_fields(t_data *data)
{
  data->config.width = DEFAULT_WIDTH;
  data->config.height = DEFAULT_HEIGHT;
  data->config.fullscreen = false;
  data->config.minimum_fps = MINIMUM_FPS;
  data->effect = NO_EFFECT;
  data->joy.lon = 0;
  data->joy.lat = 0;
  data->joy.hor = 0;
  data->joy.ver = 0;
}

int	init_data(int ac, char **av, t_data **data)
{
  bunny_set_maximum_ram(2 * 1000 * 1000 * 1000);
  if (!(*data = my_calloc(1, sizeof(t_data))))
    return (1);
  set_fields(*data);
  if ((*data)->config.width <= 0 || (*data)->config.height <= 0 ||
      !((*data)->win = bunny_start((*data)->config.width,
				   (*data)->config.height,
				   (*data)->config.fullscreen, WIN_NAME)) ||
      !((*data)->render = bunny_new_pixelarray((*data)->config.width,
					       (*data)->config.height)))
    return (1);
  if (ac == 2)
    {
      if (!((*data)->scene = load_scene(av[1])))
	return (1);
    }
  else if (!((*data)->scene = load_scene(SCENE_DEFAULT)))
    return (1);
  if (!((*data)->scene->cache =
	bunny_new_pixelarray((*data)->config.width, (*data)->config.height)) ||
      load_config(*data, CONFIG_FILE))
    return (1);
  my_sin(0.0, DRAW);
  my_cos(0.0, DRAW);
  return (0);
}
