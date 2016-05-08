/*
** init_data.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:32:39 2016 Ludovic Petrenko
** Last update Sat May  7 22:51:04 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"

int	init_data(int ac, char **av, t_data **data)
{
  set_max_heap_size(4000);
  if (!(*data = my_calloc(1, sizeof(t_data))))
    return (1);
  (*data)->width = DEFAULT_WIDTH;
  (*data)->height = DEFAULT_HEIGHT;
  (*data)->fullscreen = false;
  if (!((*data)->win = bunny_start((*data)->width, (*data)->height,
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
  return (0);
}
