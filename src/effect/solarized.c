/*
** solarized.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 18:22:04 2016 Antoine Baché
** Last update Wed May 18 23:40:21 2016 Antoine Baché
*/

#include "raytracer.h"

void		solarized_effect(t_color *pix, int height, int width,
				 t_config *conf)
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
	  pix[cur].argb[0] = (pix[cur].argb[0] < conf->solarized.max_r) ?
	    255 - pix[cur].argb[0] : pix[cur].argb[0];
	  pix[cur].argb[1] = (pix[cur].argb[1] < conf->solarized.max_g) ?
	    255 - pix[cur].argb[1] : pix[cur].argb[1];
	  pix[cur].argb[2] = (pix[cur].argb[2] < conf->solarized.max_b) ?
	    255 - pix[cur].argb[2] : pix[cur].argb[2];
	  ++j;
	}
      ++i;
    }
}
