/*
** eight_bit.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 14:23:04 2016 Antoine Baché
** Last update Thu May 19 21:49:29 2016 Luka Boulagnon
*/

#include "raytracer.h"

void		pixellize(t_color *pix, int width, int height, int intensity)
{
  int		x;
  int		y;
  int		i;
  int		j;
  t_color	color;

  x = -intensity;
  while ((x += intensity) < width)
    {
      y = -intensity;
      while ((y += intensity) < height)
	{
	  color = pix[width * y + x];
	  i = -1;
	  while (++i < intensity)
	    {
	      j = -1;
	      while (++j < intensity)
		pix[width * (y + i) + x + j] = color;
	    }
	}
    }
}

void		eight_bit_effect(t_color *pix, int height, int width,
				 t_config *conf)
{
  int		i;
  int		j;
  int		value;

  i = 0;
  (void)conf;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  value = pix[i * width + j].argb[0];
	  value /= (1 << 4);
	  pix[i * width + j].argb[0] = value * (1 << 4);
	  value = pix[i * width + j].argb[1];
	  value /= (1 << 4);
	  pix[i * width + j].argb[1] = value * (1 << 4);
	  value = pix[i * width + j].argb[2];
	  value /= (1 << 4);
	  pix[i * width + j].argb[2] = value * (1 << 4);
	  ++j;
	}
      ++i;
    }
  pixellize(pix, width, height, height / 32);
}
