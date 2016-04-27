/*
** server.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Apr 17 16:29:27 2016 Antoine Baché
** Last update Thu Apr 21 18:24:34 2016 Antoine Baché
*/

#include <unistd.h>
#include <pthread.h>
#include "raytracer.h"
#include "network.h"

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

static void		server_loop(t_data *data)
{
  while (data->network.run)
    {
      /**
       ** Do calculations here
       */
      ;
    }
}

static void		*tcp_thread(void *data_arg)
{
  t_data		*data;
  struct sockaddr_in	serv;

  data = data_arg;
  if ((data->network.fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, SOCKET_ERROR, sizeof(SOCKET_ERROR) - 1);
      return (NULL);
    }
  if (bind_server(&serv, data->network.fd, data->network.port))
    return (NULL);
  if (listen(data->network.fd, 1))
    {
      write(2, LISTEN_ERROR, sizeof(LISTEN_ERROR) - 1);
      return (NULL);
    }
  write(1, WAIT_CLIENT, sizeof(WAIT_CLIENT) - 1);
  connect_to_server(data);
  server_loop(data);
  return (NULL);
}

int			init_server(t_data *data)
{
  pthread_t		tcp_thread_buff;

  data->network.run = true;
  data->network.all_connected = false;
  if (!(data->network.clients =
	my_malloc(sizeof(int) * data->network.max_client)))
    return (1);
  if (pthread_create(&tcp_thread_buff, NULL, tcp_thread, (void *)data))
    {
      write(2, CREATE_THREAD_ERROR, sizeof(CREATE_THREAD_ERROR) - 1);
      return (1);
    }
  if (pthread_join(tcp_thread_buff, NULL))
    {
      write(2, THREAD_ERROR, sizeof(THREAD_ERROR) - 1);
      return (1);
    }
  return (0);
}
