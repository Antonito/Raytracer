/*
** camera.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 16:40:27 2016 Antoine Baché
** Last update Sun May  8 15:22:40 2016 Antoine Baché
*/

#include <unistd.h>
#include "network.h"
#include "engine/camera.h"
#include "tools/memory.h"

static void	create_camera_packet(char *packet, t_camera *cam)
{
  char		*tmp;
  unsigned int	i;

  tmp = (char *)cam;
  i = 0;
  while (i < sizeof(t_camera))
    {
      packet[i] = tmp[i];
      ++i;
    }
}

int		send_camera(int fd, t_camera *cam)
{
  char		tmp[sizeof(t_camera)];


  if (send_ok(fd) || read_ok(fd))
    {
      write(2, "Error sending camera\n", 21);
      return (1);
    }
  my_bzero(tmp, sizeof(t_camera));
  create_camera_packet(tmp, cam);
  if (write(fd, tmp, sizeof(t_camera)) == -1)
    return (1);
  write(1, "Camera sent !\n", 14);
  return (0);
}
