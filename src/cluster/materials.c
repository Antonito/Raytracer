/*
** materials.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 17:40:12 2016 Antoine Baché
** Last update Sat May  7 17:42:33 2016 Antoine Baché
*/

#include <unistd.h>
#include "network.h"
#include "tools/memory.h"

static void	create_material_packet(char *packet, t_material *material)
{
  char		*tmp;
  unsigned int	i;

  tmp = (char *)material;
  i = 0;
  while (i < sizeof(t_material))
    {
      packet[i] = tmp[i];
      ++i;
    }
}
#pragma message("Attention pointeur *name materials.c")
int		send_materials(int fd, t_material *materials, int nb)
{
  char		*tmp;
  int		i;

  if (!(tmp = my_calloc(1, sizeof(t_material))))
    return (1);
  i = 0;
  if (send_number(fd, nb) || read_ok(fd))
    return (1);
  while (i < nb)
    {
      create_material_packet(tmp, &materials[i]);
      if (write(fd, tmp, sizeof(t_material)) == -1 ||
	  read_ok(fd))
	return (1);
      ++i;
    }
  my_free(tmp);
  return (0);
}
