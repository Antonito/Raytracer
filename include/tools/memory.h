/*
** memory.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 22:54:52 2016 Ludovic Petrenko
** Last update Fri Apr 15 22:56:29 2016 Ludovic Petrenko
*/

#ifndef MEMORY_H_
# define MEMORY_H_

# include <stdlib.h>

void	*my_malloc(size_t size);
void	*my_calloc(size_t nmemb, size_t size);
void	my_free(void *ptr);

#endif /* !MEMORY_H_ */
