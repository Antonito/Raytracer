/*
** light.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 20:51:01 2016 Antoine Baché
** Last update Sun May  8 16:13:06 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"

int		get_lights(int fd, t_scene *scene)
{
  int		i;

  if ((scene->nb_light = read_number(fd)) < 0 ||
      !(scene->lights = my_calloc(scene->nb_light + 1, sizeof(t_light))) ||
      send_ok(fd))
    {
      write(2, "Error getting lights\n", 21);
      return (1);
    }
  i = 0;
  while (i < scene->nb_light)
    {
      if (read(fd, &scene->lights[i], sizeof(t_light)) == -1 ||
	  send_ok(fd))
	return (1);
      ++i;
    }
  write(1, "Lights loaded !\n", 16);
  return (0);
}
