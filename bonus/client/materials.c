/*
** materials.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 21:10:07 2016 Antoine Baché
** Last update Sun May  8 16:52:44 2016 Antoine Baché
*/

#include <unistd.h>
#include "client.h"
#include "network.h"
#include "tools/str.h"

int		get_mats(int fd, t_scene *scene)
{
  char		buff[1024];
  int		i;

  write(1, "Getting materials\n", 18);
  if ((scene->nb_mat = read_number(fd)) <= 0 ||
      !(scene->mat = my_calloc(scene->nb_mat + 1, sizeof(t_material))))
    return (1);
  i = 0;
  while (i < scene->nb_mat)
    {
      my_bzero(buff, sizeof(buff));
      if (read(fd, &scene->mat[i], sizeof(t_material)) == -1 || send_ok(fd) ||
	  read(fd, buff, sizeof(buff) - 1) == -1 ||
	  !(scene->mat[i].name = my_strdup(buff)) || send_ok(fd))
	return (1);
      ++i;
    }
  write(1, "Material loaded\n", 16);
  return (0);
}
