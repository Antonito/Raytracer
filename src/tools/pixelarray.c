/*
** pixelarray.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu May 19 07:27:37 2016 Antoine Baché
** Last update Thu May 19 07:30:27 2016 Antoine Baché
*/

#include <lapin.h>

void		cpy_pixelarray(t_bunny_pixelarray *dest,
			       t_bunny_pixelarray *src, size_t size)
{
  t_color	*new;
  t_color	*old;
  size_t	i;

  new = dest->pixels;
  old = src->pixels;
  i = 0;
  while (i < size)
    {
      new[i].full = old[i].full;
      ++i;
    }
}
