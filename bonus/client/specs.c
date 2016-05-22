/*
** specs.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 20:47:17 2016 Antoine Baché
** Last update Sun May  8 15:56:27 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"

int		get_specs(int fd, t_scene *scene)
{
  write(1, "Getting specs\n", 14);
  if (read(fd, &scene->spec, sizeof(t_scene_spec)) == -1 ||
      send_ok(fd))
    return (1);
  write(1, "Specs loaded !\n", 15);
  return (0);
}
