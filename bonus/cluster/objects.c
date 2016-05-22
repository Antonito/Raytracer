/*
** objects.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 17:04:58 2016 Antoine Baché
** Last update Sun May  8 17:07:00 2016 Antoine Baché
*/

#include <unistd.h>
#include "network.h"
#include "tools/memory.h"

static void	create_obj_packet(char *packet, t_obj *obj)
{
  char		*tmp;
  unsigned int	i;

  tmp = (char *)obj;
  i = 0;
  while (i < sizeof(t_obj))
    {
      packet[i] = tmp[i];
      ++i;
    }
}

#pragma message("Objects.c Pb avec pointeurs")
int		send_objs(int fd, t_obj *objs, int nb)
{
  char		*tmp;
  int		i;

  if (read_ok(fd) || !(tmp = my_calloc(1, sizeof(t_obj))))
    return (1);
  i = 0;
  if (send_number(fd, nb))
    return (1);
  while (i < nb)
    {
      write(1, "New obj\n", 8);
      create_obj_packet(tmp, &objs[i]);
      if (read_ok(fd) || write(fd, tmp, sizeof(t_obj)) == -1)
	return (1);
      ++i;
    }
  write(1, "Objs sent !\n", 12);
  my_free(tmp);
  return (0);
}
