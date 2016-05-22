/*
** get_next_line.c for gnl* in /tek1/semestre_01/CPE_2015_getnextline
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Tue Mar  8 18:07:36 2016 Ludovic Petrenko
** Last update Sun May 22 12:05:49 2016 Antoine Baché
*/

#include "tools/get_next_line.h"
#include "tools/memory.h"

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1] = {0};
  static int	cursor = 0;
  static int	ret = 0;
  char		*s;
  int		last;
  int		len;

  if (!(len = 0) && (s = my_strncat(NULL, 0, "", 1)) == NULL)
    return (NULL);
  while (buf[cursor] != '\n')
    {
      last = cursor;
      if (cursor >= ret)
	if ((ret = read(fd, buf, READ_SIZE)) == -1 ||
	    (buf[ret] = cursor = last = 0))
	  return (NULL);
      if (ret == 0)
	return ((len == 0) ? NULL : s);
      while (buf[cursor] != '\n' && cursor < ret && ++cursor);
      if ((s = my_strncat(s, len, buf + last, cursor - last)) == NULL)
	return (NULL);
      len += cursor - last;
    }
  ++cursor;
  return (s);
}

char	*my_strncat(char *s, int len, char *t, int n)
{
  char	*new;
  int	i[2];

  if ((new = my_malloc(len + n + 1)) == NULL)
    return (NULL);
  i[1] = i[0] = -1;
  while (++i[0] < len)
    new[i[0]] = s[i[0]];
  while (++i[1] < n)
    new[i[0] + i[1]] = t[i[1]];
  new[i[0] + i[1]] = 0;
  if (s != NULL)
    my_free(s);
  return (new);
}
