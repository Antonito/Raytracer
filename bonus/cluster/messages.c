/*
** messages.c for Raytracer in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 16:50:42 2016 Antoine Baché
** Last update Sun May  8 14:42:28 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools/memory.h"
#include "tools/str.h"

int		read_ko(const int fd)
{
  char		msg[1024];

  my_bzero(msg, sizeof(msg));
  if (read(fd, msg, 1023) == -1)
    return (1);
  if (my_strcmp("KO", msg))
    {
      return (1);
    }
  return (0);
}

int		read_ok(const int fd)
{
  char		msg[1024];

  my_bzero(msg, sizeof(msg));
  if (read(fd, msg, 1023) == -1)
    return (1);
  write(1, msg, my_strlen(msg));
  if (my_strcmp("OK", msg))
    {
      return (1);
    }
  return (0);
}

int		send_ko(const int fd)
{
  if (write(fd, "KO\0", 3) == -1)
    return (1);
  return (0);
}

int		send_ok(const int fd)
{
  if (write(fd, "OK\0", 3) == -1)
    return (1);
  return (0);
}
