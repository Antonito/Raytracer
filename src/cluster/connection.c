/*
** connection.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Apr 17 17:25:46 2016 Antoine Baché
** Last update Thu Apr 21 18:17:35 2016 Antoine Baché
*/

#include <unistd.h>
#include <time.h>
#include "raytracer.h"
#include "network.h"

static int		accept_client(int fd)
{
  int			new_client;
  int			socket_size;
  struct sockaddr_in	client;

  socket_size = sizeof(struct sockaddr_in);
  if ((new_client = accept(fd, (struct sockaddr *)&client,
			   (socklen_t *)&socket_size)) < 0)
    {
      write(2, NEW_CLIENT_ERROR, sizeof(NEW_CLIENT_ERROR) - 1);
      return (-1);
    }
  write(1, NEW_CLIENT, sizeof(NEW_CLIENT) - 1);
  return (new_client);
}

void			connect_to_server(t_data *data)
{
  int			tmp;
  int			nb_clients;
  time_t		start;
  time_t		total;

  nb_clients = 0;
  start = time(NULL);
  total = 0;
  while (1)
    {
      if (total % 60 >= CONNECTION_DELAY)
	break;
      if (nb_clients == data->network.max_client)
	{
	  write(1, MAX_CLIENT_REACHED, sizeof(MAX_CLIENT_REACHED) - 1);
	  break;
	}
      if ((tmp = accept_client(data->network.fd)) != -1 && tmp != 0)
	{
	  data->network.clients[nb_clients] = tmp;
	  ++nb_clients;
	}
      total = time(NULL) - start;
    }
  data->network.all_connected = true;
}
