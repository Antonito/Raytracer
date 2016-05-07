/*
** light.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 20:51:01 2016 Antoine Baché
** Last update Sat May  7 21:01:41 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"

int		get_lights(int fd, t_scene *scene)
{
  int		i;
  int		nb_lights;

  if ((nb_lights = read_number(fd)) <= 0 ||
      !(scene->lights = my_calloc(nb_lights + 1, sizeof(t_light))))
    return (1);
  i = 0;
  while (i < nb_lights)
    {
      if (read(fd, &scene->lights[i], sizeof(t_light)) == -1 ||
	  send_ok(fd))
	return (1);
      ++i;
    }
  return (0);
}
