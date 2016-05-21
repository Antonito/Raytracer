/*
** pixelarray.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu May 19 07:27:37 2016 Antoine Baché
** Last update Thu May 19 11:32:19 2016 Antoine Baché
*/

#include <lapin.h>

void		cpy_pixelarray(t_bunny_pixelarray *dest,
			       t_bunny_pixelarray *src, int w, int h)
{
  t_color	*new;
  t_color	*old;
  int		i;
  int		j;
  int		cur;

  new = dest->pixels;
  old = src->pixels;
  i = 0;
  while (i < h)
    {
      j = 0;
      while (j < w)
	{
	  cur = j + i * w;
	  new[cur].full = old[cur].full;
	  ++j;
	}
      ++i;
    }
}
