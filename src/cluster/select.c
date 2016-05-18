/*
** select.c for Raytracer2 in /home/asphahyre/rendu/gfx_raytracer2/src/cluster
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Mon May 16 21:34:58 2016 Luka Boulagnon
** Last update Mon May 16 21:42:59 2016 Luka Boulagnon
*/

#include "network.h"
#include <unistd.h>

static int		fdready(t_data *data, fd_set *clients, int fd, int *max)
{
  static int		step = 0;

  if (!fd)
    {
      if (read(0, NULL, 1) > 0)
	step = 1;
      else
	{
	  FD_ZERO(clients);
	  return (-1);
	}
    }
  else if (fd != data->network.fd && step)
    {
      /*
      ** On read du data du client i. <3
      */
    }
  else if (fd == data->network.fd && !step)
    if (new_connection(clients, data->network.fd, max) == -1)
      {
	FD_ZERO(clients);
	return (-1);
      }
  return (0);
}

static fd_set		except_fd()
{
  fd_set		except;

  FD_ZERO(&except);
  FD_SET(1, &except);
  FD_SET(2, &except);
  return (except);
}

static fd_set		init_clients(t_data *data)
{
  fd_set		clients;

  FD_ZERO(&clients);
  FD_SET(0, &clients);
  FD_SET(data->network.fd, &clients);
  return (clients);
}

void			*tcp_loop(t_data *data)
{
  fd_set		clients;
  fd_set		set;
  int			maxfd;
  int			i;

  clients = init_clients(data);
  maxfd = data->network.fd;
  if (data->network.clients[0] == -1)
    return (NULL);
  while (data->network.run)
    {
      set = clients;
      select(maxfd + 1, &set, NULL, (fd_set []){except_fd()}, NULL);
      i = -1;
      while (i++ < maxfd)
	if (FD_ISSET(i, &set))
	  if (fdready(data, &clients, i, &maxfd) == -1)
	    return (NULL);
    }
  return (NULL);
}
