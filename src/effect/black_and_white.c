/*
** black_and_white.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 12:43:53 2016 Antoine Baché
** Last update Wed May 18 23:37:12 2016 Antoine Baché
*/

#include "raytracer.h"

void		black_and_white_effect(t_color *pix, int height, int width,
				       t_config *conf)
{
  int		i;
  int		j;
  int		grey;
  int		cur;

  i = 0;
  (void)conf;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  cur = i * width + j;
	  grey = ((double)pix[cur].argb[0] * 0.3 +
		  (double)pix[cur].argb[1] * 0.59 +
		  (double)pix[cur].argb[2] * 0.11);
	  pix[cur].argb[0] = grey;
	  pix[cur].argb[1] = grey;
	  pix[cur].argb[2] = grey;
	  ++j;
	}
      ++i;
    }
}
