/*
** objects.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 22:17:18 2016 Antoine Baché
** Last update Sun May  8 16:42:24 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"
#include "tools/memory.h"

int		get_objs(int fd, t_scene *scene)
{
  int		i;

  if (send_ok(fd) || (scene->nb_obj = read_number(fd)) <= 0 ||
      !(scene->objs = my_calloc(scene->nb_obj + 1, sizeof(t_obj))))
    return (1);
  i = 0;
  while (i < scene->nb_obj)
    {
      write(1, "Loading objs\n", 13);
      if (send_ok(fd) || read(fd, &scene->objs[i], sizeof(t_obj)) == -1)
	return (1);
      ++i;
    }
  send_ok(fd);
  write(1, "Obj loaded\n", 11);
  return (0);
}
