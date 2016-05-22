/*
** server.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Apr 17 16:29:27 2016 Antoine Baché
** Last update Mon May 16 21:41:33 2016 Luka Boulagnon
*/

#include <unistd.h>
#include <pthread.h>
#include "raytracer.h"
#include "network.h"
#include "tools/str.h"

static int		bind_server(struct sockaddr_in *serv, int fd, int port)
{
  serv->sin_addr.s_addr = INADDR_ANY;
  serv->sin_family = AF_INET;
  serv->sin_port = htons(port);
  if (bind(fd, (struct sockaddr *)serv, sizeof(*serv)) == -1)
    {
      write(2, INIT_SERVER_ERROR, sizeof(INIT_SERVER_ERROR) - 1);
      return (1);
    }
  write(1, NEW_CLIENT_CONNECTED, sizeof(NEW_CLIENT_CONNECTED) - 1);
  return (0);
}

static int		init_tcp(t_data *data)
{
  struct sockaddr_in	serv;

  if ((data->network.fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, SOCKET_ERROR, sizeof(SOCKET_ERROR) - 1);
      return (1);
    }
  if (bind_server(&serv, data->network.fd, data->network.port))
    return (1);
  if (listen(data->network.fd, 1))
    {
      write(2, LISTEN_ERROR, sizeof(LISTEN_ERROR) - 1);
      return (1);
    }
  write(1, WAIT_CLIENT, sizeof(WAIT_CLIENT) - 1);
  connect_to_server(data);
  send_scene_all_clients(data);
  return (0);
}

#pragma message("Penser a rm le premier thread (useless)")
int			init_server(t_data *data)
{
  pthread_t		tcp_thread_loop;

  if (data->network.max_client == 0)
    return (0);
  data->network.run = true;
  data->network.all_connected = false;
  if (!(data->network.clients =
	my_malloc(sizeof(int) * data->network.max_client)))
    return (1);
  my_memset(data->network.clients, sizeof(int) * data->network.max_client, -1);
  if (init_tcp(data))
    return (1);
  if (pthread_create(&tcp_thread_loop, NULL, (t_thread)tcp_loop, (void *)data))
    return (1);
  return (0);
}
