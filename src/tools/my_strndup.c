/*
** my_strndup.c for Corewar in /CPE_2015_corewar/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Feb 23 16:10:17 2016 Antoine Baché
** Last update Mon May  2 17:44:57 2016 Arthur ARNAUD
*/

#include <stdlib.h>
#include "tools/str.h"
#include "tools/memory.h"

char	*my_strndup(const char *src, int n)
{
  char	*dest;
  int	i;

  i = 0;
  if ((dest = my_malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(const char *src)
{
  char	*dest;
  int	i;
  int	n;

  i = 0;
  n = my_strlen(src);
  if ((dest = my_malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
