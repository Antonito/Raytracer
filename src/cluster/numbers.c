/*
** numbers.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 17:14:41 2016 Antoine Baché
** Last update Sat May  7 17:36:40 2016 Antoine Baché
*/

#include <unistd.h>

int		send_number(const int fd, int nb)
{
  if (write(fd, &nb, sizeof(int)))
    return (1);
  return (0);
}

inline int	read_number(const int fd)
{
  int		nb;
  char		buff[sizeof(int)];

  if (read(fd, buff, sizeof(int)) == -1)
    return (0);
  ((char *)&nb)[0] = buff[0];
  ((char *)&nb)[1] = buff[1];
  ((char *)&nb)[2] = buff[2];
  ((char *)&nb)[3] = buff[3];
  return (nb);
}
