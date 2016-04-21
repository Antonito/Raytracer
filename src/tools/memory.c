/*
** memory.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:40:54 2016 Ludovic Petrenko
** Last update Thu Apr 21 16:58:06 2016 Ludovic Petrenko
*/

#include "tools/memory.h"

void	*my_malloc(size_t size)
{
  void	*ptr;

  if (!(ptr = bunny_malloc(size)))
    my_puterr("Malloc Failed !\n");
  return (ptr);
}

void	my_free(void *ptr)
{
  bunny_free(ptr);
}

void		*my_calloc(size_t nmemb, size_t size)
{
  unsigned char	*ptr;
  size_t	i;
  size_t	total_size;

  total_size = nmemb * size;
  if (!(ptr = bunny_malloc(total_size)))
    {
      my_puterr("Calloc Failed !\n");
      return (NULL);
    }
  i = 0;
  while (i < total_size)
    {
      ptr[i] = 0;
      ++i;
    }
  return (ptr);
}
