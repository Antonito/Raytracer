/*
** memory.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:54:52 2016 Ludovic Petrenko
** Last update Tue May 10 18:21:30 2016 Ludovic Petrenko
*/

#ifndef MEMORY_H_
# define MEMORY_H_

# include <stdlib.h>

void	*my_malloc(size_t size);
void	*my_calloc(size_t nmemb, size_t size);
int	my_free(void *ptr);
void	swap_double(double *, double *);

#endif /* !MEMORY_H_ */
