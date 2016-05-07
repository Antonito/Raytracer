/*
** lights.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 17:21:53 2016 Antoine Baché
** Last update Sat May  7 17:37:13 2016 Antoine Baché
*/

#include <unistd.h>
#include "network.h"
#include "tools/memory.h"

static void	create_light_packet(char *packet, t_light *light)
{
  char		*tmp;
  unsigned int	i;

  tmp = (char *)light;
  i = 0;
  while (i < sizeof(t_light))
    {
      packet[i] = tmp[i];
      ++i;
    }
}

int		send_lights(int fd, t_light *lights, int nb)
{
  char		*tmp;
  int		i;

  if (!(tmp = my_calloc(1, sizeof(t_light))))
    return (1);
  i = 0;
  if (send_number(fd, nb) || read_ok(fd))
    return (1);
  while (i < nb)
    {
      create_light_packet(tmp, &lights[i]);
      if (write(fd, tmp, sizeof(t_light)) == -1 ||
	  read_ok(fd))
	return (1);
      ++i;
    }
  my_free(tmp);
  return (0);
}
