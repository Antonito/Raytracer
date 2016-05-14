/*
** init_data.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:32:39 2016 Ludovic Petrenko
** Last update Sat May 14 18:21:33 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/math.h"

static void	set_fields(t_data *data)
{
  data->width = DEFAULT_WIDTH;
  data->height = DEFAULT_HEIGHT;
  data->fullscreen = false;
  data->minimum_fps = MINIMUM_FPS;
}

int	init_data(int ac, char **av, t_data **data)
{
  bunny_set_maximum_ram(3 * 1000 * 1000 * 1000);
  if (!(*data = my_calloc(1, sizeof(t_data))))
    return (1);
  set_fields(*data);
  if ((*data)->width <= 0 || (*data)->height <= 0 ||
      !((*data)->win = bunny_start((*data)->width, (*data)->height,
				   (*data)->fullscreen, WIN_NAME)) ||
      !((*data)->render = bunny_new_pixelarray((*data)->width,
					       (*data)->height)))
    return (1);
  if (ac == 2)
    {
      if (!((*data)->scene = load_scene(av[1])))
	return (1);
    }
  else if (!((*data)->scene = load_scene(SCENE_DEFAULT)))
    return (1);
  if (!((*data)->scene->cache = bunny_new_pixelarray((*data)->width,
						     (*data)->height)) ||
      load_config(*data, CONFIG_FILE))
    return (1);
  my_sin(0.0, DRAW);
  my_cos(0.0, DRAW);
  return (0);
}
