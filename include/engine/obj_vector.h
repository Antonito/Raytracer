/*
** obj_vector.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu May 12 05:57:13 2016 Ludovic Petrenko
** Last update Thu May 12 07:30:41 2016 Ludovic Petrenko
*/

#ifndef OBJ_VECTOR_H_
# define OBJ_VECTOR_H_

# include <stdlib.h>

typedef struct		s_vector
{
  int			(*push_back)(struct s_vector *, void *);
  void			(*pop_back)(struct s_vector *);
  void			(*remove)(struct s_vector *, unsigned int);
  struct s_vector	*(*copy)(struct s_vector *);
  void			(*delete)(struct s_vector **);
  unsigned int		nb_elem;
  unsigned int		max_capacity;
  size_t		elem_size;
  void			*begin;
}			t_vector;

t_vector	*new_vector(size_t elem_size);
t_vector	*copy_vector(t_vector *this);
void		delete_vector(t_vector **this);
int		vector_push_back(t_vector *this, void *elem);
void		vector_pop_back(t_vector *this);
void		vector_remove(t_vector *this, unsigned int elem);

#endif /* !OBJ_VECTOR_H_ */
