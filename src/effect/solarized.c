/*
** solarized.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 18:22:04 2016 Antoine Baché
** Last update Wed May 18 18:31:15 2016 Antoine Baché
*/

#include <lapin.h>

void		solarized_effect(t_color *pix, int height, int width)
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
	  pix[cur].argb[0] = (pix[cur].argb[0] < 152) ? 255 - pix[cur].argb[0]
	    : pix[cur].argb[0];
	  pix[cur].argb[1] = (pix[cur].argb[1] < 116) ? 255 - pix[cur].argb[1]
	    : pix[cur].argb[1];
	  pix[cur].argb[2] = (pix[cur].argb[2] < 124) ? 255 - pix[cur].argb[2]
	    : pix[cur].argb[2];
	  ++j;
	}
      ++i;
    }
}
