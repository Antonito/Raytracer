/*
** scene.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 16:07:22 2016 Antoine Baché
** Last update Sat May  7 20:25:04 2016 Antoine Baché
*/

#include <unistd.h>
#include "raytracer.h"
#include "network.h"

static void	create_specs_packet(char *packet, t_scene_spec *spec)
{
  char		*tmp;
  unsigned int	i;

  tmp = (char *)spec;
  i = 0;
  while (i < sizeof(t_scene_spec))
    {
      packet[i] = tmp[i];
      ++i;
    }
}

static int	send_specs(int fd, t_scene_spec *spec)
{
  char		*tmp;

  if (!(tmp = my_calloc(1, sizeof(t_scene_spec))))
    return (1);
  create_specs_packet(tmp, spec);
  if (write(fd, tmp, sizeof(t_scene_spec)) == -1)
    return (1);
  my_free(tmp);
  return (read_ok(fd));
}


void		send_scene_all_clients(t_data *data)
{
  int		i;
  t_scene	*tmp;

  i = 0;
  while (data->network.clients[i] != -1)
    {
      tmp = data->scene;
#pragma message("Penser a envoyer nb de scene en premier")
      while (tmp)
	{
	  if (send_camera(data->network.clients[i], &tmp->cam) ||
	      send_objs(data->network.clients[i], tmp->objs, tmp->nb_obj) ||
	      send_lights(data->network.clients[i], tmp->lights,
			  tmp->nb_light) ||
	      send_materials(data->network.clients[i], tmp->mat,
			     tmp->nb_mat) ||
	      send_specs(data->network.clients[i], &tmp->spec))
	    {
	      data->network.clients[i] = -1;
	      return ;
	    }
	  tmp = tmp->next;
	}
#ifdef	DEBUG
      printf("Scene sent to client %d\n", i);
#endif
      ++i;
    }
}
