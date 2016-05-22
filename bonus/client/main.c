/*
** main.c for Raytracer in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:15:34 2016 Antoine Baché
** Last update Mon Apr 18 11:09:14 2016 Antoine Baché
*/

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"
#include "tools/str.h"

int			init_connect(char *address, char *port_str)
{
  int			port;
  int			fd;
  struct sockaddr_in	serv;

  port = my_getnbr(port_str);
  if (port < 1024)
    {
      write(2, "Incorrect port number\n", 22);
      return (-1);
    }
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "Cannot create socket\n", 21);
      return (-1);
    }
  serv.sin_addr.s_addr = inet_addr(address);
  serv.sin_family = AF_INET;
  serv.sin_port = htons(port);
  if (connect(fd, (struct sockaddr *)&serv, sizeof(serv)) == -1)
    {
      write(2, "Cannot establish connection\n", 28);
      return (-1);
    }
  return (client_loop(fd));
}

int			start_client(char *address, char *port_str)
{
  int			fd;

  if ((fd = init_connect(address, port_str)) == -1)
    return (1);
#ifdef	DEBUG
  write(1, "Client connected\n", 17);
#endif
  return (0);
}

void			write_usage(const char *name)
{
  write(2, "Usage: ", 6);
  write(2, name, my_strlen(name));
  write(2, " address port\n", 14);
}

int			main(int ac, char **av, char **env)
{
  if (ac < 3)
    {
      write_usage(av[0]);
      return (1);
    }
  if (!env)
    {
      write(2, "Env is missing\n", 15);
      return (1);
    }
  if (start_client(av[1], av[2]))
    {
      return (1);
    }
  return (0);
}
