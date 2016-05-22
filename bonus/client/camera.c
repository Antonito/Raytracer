/*
** camera.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 20:41:57 2016 Antoine Baché
** Last update Sun May  8 15:22:28 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"

int		get_camera(int fd, t_scene *scene)
{
  if (read_ok(fd) || send_ok(fd) ||
      read(fd, &scene->cam, sizeof(t_camera)) == -1)
    {
      write(2, "Error getting camera\n", 21);
      return (1);
    }
  write(1, "Camera OK\n", 10);
  return (0);
}
