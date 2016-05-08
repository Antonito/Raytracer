/*
** materials.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 17:40:12 2016 Antoine Baché
** Last update Sun May  8 16:51:08 2016 Antoine Baché
*/

#include <unistd.h>
#include "network.h"
#include "tools/memory.h"
#include "tools/str.h"

static void	create_material_packet(char *packet, t_material *material)
{
  char		*tmp;
  unsigned int	i;
  int		len;

  tmp = (char *)material;
  i = 0;
  while (i < sizeof(t_material))
    {
      packet[i] = tmp[i];
      ++i;
    }
}

#pragma message("Penser a envoyer et recuperer nom mat")
int		send_materials(int fd, t_material *materials, int nb)
{
  char		tmp[sizeof(t_material)];
  int		i;

  my_bzero(tmp, sizeof(t_material));
  i = 0;
  if (send_number(fd, nb) || read_ok(fd))
    return (1);
  while (i < nb)
    {
      write(1, "Sending new material\n", 21);
      create_material_packet(tmp, &materials[i]);
      if (write(fd, tmp, sizeof(t_material)) == -1 ||
	  read_ok(fd) ||
	  write(fd, materials[i].name, my_strlen(materials[i].name) + 1) == -1 ||
	  read_ok(fd))
	return (1);
      ++i;
    }
  write(1, "Materials sent!\n", 16);
  return (0);
}
