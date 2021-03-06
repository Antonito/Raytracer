/*
** memory.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:40:54 2016 Ludovic Petrenko
** Last update Sun May 22 19:20:25 2016 Antoine Baché
*/

#include <lapin.h>
#include "tools/str.h"
#include "tools/memory.h"

void		*my_malloc(size_t size)
{
  void		*ptr;

  if (!(ptr = bunny_malloc(size)))
    my_puterr("Malloc Failed !\n");
  return (ptr);
}

int		my_free(void *ptr)
{
  bunny_free(ptr);
  return (0);
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
  total_size /= sizeof(*ptr);
  while (i < total_size)
    {
      ptr[i] = 0;
      ++i;
    }
  return (ptr);
}
