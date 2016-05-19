/*
** bayer.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:30:09 2016 Antoine Baché
** Last update Thu May 19 02:47:35 2016 Antoine Baché
*/

#include "raytracer.h"

void		bayer_effect(t_color *pix, int height, int width, t_config *conf)
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
	  if ((i / conf->bayer.value) & 1)
	    pix[cur].argb[2] = 0;
	  else
	    pix[cur].argb[0] = 0;
	  if ((j / conf->bayer.value) & 1)
	    pix[cur].argb[1] = 0;
	  ++j;
	}
      ++i;
    }
}
