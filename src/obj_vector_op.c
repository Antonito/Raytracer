/*
** obj_vector_op.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu May 12 06:35:31 2016 Ludovic Petrenko
** Last update Sun May 22 20:09:09 2016 Antoine Baché
*/

#include "engine/obj_vector.h"
#include "tools/memory.h"

int		vector_push_back(t_vector *v, void *elem)
{
  char		*src;
  char		*dest;
  size_t	i;

  if (!(i = 0) && v->nb_elem < v->max_capacity - 1)
    {
      src = elem;
      dest = v->begin + v->nb_elem * v->elem_size;
      while (i++ < v->elem_size)
	dest[i - 1] = src[i - 1];
    }
  else
    {
      src = v->begin;
      if (!(dest = v->begin = my_malloc(v->max_capacity * 10 * v->elem_size)))
	return (1);
      while (i++ < v->max_capacity * v->elem_size)
	dest[i - 1] = src[i - 1];
      v->max_capacity *= 10 + (i = 0);
      src = elem;
      while (i++ < v->elem_size)
	dest[i - 1] = src[i - 1];
    }
  ++v->nb_elem;
  return (0);
}

void		vector_pop_back(t_vector *v)
{
  if (v->nb_elem)
    --v->nb_elem;
}

void		vector_remove(t_vector *v, unsigned int elem)
{
  unsigned int	i;
  unsigned int	j;
  char		*src;
  char		*dest;

  if (elem >= v->nb_elem)
    return ;
  i = (elem + 1) * v->elem_size;
  j = 0;
  dest = v->begin + elem * v->elem_size;
  src = dest + v->elem_size;
  while (i < v->nb_elem * v->elem_size)
    {
      dest[j] = src[j];
      ++j;
      ++i;
    }
}
