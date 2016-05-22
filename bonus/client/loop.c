/*
** loop.c for Raytracer1 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:53:35 2016 Antoine Baché
** Last update Sun May  8 16:39:27 2016 Antoine Baché
*/

#include "raytracer.h"
#include "client.h"

int		client_loop(int fd)
{
  t_scene	*scene;

  if (!(scene = get_scene(fd)))
    return (1);
  print_scenes(scene);
  return (0);
}
