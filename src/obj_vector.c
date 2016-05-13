/*
** obj_vector.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu May 12 05:56:40 2016 Ludovic Petrenko
** Last update Thu May 12 08:17:46 2016 Ludovic Petrenko
*/

#include "engine/obj_vector.h"
#include "tools/memory.h"

t_vector	*new_vector(size_t elem_size)
{
  t_vector	*new;

  if (!(new = my_malloc(sizeof(t_vector))) ||
      !(new->begin = my_malloc(10 * elem_size)))
    return (NULL);
  new->nb_elem = 0;
  new->max_capacity = 10;
  new->elem_size = elem_size;
  new->push_back = vector_push_back;
  new->pop_back = vector_pop_back;
  new->remove = vector_remove;
  new->copy = copy_vector;
  new->delete = delete_vector;
  return (new);
}

t_vector	*copy_vector(t_vector *v)
{
  t_vector	*copy;
  size_t	i;
  size_t	size;
  char		*src;
  char		*dest;

  if (!(copy = my_malloc(sizeof(t_vector))))
    return (NULL);
  *copy = *v;
  if (!(copy->begin = my_malloc(v->max_capacity * v->elem_size)))
    return (NULL);
  i = 0;
  size = v->nb_elem * v->elem_size;
  src = v->begin;
  dest = copy->begin;
  while (i < size)
    {
      dest[i] = src[i];
      ++i;
    }
  return (copy);
}

void	delete_vector(t_vector **v)
{
  my_free((*v)->begin);
  my_free(*v);
  *v = NULL;
}
