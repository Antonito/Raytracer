/*
** messages.c for Raytracer in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 16:50:42 2016 Antoine Baché
** Last update Sat May  7 17:36:10 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools/memory.h"
#include "tools/str.h"

inline int	read_ko(const int fd)
{
  char		*msg;

  if (!(msg = my_calloc(1, 1024)))
    return (1);
  if (read(fd, msg, 1023) == -1)
    return (1);
  if (my_strcmp("KO", msg))
    {
      my_free(msg);
      return (1);
    }
  my_free(msg);
  return (0);
}

int		read_ok(const int fd)
{
  char		*msg;

  if (!(msg = my_calloc(1, 1024)))
    return (1);
  if (read(fd, msg, 1023) == -1)
    return (1);
  if (my_strcmp("OK", msg))
    {
      my_free(msg);
      return (1);
    }
  my_free(msg);
  return (0);
}

inline int	send_ko(const int fd)
{
  if (write(fd, "KO", 2) == -1)
    return (1);
  return (0);
}

inline int	send_ok(const int fd)
{
  if (write(fd, "OK", 2) == -1)
    return (1);
  return (0);
}
