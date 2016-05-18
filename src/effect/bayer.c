/*
** bayer.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:30:09 2016 Antoine Baché
** Last update Wed May 18 14:37:12 2016 Antoine Baché
*/

#include <lapin.h>

#pragma message("Not implemented")
void		bayer_effect(t_color *pix, int height, int width)
{
  int		i;
  int		j;
  int		cur;

  i = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  cur = i * width + j;
	  ++j;
	}
      ++i;
    }
}
