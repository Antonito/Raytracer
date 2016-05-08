/*
** scene.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 16:07:22 2016 Antoine Baché
** Last update Sun May  8 17:53:54 2016 Antoine Baché
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
  char		tmp[sizeof(t_scene_spec)];

  my_bzero(tmp, sizeof(t_scene_spec));
  create_specs_packet(tmp, spec);
  if (write(fd, tmp, sizeof(t_scene_spec)) == -1 || read_ok(fd))
    return (1);
  write(1, "Specs sent !\n", 13);
  return (0);
}

static void	count_scenes(int fd, t_scene *scenes)
{
  static int	i = 0;

  if (!i)
    while (scenes)
      {
	++i;
	scenes = scenes->next;
      }
  if (send_number(fd, i) || read_ok(fd))
    return ;
  write(1, "Sent new scene\n", 15);
  return ;
}

void		send_scene_all_clients(t_data *data)
{
  int		i;
  t_scene	*tmp;

  i = 0;
  while (data->network.clients[i] != -1)
    {
      tmp = data->scene;
      count_scenes(data->network.clients[i], tmp);
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
	      break ;
	    }
	  tmp = tmp->next;
	}
      ++i;
    }
}
